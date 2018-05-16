#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define maxn 200007
using namespace std;
int Hn[maxn],Vn[maxn];
int L[maxn],R[maxn],S[maxn],K[maxn],IP;
void zig(int &x){int t=R[x];R[x]=L[t];L[t]=x;S[t]=S[x];S[x]=S[L[x]]+S[R[x]]+1;x=t;} 
void zag(int &x){int t=L[x];L[x]=R[t];R[t]=x;S[t]=S[x];S[x]=S[L[x]]+S[R[x]]+1;x=t;}
void level(int &x,bool flag){
	if(flag){
		if(S[L[L[x]]]>S[R[x]]) zag(x);
		else if(S[R[L[x]]]>S[R[x]]) zig(L[x]),zag(x);
		else return;
	}
	else{
		if(S[R[R[x]]]>S[L[x]]) zig(x);
		else if(S[L[R[x]]]>S[L[x]]) zag(R[x]),zig(x);
		else return;
	}
	level(L[x],true);level(R[x],false);
	level(x,true);level(x,false);
}
void Insert(int &rt,int v){
	if(!rt) {rt=++IP;L[rt]=R[rt]=0;S[rt]=1;K[rt]=v;return;}
	v<=K[rt]?Insert(L[rt],v):Insert(R[rt],v);
	++S[rt];level(rt,v<=K[rt]);
}
int Pred(int &rt,int X){
	if(!rt) return 0;
	if(K[rt]>=X) return Pred(L[rt],X);
	else{
		int ID=Pred(R[rt],X);
		return ID?ID:rt;
	}
}
int Succ(int &rt,int X){
	if(!rt) return 0;
	if(K[rt]<=X) return Succ(R[rt],X);
	else{
		int ID=Succ(L[rt],X);
		return ID?ID:rt;
	}
}
void Cut(int &rt,int *cnt,int v){
	Insert(rt,v);
	int L=K[Pred(rt,v)],R=K[Succ(rt,v)];
	cnt[R-L]--;
	cnt[v-L]++;
	cnt[R-v]++;
}
int w,h,n;
int main(void)
{
	freopen("527C.txt","r",stdin); 
	while(cin>>w>>h>>n){
		//��ʼ�� 
		L[0]=R[0]=S[0]=IP=0;
		int H=0,V=0;
		memset(Hn,0,sizeof(Hn));memset(Vn,0,sizeof(Vn));
		Hn[h]=1;Vn[w]=1;
		Insert(H,h);Insert(V,w);
		Insert(H,0);Insert(V,0);
		int MaxH=h,MaxV=w;
		for(int i=0;i<n;++i){
			//��ȡ 
			char a;int v;
			scanf(" %c%d",&a,&v);
			//�и� 
			a=='H'?Cut(H,Hn,v):Cut(V,Vn,v);
			//��� 
			while(!Hn[MaxH]) --MaxH;
			while(!Vn[MaxV]) --MaxV;
			printf("%I64d\n",(long long)MaxH*MaxV);
		}
	}	
return 0;
}
