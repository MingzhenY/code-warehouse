#include <iostream>
#include <cstdio>
#include <cmath>
#define maxn 200007
using namespace std;
int L[maxn],R[maxn],Size[maxn];
int Max[maxn],Sum[maxn],Key[maxn];
int IP;
void Init(){//初始化 
	L[0]=R[0]=Size[0]=0;
	Max[0]=Sum[0]=Key[0]=0;
	IP=0;
}
void PushUp(int rt){//更新节点 
	Size[rt]=1+Size[L[rt]]+Size[R[rt]];
	Sum[rt]=Key[rt]+Sum[L[rt]]+Sum[R[rt]];
	Max[rt]=max(Key[rt],max(Max[L[rt]],Max[R[rt]]));
}
void zig(int &rt){//左旋 
	int t=R[rt];R[rt]=L[t];L[t]=rt;
	PushUp(rt);PushUp(t);rt=t;
}
void zag(int &rt){//右旋 
	int t=L[rt];L[rt]=R[t];R[t]=rt;
	PushUp(rt);PushUp(t);rt=t;
}
void maintain(int &rt,bool flag){//平衡 
	if(flag){
		if(Size[L[L[rt]]]>Size[R[rt]]) zag(rt);
		else if(Size[R[L[rt]]]>Size[R[rt]]){zig(L[rt]);zag(rt);}
		else return;
	}
	else{
		if(Size[R[R[rt]]]>Size[L[rt]]) {zig(rt);}
		else if(Size[L[R[rt]]]>Size[L[rt]]) {zag(R[rt]);zig(rt);}
		else return;
	}
	maintain(L[rt],true);maintain(R[rt],false);
	maintain(rt,true);maintain(rt,false); 
}
void InsertLeft(int &rt,int X){//在rt这课树的最左端插入，Insert的辅助函数 
	if(rt) {
		InsertLeft(L[rt],X);PushUp(rt);maintain(rt,true);
	}
	else {
		rt=++IP;
		Sum[rt]=Max[rt]=Key[rt]=X;
		Size[rt]=1;L[rt]=R[rt]=0;
	}
}
void Insert(int &rt,int X){//在X处切割 
	if(X < Sum[L[rt]]) {Insert(L[rt],X);PushUp(rt);maintain(rt,true);return;}
	X-=Sum[L[rt]];
	if(X > Key[rt]){Insert(R[rt],X - Key[rt]);PushUp(rt);maintain(rt,false);return;}
	InsertLeft(R[rt],Key[rt]-X);
	Key[rt]=X;PushUp(rt);
	maintain(rt,true); 
}
int w,h,n;
int main(void)
{
	freopen("527C.txt","r",stdin); 
	while(cin>>w>>h>>n){
		//初始化 
		Init();
		int H=0,V=0;  
		InsertLeft(H,h);InsertLeft(V,w);
		
		for(int i=0;i<n;++i){
			//读取 
			char a;int v;
			scanf(" %c%d",&a,&v);
			//切割 
			a=='H'?Insert(H,v):Insert(V,v);
			//输出 
			printf("%I64d\n",(long long)Max[H]*Max[V]);
		}
	}	
return 0;
}














