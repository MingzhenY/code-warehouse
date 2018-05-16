#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define maxn 200007
using namespace std;
char str[2][maxn];
LL PowerK[maxn];
void Switch(int L1,int L2,int n,int type){
	int T=0;
	for(int i=0;i<n;++i){
		if(str[type][L1+i]<str[type][L2+i]) return;
		if(str[type][L1+i]>str[type][L2+i]) {T=1;break;}
	}
	if(T){
		for(int i=0;i<n;++i) swap(str[type][L1+i],str[type][L2+i]);
	}
}
void Transform(int L,int R){//[L,R)
	int n=(R-L);
	if(n&1) return;else n>>=1;
	Transform(L,L+n);Transform(L+n,R);
	Switch(L,L+n,n,0);
	Switch(L,L+n,n,1);
} 
int main(void)
{
	freopen("559B.txt","r",stdin); 
	while(~scanf("%s%s",str[0],str[1])){
		int n=strlen(str[0]);
		Transform(0,n);
		printf("%s\n",strcmp(str[0],str[1])?"NO":"YES");
	}
return 0;
}

