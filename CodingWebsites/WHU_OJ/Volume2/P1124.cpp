#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAXN = 1200;
const int MAXM = 6400;
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
    //printf("(%d,%d,%d)\n",u,v,f);
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
    //printf("Flow:%d\n",ans);
    return ans;
}
int A[1001],B[1001],D[101],R[101],T;
int main(){
    freopen("P1124.txt","r",stdin);
    int N,M,a,b;
    while(~scanf("%d%d",&N,&M)){
        T = 0;
        for(int i = 1 ; i <= N ; ++i)
            scanf("%d",&D[i]);
        for(int i = 1 ; i <= M ; ++i){
            scanf("%d%d",&a,&b);
            if(N == a || N == b) {
                D[N] += 2;
            }
            else{
                ++T;
                A[T] = a;
                B[T] = b;
            }
        }
        bool YES = true;
        for(int i = 1 ; i < N ; ++i){
            R[i] = D[N] - 1 - D[i];
            if(R[i] <= 0) {
                YES = false;
                break;
            }
        }
        if(YES){//flow
            init();
            for(int i = 1 ; i <= T ; ++i){
                read_graph(0,i,2);
                read_graph(i,1000+A[i],2);
                read_graph(i,1000+B[i],2);
            }
            for(int i = 1 ; i < N ; ++i){
                read_graph(1000+i,1101,R[i]);
            }
            YES = Dinic(0,1101) == 2 * T;
        }
        printf("%s\n",YES?"YES":"NO");
    }
    return 0;
}


