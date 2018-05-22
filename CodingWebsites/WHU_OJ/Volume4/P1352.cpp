#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#define LL long long
using namespace std;
struct ArcNode{
    int to,w;
    ArcNode *next;
    ArcNode(){}
};
struct Node{
    ArcNode *List;
    LL D;
    Node():List(NULL),D(-1){}
    void Clear(){
        ArcNode *temp;
        while(List){
            temp = List;
            List = List -> next;
            delete temp;
        }
        D = -1;
    }
}node[2000];
void Arc(int from,int to,int w){
    ArcNode *temp = new ArcNode;
    temp->to = to;
    temp->w = w;
    temp->next = node[from].List;
    node[from].List = temp;
}
void DArc(int from,int to,int w){
    Arc(from,to,w);
    Arc(to,from,w);
}
queue<int> Q;
int main(){
    freopen("P1352.txt","r",stdin);
    int T,n,m,s,t,u,v,w;
    scanf("%d",&T);
    while(T-- > 0){
        scanf("%d%d%d%d",&n,&m,&s,&t);
        for(int i = 0 ; i < m ; ++i){
            scanf("%d%d%d",&u,&v,&w);
            DArc(u,v + 1000,w);
            DArc(u + 1000,v,w);
        }
        Q.push(s);
        node[s].D = 0;
        while(!Q.empty()){
            int cnt = Q.front();Q.pop();
            ArcNode *temp = node[cnt].List;
            while(temp){
                LL &D = node[temp->to].D;
                if(-1 == D || node[cnt].D + temp->w < D){
                    D = node[cnt].D + temp->w;
                    Q.push(temp->to);
                }
                temp = temp->next;
            }
        }
        printf("%lld %lld\n",node[1000+t].D,node[t].D);
        for(int i = 0 ; i < n ; ++i){
            node[i].Clear();
            node[i + 1000].Clear();
        }
    }
    return 0;
}


