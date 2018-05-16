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

int A[30001];
vector<int> L[30001];
int N;
int main(void)
{freopen("1203.txt","r",stdin); 
	while(cin>>N){
		memset(A,0,sizeof(A));
		For(i,30001) L[i].clear();
		For(i,N){
			int a,b;
			scanf("%d%d",&a,&b);
			L[a-1].push_back(b);
		}
		For(i,30000){
			if(A[i]>A[i+1]) A[i+1]=A[i];
			For(j,L[i].size()){
				if(A[i]+1>A[L[i][j]])A[L[i][j]]=A[i]+1;
			}
		}
		cout<<A[30000]<<endl;
	}
return 0;
}








