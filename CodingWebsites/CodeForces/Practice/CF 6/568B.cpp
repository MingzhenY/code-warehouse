#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define M 1000000007
#define LL long long
using namespace std;
LL S[4001][4001];
int main(void)
{
	freopen("568B.txt","r",stdin); 
	memset(S,0,sizeof(S));
	S[0][0]=1;
	for(int i=1;i<4001;++i){
		for(int j=1;j<=i;++j){
			S[i][j]=(j*S[i-1][j]%M+S[i-1][j-1])%M;
		}
	}
	int n;
	while(cin>>n){
		LL ANS=0;
		for(int k=1;k<=n;++k) ANS=(ANS+k*S[n][k])%M;
		cout<<ANS<<endl;
	}
	
return 0;
}

