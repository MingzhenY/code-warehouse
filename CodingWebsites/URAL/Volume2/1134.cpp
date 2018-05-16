#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

int N,M;
int A[1001];
int Card[1001];
int main(void)
{freopen("1134.txt","r",stdin); 
	while(cin>>N>>M){
		memset(A,0,sizeof(A));
		memset(Card,0,sizeof(Card));
		int T=1;//表示正常 
		if(M>N) T=0;
		For(i,M){
			int a; 
			cin>>a;
			if(a>N)T=0;
			A[a]++;
		}
		For(i,N+1){
			if(A[i]>2) {
				T=0;break;
			}
			if(A[i]>0){
				if(i&&!Card[i]) Card[i]=1,A[i]--; 
			}
			if(A[i]>0){
				if(i+1<=N&&!Card[i+1]) Card[i+1]=1,A[i]--;
			}
			if(A[i]>0) {
				T=0;break;
			}
		}
		
		
		if(T) cout<<"YES"<<endl;
		else cout<<"NO"<<endl; 
	}
return 0;
}








