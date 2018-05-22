#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAXN = 500;
const int MAXM = 250000;
const int INF = 0x3f3f3f3f;

struct Edge
{
    int v, f;
    int next;
}edge[MAXM];

int n, m;
int cnt;

int first[MAXN], level[MAXN];
int q[MAXN];

void init()
{
    cnt = 0;
    memset(first, -1, sizeof(first));
}

void read_graph(int u, int v, int f)
{
    edge[cnt].v = v, edge[cnt].f = f;
    edge[cnt].next = first[u], first[u] = cnt++;
    edge[cnt].v = u, edge[cnt].f = 0;  //增加一条反向弧，容量为0
    edge[cnt].next = first[v], first[v] = cnt++;
}

int bfs(int s, int t) //构建层次网络
{
    memset(level, 0, sizeof(level));
    level[s] = 1;
    int front = 0, rear = 1;
    q[front] = s;
    while(front < rear)
    {
        int x = q[front++];
        if(x == t) return 1;
        for(int e = first[x]; e != -1; e = edge[e].next)
        {
            int v = edge[e].v, f = edge[e].f;
            if(!level[v] && f)
            {
                level[v] = level[x] + 1;
                q[rear++] = v;
            }
        }
    }
    return 0;
}
int dfs(int u, int maxf, int t)
{
    if(u == t) return maxf;
    int ret = 0;
    for(int e = first[u]; e != -1; e = edge[e].next)
    {
        int v = edge[e].v, f = edge[e].f;
        if(level[u] + 1 == level[v] && f)
        {
            int Min = min(maxf-ret, f);
            f = dfs(v, Min, t);
            edge[e].f -= f;
            edge[e^1].f += f;
            ret += f;
            if(ret == maxf) return ret;
        }
    }
    return ret;
}
int Dinic(int s, int t) //Dinic
{
    int ans = 0;
    while(bfs(s, t)) ans += dfs(s, INF, t);
    return ans;
}

int main(){
    freopen("P1223.txt","r",stdin);
    int N,F,D;
    while(~scanf("%d%d%d",&N,&F,&D)){
        init();
        for(int i = 1 ; i <= N ; ++i) read_graph(100+i,200+i,1);
        for(int i = 1 ; i <= F ; ++i) read_graph(0,i,1);
        for(int i = 1 ; i <= D ; ++i) read_graph(300+i,401,1);
        for(int i = 1 ; i <= N ; ++i){
            int Fi,Di,t;
            scanf("%d%d",&Fi,&Di);
            for(int j = 1 ; j <= Fi ; ++j) {
                scanf("%d",&t);
                read_graph(t,100+i,1);
            }
            for(int j = 1 ; j <= Di ; ++j){
                scanf("%d",&t);
                read_graph(200+i,300+t,1);
            }
        }
        int ANS = Dinic(0,401);
        printf("%d\n",ANS);
        break;
    }
    return 0;
}


