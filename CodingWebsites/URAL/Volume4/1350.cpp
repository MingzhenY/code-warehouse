#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map> 
#include <vector>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

int N,M,K;
int vis[100],nv;
vector <int> V[100];
int main(void)
{freopen("1350.txt","r",stdin); 
	while(cin>>N){
		memset(vis,0,sizeof(vis));
		map<string,int> MP;
		string a;
		for(int i=0;i<N;i++) cin>>a,MP[a]=i;
		cin>>K;int n;
		cin>>n;For(i,n) cin>>a,vis[MP[a]]=1,N--;
		For(i,K){
			cin>>n;int Left=n;
			For(j,n){
				cin>>a;
				if(!vis[MP[a]]) V[i].push_back(MP[a]);
			}
		}
		//OUT1(N);
		cin>>M;
		For(i,K){
			int k=V[i].size();
			//OUT3(i,k,M);
			if(k<1||!M) {
				printf("YES\n");continue;
			}
			if(k+M >N){
				printf("NO\n");
			}
			else{
				printf("MAYBE\n");
			}
		}
	}
return 0;
}








