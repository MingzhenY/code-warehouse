/*
187ms 6300 KB 
*/ 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define maxn 200007
using namespace std;
int Hn[maxn],Vn[maxn];
int L[maxn],R[maxn],S[maxn],K[maxn],N[maxn],P[maxn],IP;
int Last;bool Left;//Insert的辅助变量
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
void Init(){L[0]=R[0]=S[0]=N[0]=P[0]=IP=0;}
void RawInsert(int &rt,int v){
	if(!rt){
		rt=++IP;L[rt]=R[rt]=0;
		S[rt]=1;K[rt]=v;
		if(Left){N[rt]=Last;P[rt]=P[Last];}
		else    {P[rt]=Last;N[rt]=N[Last];}
		N[P[rt]]=rt;P[N[rt]]=rt;
		return;
	}
	Last=rt;Left=v<=K[rt];
	v<=K[rt]?RawInsert(L[rt],v):RawInsert(R[rt],v);
	++S[rt];level(rt,v<=K[rt]);
}
void Insert(int &rt,int v){
	Last=0;Left=true;
	RawInsert(rt,v);
}
void Cut(int &rt,int *cnt,int v){
	Insert(rt,v);
	int L=K[P[IP]],R=K[N[IP]];
	cnt[R-L]--;
	cnt[v-L]++;
	cnt[R-v]++;
}
int w,h,n;
int main(void)
{
	freopen("527C.txt","r",stdin); 
	while(~scanf("%d%d%d",&w,&h,&n)){
		//初始化 
		Init();
		int H=0,V=0;
		memset(Hn,0,sizeof(Hn));memset(Vn,0,sizeof(Vn));
		Hn[h]=1;Vn[w]=1;
		Insert(H,h);Insert(V,w);
		Insert(H,0);Insert(V,0);
		int MaxH=h,MaxV=w;
		for(int i=0;i<n;++i){
			//读取 
			char a;int v;
			scanf(" %c%d",&a,&v);
			//切割 
			a=='H'?Cut(H,Hn,v):Cut(V,Vn,v);
			//输出 
			while(!Hn[MaxH]) --MaxH;
			while(!Vn[MaxV]) --MaxV;
			printf("%I64d\n",(long long)MaxH*MaxV);
		}
	}	
return 0;
}

