#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
//并查集
int p[100];
int Find(int i){
	return i==p[i]?i:p[i]=Find(p[i]);
} 
void Union(int i,int j){
	p[Find(i)]=Find(j);
}
bool Is(int i,int j){
	return Find(i)==Find(j);
}
int N,ALL;
vector<int>Stop[10000];
struct ArcNode{
	int to;
	ArcNode*next;
};
struct Route{
	bool visit;
	int N;
	ArcNode *Head,*Tail;
	vector<int>route;
	vector<int>Cross;
	vector<int>CrossPoint;
}R[100];
void Arc(int from,int to){
	ArcNode*temp=new ArcNode;
	temp->to=to;
	if(R[from].Tail){
		R[from].Tail->next=temp;
		R[from].Tail=temp;
	}
	else{
		temp->next=NULL;
		R[from].Head=temp;
		R[from].Tail=temp;
	}
	R[from].N++;
}
void show(int i,int start){
	ArcNode *temp=R[i].Head;
	For(j,R[i].N) if(temp->to!=start) temp=temp->next; else break;
	R[i].visit=1;
	For(j,R[i].N){
		For(k,R[i].CrossPoint.size()){
			if(temp->to==R[i].CrossPoint[k]){
				if(!R[R[i].Cross[k]].visit){
					show(R[i].Cross[k],R[i].CrossPoint[k]);
				}
			}
		}
		printf("%d ",temp->to+1);
		temp=temp->next;
	}
}
int main(void)
{freopen("1137.txt","r",stdin); 
	while(cin>>N){
		//输入 
		For(i,N) R[i].Head=NULL,R[i].Tail=NULL,R[i].N=0,R[i].visit=0;
		int ANS=0;
		For(i,N){
			int M,from,to;
			scanf("%d%d",&M,&from);ANS+=M;
			For(j,M){
				scanf("%d",&to);
				Arc(i,to-1);
				int T=1;
				For(k,Stop[to-1].size()){
					if(Stop[to-1][k]==i) {
						T=0;break;
					}
				}
				if(T) Stop[to-1].push_back(i);
			}
		}
		For(i,N){
			R[i].Tail->next=R[i].Head;
			p[i]=i;
		}
		
		
		//建图
		ALL=N;
		For(i,10000){
			for(int j=0;j<Stop[i].size();j++){
				for(int k=j+1;k<Stop[i].size();k++){
					//Stop[i][j],Stop[i][k];
					if(!Is(Stop[i][j],Stop[i][k])) ALL--;
					//OUT3(Stop[i][j],Stop[i][k],Is(Stop[i][j],Stop[i][k]));
					Union(Stop[i][j],Stop[i][k]);
					R[Stop[i][j]].Cross.push_back(Stop[i][k]);
					R[Stop[i][j]].CrossPoint.push_back(i);
					R[Stop[i][k]].Cross.push_back(Stop[i][j]);
					R[Stop[i][k]].CrossPoint.push_back(i);
				}
			}
		}
		//计算 
		if(ALL==1){
			printf("%d ",ANS);
			show(0,R[0].Head->to);
			printf("%d\n",R[0].Head->to+1);
		}
		else printf("0\n");
		
	}
return 0;
}








