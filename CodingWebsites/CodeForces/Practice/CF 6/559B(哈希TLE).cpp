#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define K 137
#define M 1000000021
#define maxn 200007
#define LL long long
using namespace std;
LL Hash1[maxn],Hash2[maxn];
char str1[maxn],str2[maxn];
LL PowerK[maxn];
int InitHash(int n){
	PowerK[0]=1;for(int i=1;i<maxn;++i) PowerK[i]=(PowerK[i-1]*K)%M;
	for(int i=0;i<n;++i) str1[i]-='a'-1,str2[i]-='a'-1;
	Hash1[0]=0;Hash2[0]=0;//Hash[i]=[0,i)
	for(int i=1;i<=n;++i){
		Hash1[i]=(Hash1[i-1]*K+str1[i-1])%M;
		Hash2[i]=(Hash2[i-1]*K+str2[i-1])%M;
	}
}
bool F(int L1,int R1,int L2,int R2){//[L,R)
	LL H1=(Hash1[R1]+M-(Hash1[L1]*PowerK[R1-L1])%M)%M;
	LL H2=(Hash2[R2]+M-(Hash2[L2]*PowerK[R2-L2])%M)%M;
	if(H1==H2) return true;
	if((R1-L1)&1) return false;
	int Mid1=(L1+R1)>>1,Mid2=(L2+R2)>>1;
	return F(L1,Mid1,L2,Mid2)&&F(Mid1,R1,Mid2,R2) || F(L1,Mid1,Mid2,R2)&&F(Mid1,R1,L2,Mid2);
}
int main(void)
{
	freopen("559B.txt","r",stdin); 
	while(~scanf("%s%s",str1,str2)){
		int n1=strlen(str1),n2=strlen(str2);
		InitHash(n1);
		printf("%s\n",F(0,n1,0,n2)?"YES":"NO");
	}
return 0;
}

