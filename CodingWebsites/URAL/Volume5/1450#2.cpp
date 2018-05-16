#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define  inf  0x1fffffff
#define maxn 510
using namespace std;
//Õº 
struct ArcNode{
	int from,to,value;
	ArcNode *In,*Out;
}; 
struct Node{
	ArcNode *In,*Out;
	int d;//»Î∂»
	int ord;//Õÿ∆À≈≈–Ú÷Æ∫ÛµƒÀ≥–Ú 
}node[maxn];
void Arc(int from,int to,int value){
	ArcNode *temp=new ArcNode;
	temp->from=from;temp->to=to;temp->value=value;
	temp->In=node[to].In;node[to].In=temp;++node[to].d;
	temp->Out=node[from].Out;node[from].Out=temp;
}
int n,m,Ord;
int dist[maxn];
int ord[maxn];//–¬À≥–Ú --> æ…À≥–Ú 

int main(){
    freopen("1450.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)){
    	//≥ı ºªØ 
        for(int i=1;i<=n;++i) node[i].In=NULL,node[i].Out=NULL,node[i].d=0,node[i].ord=0;
        //Ω®±ﬂ 
        for(int i=0;i<m;++i){
        	int a,b,c;scanf("%d%d%d",&a,&b,&c);
        	Arc(a,b,c);
        }
        //Õÿ∆À≈≈–Ú
		queue<int> Q ;int Ord=0;
		for(int i=1;i<=n;++i) if(!node[i].d) Q.push(i);
		while(!Q.empty()){
			int cnt=Q.front();Q.pop();
			node[cnt].ord=++Ord;
			ord[Ord]=cnt;
			ArcNode *temp=node[cnt].Out;
			while(temp){
				--node[temp->to].d;
				if(!node[temp->to].d) Q.push(temp->to);
				temp=temp->Out;
			}
		}
		//º∆À„¥∞∏ 
        int S,T;scanf("%d%d",&S,&T);
        memset(dist,-1,sizeof(dist));
        dist[S]=0;
        for(int i=node[S].ord+1;i<=n;++i){
        	ArcNode *temp=node[ord[i]].In;
        	dist[ord[i]]=0;
        	while(temp){
				if(dist[temp->from]>=0&&dist[temp->from]+temp->value>dist[ord[i]]) {
					dist[ord[i]]=dist[temp->from]+temp->value;
				}
        		temp=temp->In;
        	}
        	if(ord[i]==T) break;
        }
        // ‰≥ˆ 
        if(dist[T]>0) printf("%d\n",dist[T]);
        else printf("No solution\n");
    }
    return 0;   
}
