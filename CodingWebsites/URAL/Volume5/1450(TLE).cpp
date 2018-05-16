#include <iostream>
#include <cstdio>
#include <queue>
#define maxn 510
using namespace std;

int getInt(){
	char a=getchar();
	while(a<'0'||a>'9') a=getchar();
	int ANS=0;
	while(a>='0'&&a<='9'){
		ANS=10*ANS+a-48;
		a=getchar();
	}
	return ANS;
}

struct ArcNode{
    int to,w;
    ArcNode *next;
};
struct Node{
    ArcNode *List;
    int Dis;   
}node[maxn];
void Arc(int from,int to,int w){
    ArcNode *temp=new ArcNode;
    temp->to=to;temp->w=w;
    temp->next=node[from].List;
    node[from].List=temp;   
}
bool Inq[maxn];
queue <int> Q;
int n,m;
void BFS(int t){
    ArcNode *temp=node[t].List;
    while(temp){
        if(!~node[temp->to].Dis||node[temp->to].Dis<node[t].Dis+temp->w){
            node[temp->to].Dis= node[t].Dis+temp->w;
            if(!Inq[temp->to]){
                Q.push(temp->to);Inq[temp->to]=1;
            }  
        }
        temp=temp->next;   
    }
}
int main(){
    freopen("1450.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;++i) node[i].List=NULL,node[i].Dis=-1,Inq[i]=0;
        for(int i=0;i<m;++i){
            int a,b,c;
            a=getInt();b=getInt();c=getInt();
            Arc(a,b,c);
        }  
        int S,T;scanf("%d%d",&S,&T);
        while(!Q.empty()) Q.pop();
        Q.push(S);node[S].Dis=0;Inq[S]=1;
        while(!Q.empty()){
            int cnt=Q.front();Q.pop();Inq[cnt]=0;
            BFS(cnt);  
        }
        
        if(~node[T].Dis){
            printf("%d\n",node[T].Dis);
        }
        else printf("No solution\n");
    }
    return 0;   
}
