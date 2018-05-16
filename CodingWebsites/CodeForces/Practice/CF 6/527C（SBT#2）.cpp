#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define maxn 200007
using namespace std;
int L[maxn],R[maxn],Size[maxn],Key[maxn];
int Hn[maxn],Vn[maxn];
int IP;
void Init(){//初始化 
	L[0]=R[0]=Size[0]=Key[0]=IP=0;
}
void PushUp(int rt){//更新节点 
	Size[rt]=1+Size[L[rt]]+Size[R[rt]];
}
void zig(int &rt){//左旋 
	int t=R[rt];R[rt]=L[t];L[t]=rt;
	PushUp(rt);PushUp(t);rt=t;
}
void zag(int &rt){//右旋 
	int t=L[rt];L[rt]=R[t];R[t]=rt;
	PushUp(rt);PushUp(t);rt=t;
}
void maintain(int &rt){//平衡 
	if(Size[L[L[rt]]]>Size[R[rt]]) {zag(rt);maintain(R[rt]);maintain(rt);return;}
	if(Size[R[R[rt]]]>Size[L[rt]]) {zig(rt);maintain(L[rt]);maintain(rt);return;}
	if(Size[R[L[rt]]]>Size[R[rt]]) {zig(L[rt]);zag(rt);maintain(L[rt]);maintain(R[rt]);return;}
	if(Size[L[R[rt]]]>Size[L[rt]]) {zag(R[rt]);zig(rt);maintain(R[rt]);maintain(L[rt]);return;} 
}
void Insert(int &rt,int X){//在rt这课树的最左端插入，Insert的辅助函数 
	if(rt) {
		if(X <= Key[rt]) Insert(L[rt],X);
		else             Insert(R[rt],X);
		++Size[rt];maintain(rt);
	}
	else {
		rt=++IP;
		Key[rt]=X;
		Size[rt]=1;
		L[rt]=R[rt]=0;
	}
}
int Pred(int &rt,int X){
	if(!rt) return 0;
	if(Key[rt]>=X) return Pred(L[rt],X);
	else{
		int ID=Pred(R[rt],X);
		return ID?ID:rt;
	}
}
int Succ(int &rt,int X){
	if(!rt) return 0;
	if(Key[rt]<=X) return Succ(R[rt],X);
	else{
		int ID=Succ(L[rt],X);
		return ID?ID:rt;
	}
}
void Cut(int &rt,int *cnt,int v){
	Insert(rt,v);
	int L=Key[Pred(rt,v)],R=Key[Succ(rt,v)];
	cnt[R-L]--;
	cnt[v-L]++;
	cnt[R-v]++;
}
int w,h,n;
int main(void)
{
	freopen("527C.txt","r",stdin); 
	while(cin>>w>>h>>n){
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














