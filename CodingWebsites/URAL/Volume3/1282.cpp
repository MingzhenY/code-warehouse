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

struct Node{
	int result;
	int depth;
	vector<int> D;
}node[1000];
int N;
int dfs(int k){
	if(node[k].result<5) return node[k].result;
	int ANS=node[k].result;
	For(i,node[k].D.size()){
		int D=dfs(node[k].D[i]);
		if(D <ANS) ANS=D;
	}
	node[k].result=-ANS;
	return node[k].result;
}
int main(void)
{freopen("1282.txt","r",stdin); 
	while(cin>>N){
		For(i,N) node[i].D.clear(),node[i].result=7;
		node[0].depth=0;
		for(int i=2;i<=N;i++){
			char op;
			cin>>op;
			if(op=='N'){
				int pa;
				scanf("%d",&pa);
				node[pa-1].D.push_back(i-1);
				node[i-1].depth=node[pa-1].depth+1;
			}
			else{
				int pa,result;
				scanf("%d%d",&pa,&result);
				//OUT2(pa,result);
				node[pa-1].D.push_back(i-1);
				node[i-1].result=result;
				node[i-1].depth=node[pa-1].depth+1;
			}
		}
		
		/*
		For(i,N){
			printf("½Úµã%d:",i+1);
			For(k,node[i].D.size()){
				printf("->%d(%d)",node[i].D[k]+1,node[node[i].D[k]].result);
			}
			cout<<endl;
		}*/
		For(i,N){
			if(node[i].D.size()<1){
				if(node[i].depth&1) node[i].result=-node[i].result;
			}
		}
		int ANS=dfs(0);
		if(ANS==1) {
			printf("+1\n");
		}
		else if(ANS==0){
			printf("0\n");
		}
		else if(ANS==-1){
			printf("-1\n");
		}
	}
return 0;
}








