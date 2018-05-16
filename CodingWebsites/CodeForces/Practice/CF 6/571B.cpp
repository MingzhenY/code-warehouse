#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define LL long long
using namespace std;
int n,k;
int A[300007]; 
int main(void)
{
	freopen("571B.txt","r",stdin); 
	while(cin>>n>>k){
		for(int i=1;i<=n;++i) cin>>A[i];
		LL ANS=0;
		sort(A+1,A+n+1);
		for(int i=2;i<=n;++i) ANS+=abs(A[i]-A[i-1]);
		int T=0;
		for(int t=1;t<=k;++t){
			T+=1+(n-t)/k;
			cout<<"T="<<T<<endl;
			if(T+1<n) ANS-=abs(A[T+1]-A[T]);
		}
		cout<<ANS<<endl;
	}
return 0;
}

