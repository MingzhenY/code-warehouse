#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
struct ArcNode{
    int to;
    ArcNode *next;
};
ArcNode *List[200000];
int Dist[200000];
bool vis[200000];

void Arc(int from,int to){
    ArcNode *temp=new ArcNode;
    temp->to=to;
    temp->next=List[from];
    List[from]=temp;
}
void DArc(int from,int to){
    Arc(from,to);
    Arc(to,from);
}

queue<int> Q;
int main(){
    freopen("P1006.txt","r",stdin);
    int n,m,k,a,b;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<m;++i){
            scanf("%d%d",&a,&b);
            DArc(a,b);
        }
        scanf("%d",&k);
        for(int i=0;i<k;++i){
            scanf("%d%d",&a,&b);
            if(a==b){
                printf("0\n");
                continue;
            }
            memset(vis,0,sizeof(vis));
            memset(Dist,0,sizeof(Dist));
            Q.push(a);
            Dist[a]=0;
            vis[a]=1;
            while(!Q.empty()){
                int cnt=Q.front();Q.pop();
                for(ArcNode *p=List[cnt];p;p=p->next){
                    if(!vis[p->to]){
                        Q.push(p->to);
                        Dist[p->to]=Dist[cnt]+1;
                        vis[p->to]=1;
                    }
                }
            }
            printf("%d\n",Dist[b]-1);
        }
        for(int i=0;i<n;++i){
            ArcNode *temp=List[i];
            while(temp){
                ArcNode *del = temp;
                temp=temp->next;
                delete del;
            }
            Dist[i]=0;
        }
    }
    
    
    return 0;
}


