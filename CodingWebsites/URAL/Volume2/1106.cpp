#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

int N;int ALL;
vector<int> V[100];
int team[100];
void dfs(int i,int t);
int main(void)
{freopen("1106.txt","r",stdin); 
	while(cin>>N){
		//Ô¤´¦Àí 
		For(i,N) V[i].clear();
		For(i,N){
			int a;
			do{
				scanf("%d",&a);
				if(a) V[i].push_back(a-1);
			}while(a);
			
			//OUT1(V[i].size());
		}
		/*
		For(i,N){
			printf("%d:",i+1);
			For(j,V[i].size()){
				printf("->%d",V[i][j]+1);
			}
			cout<<endl;
		}
		*/
		//¼ÆËã 
		memset(team,-1,sizeof(team));
		ALL=0;
		For(i,N) dfs(i,0);
		cout<<ALL<<endl;
		For(i,N){
			if(team[i]) {
				printf("%d",i+1);
				if(i==N-1) printf("\n");
				else printf(" ");	
			}
		}
	}
	
	
	
	
return 0;
}
void dfs(int i,int t){
	if(~team[i]) return;
	team[i]=t;if(t) ALL++;
	For(k,V[i].size()){
		dfs(V[i][k],1-t);
	}
}







