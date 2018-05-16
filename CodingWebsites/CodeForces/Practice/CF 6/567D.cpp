#include <iostream>
#include <cstdio>
#include <cmath>
#define maxn 200007 
using namespace std;
int n,k,a,m,cut[maxn];
int L[maxn],R[maxn],S[maxn],V[maxn],sum[maxn],IP,N,RT;
int ShipNumber(int length){return (length+1)/(a+1);}
void Init(){L[0]=R[0]=S[0]=V[0]=IP=N=RT=0;}
void PushUp(int &rt){
	S[rt]=S[L[rt]]+S[R[rt]]+1;
	sum[rt]=sum[L[rt]]+sum[R[rt]]+V[rt];
}
void zig(int &rt){
	int t=R[rt];R[rt]=L[t];L[t]=rt;
	S[t]=S[rt];S[rt]=S[L[rt]]+S[R[rt]]+1;
	sum[t]=sum[rt];sum[rt]=sum[L[rt]]+sum[R[rt]]+V[rt]; 
	rt=t;
}
void zag(int &rt){
	int t=L[rt];L[rt]=R[t];R[t]=rt;
	S[t]=S[rt];S[rt]=S[L[rt]]+S[R[rt]]+1;
	sum[t]=sum[rt];sum[rt]=sum[L[rt]]+sum[R[rt]]+V[rt]; 
	rt=t;
}
void maintain(int &rt){
	if(S[L[L[rt]]]>S[R[rt]]){zag(rt);maintain(R[rt]);maintain(rt);return;}
	if(S[R[R[rt]]]>S[L[rt]]){zig(rt);maintain(L[rt]);maintain(rt);return;}
	if(S[R[L[rt]]]>S[R[rt]]){zig(L[rt]);zag(rt);maintain(L[rt]);maintain(R[rt]);return;}
	if(S[L[R[rt]]]>S[L[rt]]){zag(R[rt]);zig(rt);maintain(L[rt]);maintain(R[rt]);return;}
}
void InsertLeft(int &rt,int C){
	if(!rt){
		rt=++IP;
		sum[rt]=V[rt]=C;
		L[rt]=R[rt]=0;
		S[rt]=1;
		return;
	}
	InsertLeft(L[rt],C);	
	sum[rt]+=C;
	++S[rt];
	maintain(rt);
}
void Cut(int &rt,int C){
	if(C <=0) return;
	if(sum[L[rt]]+S[L[rt]]>=C) {Cut(L[rt],C);PushUp(rt);maintain(rt);return;}
	if(sum[L[rt]]+V[rt]+S[L[rt]]<C) {Cut(R[rt],C-sum[L[rt]]-V[rt]-S[L[rt]]-1);PushUp(rt);maintain(rt);return;}
	C-=S[L[rt]]+sum[L[rt]];
	N+=ShipNumber(V[rt]-C)+ShipNumber(C-1)-ShipNumber(V[rt]); 
	InsertLeft(R[rt],V[rt]-C);V[rt]=C-1;
	PushUp(rt);
	maintain(rt);
}
void show(int rt,bool end){
	if(S[L[rt]]) show(L[rt],false);
	printf("%d ",V[rt]);
	if(S[R[rt]]) show(R[rt],false);
	if(end) printf("\n");
}
void Show(int rt){show(rt,true);}
int main(void)
{
	freopen("567D.txt","r",stdin); 
	while(~scanf("%d%d%d%d",&n,&k,&a,&m)){
		Init();InsertLeft(RT,n);
		int temp,ANS=-1;N=ShipNumber(n);
		for(int i=0;i<m;++i) scanf("%d",&cut[i]);
		for(int i=0;i<m;++i){
			Cut(RT,cut[i]);
			if(N < k) {
				ANS=i+1;break;
			}
		}
		printf("%d\n",ANS);
	}
return 0;
}

