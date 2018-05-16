#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define M 1000000007LL
#define maxn 5010
using namespace std;
int n,a,b,k;
long long C[maxn];
long long S[maxn];
void Caculate_S(){
	S[0]=0LL;
	for(int i=1;i<=n;++i) S[i]=(S[i-1]+C[i])%M;
}
long long Query(int L,int R){
	if(L > R) return 0LL;
	long long ANS=S[R]-S[L-1];
	return ANS <0LL?ANS+M:ANS;
}
int main(void)
{
	freopen("479E.txt","r",stdin); 
	while(cin>>n>>a>>b>>k){
		memset(C,0,sizeof(C));
		C[a]=1;Caculate_S();
		for(int i=0;i<k;++i){
			for(int j=1;j<b;++j)	C[j]=Query(1,j-1)+Query(j+1,(b+j-1)>>1);
			for(int j=b+1;j<=n;++j)	C[j]=Query(j+1,n)+Query((b+j+2)>>1,j-1);
			Caculate_S();
		}
		cout<<S[n]<<endl;
	}
return 0;
}














