#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 200007
#define LL long long
using namespace std;
struct V{
	int I,C;
	V(){}
	V(int I,int C):I(I),C(C){}
	bool operator<(const V &B)const{return C < B.C;}
}T1[maxn],T2[maxn];
int n,m,s,k;
int A[maxn],B[maxn];
int AI[maxn],BI[maxn];
LL ST1[maxn],ST2[maxn];
int T1n,T2n;
int DF;
bool F(int d){
	int L=max(0,k-T2n),R=min(T1n,k);
	if(L>R) return false;
	LL ANS=ST1[L]*A[d]+ST2[k-L]*B[d];
	DF=L;
	for(int t=L+1;t<=R;++t){
		LL D=ST1[t]*A[d]+ST2[k-t]*B[d];
		if(D < ANS) {
			ANS=D;
			DF=t;
		}
	}
	return ANS <= s;
}
int main(void)
{
	freopen("609D.txt","r",stdin); 
	while(~scanf("%d%d%d%d",&n,&m,&k,&s)){
		
		for(int i=1;i<=n;++i) scanf("%d",&A[i]);
		AI[1]=1;
		for(int i=2;i<=n;++i) 
			if(A[i]>A[i-1]){
				A[i]=A[i-1];
				AI[i]=AI[i-1];
			}
			else AI[i]=i;
		for(int i=1;i<=n;++i) scanf("%d",&B[i]);
		BI[1]=1;
		for(int i=2;i<=n;++i) 
			if(B[i]>B[i-1]){
				B[i]=B[i-1];
				BI[i]=BI[i-1];
			}
			else BI[i]=i;
		T1n=T2n=0;
		for(int i=1;i<=m;++i){
			int t,c;
			scanf("%d%d",&t,&c);
			if(t==1) T1[++T1n]=V(i,c);
			else T2[++T2n]=V(i,c);
		} 
		sort(T1+1,T1+T1n+1);
		sort(T2+1,T2+T2n+1);
		ST1[1]=T1[1].C;
		for(int i=2;i<=T1n;++i) ST1[i]=ST1[i-1]+T1[i].C;
		ST2[1]=T2[1].C;
		for(int i=2;i<=T2n;++i) ST2[i]=ST2[i-1]+T2[i].C;
		if(!F(n)){
			printf("-1\n");
			continue;
		}
		{
			int L=1,R=n,M;
			while(L^R){
				int M=(L+R)>>1;
				if(F(M)) R=M;
				else L=M+1;
			}
			F(L);
			printf("%d\n",L);
			for(int i=1;i<=DF;++i) 
				printf("%d %d\n",T1[i].I,AI[L]);
			for(int i=1;i<=k-DF;++i)
				printf("%d %d\n",T2[i].I,BI[L]);
		}
	}
return 0;
}














