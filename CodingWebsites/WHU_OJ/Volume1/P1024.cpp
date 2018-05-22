#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;
struct ArcNode{
    int to,value;
    ArcNode *next;
};
struct Node{
    ArcNode *List;
    int Dist;
}node[50001];
void Arc(int from,int to,int value){
    ArcNode *temp = new ArcNode;
    temp->to=to;
    temp->value=value;
    temp->next=node[from].List;
    node[from].List=temp;
}
void DArc(int from,int to,int value){
    Arc(from,to,value);
    Arc(to,from,value);
}
int T,N,u,v,d,Sum;


void Calculate(int start,int &dist,int &end){
    for(int i=1;i<=N;++i) node[i].Dist=-1;
    queue<int> Q;
    node[start].Dist=0;
    Q.push(start);
    while(!Q.empty()){
        int cnt=Q.front();Q.pop();
        ArcNode *temp=node[cnt].List;
        while(temp){
            if(!~node[temp->to].Dist){
                node[temp->to].Dist=node[cnt].Dist+temp->value;
                Q.push(temp->to);
            }
            temp=temp->next;
        }
    }
    end = start;
    dist = 0;
    for(int i=1 ;i<=N;++i){
        if(node[i].Dist > dist){
            dist = node[i].Dist;
            end = i;
        }
    }
}
int main(){
    freopen("P1024.txt","r",stdin);
    
    scanf("%d",&T);
    for(int C=1;C<=T;++C){
        scanf("%d",&N);
        Sum=0;
        for(int i=1;i<N;++i){
            scanf("%d%d%d",&u,&v,&d);
            DArc(u,v,d);
            Sum+=d;
        }
        int start=1,dist,end;
        Calculate(start,dist,end);
        Calculate(end,dist,start);
        printf("Case %d:\n%d\n",C,2*Sum-dist);
        if(C < T) printf("\n");
        //Free
        for(int i=1;i<=N;++i){
            while(node[i].List){
                ArcNode *temp=node[i].List;
                node[i].List=node[i].List->next;
                delete temp;
            }
        }
    }
    
    return 0;
}


