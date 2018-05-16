#include <iostream>
#include <cstdio>
#include <cmath>
#define maxn 200007
using namespace std;
int L[maxn],R[maxn],Size[maxn];
int Max[maxn],Sum[maxn],Key[maxn];
int IP;
void Init(){//��ʼ�� 
	L[0]=R[0]=Size[0]=0;
	Max[0]=Sum[0]=Key[0]=0;
	IP=0;
}
void PushUp(int rt){//���½ڵ� 
	Size[rt]=1+Size[L[rt]]+Size[R[rt]];
	Sum[rt]=Key[rt]+Sum[L[rt]]+Sum[R[rt]];
	Max[rt]=max(Key[rt],max(Max[L[rt]],Max[R[rt]]));
}
void zig(int &rt){//���� 
	int t=R[rt];R[rt]=L[t];L[t]=rt;
	Size[rt]=Size[t];Sum[rt]=Sum[t];Max[rt]=Max[t];PushUp(t);rt=t;
}
void zag(int &rt){//���� 
	int t=L[rt];L[rt]=R[t];R[t]=rt;
	Size[rt]=Size[t];Sum[rt]=Sum[t];Max[rt]=Max[t];PushUp(t);rt=t;
}
void maintain(int &rt){//ƽ�� 
	if(Size[L[L[rt]]]>Size[R[rt]]) {zag(rt);maintain(R[rt]);maintain(rt);return;}
	if(Size[R[R[rt]]]>Size[L[rt]]) {zig(rt);maintain(L[rt]);maintain(rt);return;}
	if(Size[R[L[rt]]]>Size[R[rt]]) {zig(L[rt]);zag(rt);maintain(L[rt]);maintain(R[rt]);return;}
	if(Size[L[R[rt]]]>Size[L[rt]]) {zag(R[rt]);zig(rt);maintain(R[rt]);maintain(L[rt]);return;} 
}
void InsertLeft(int &rt,int X){//��rt�����������˲��룬Insert�ĸ������� 
	if(rt) {
		InsertLeft(L[rt],X);PushUp(rt);maintain(rt);
	}
	else {
		rt=++IP;
		Sum[rt]=Max[rt]=Key[rt]=X;
		Size[rt]=1;L[rt]=R[rt]=0;
	}
}
void Insert(int &rt,int X){//��X���и� 
	if(X < Sum[L[rt]]) {Insert(L[rt],X);PushUp(rt);maintain(rt);return;}
	X-=Sum[L[rt]];
	if(X > Key[rt]){Insert(R[rt],X - Key[rt]);PushUp(rt);maintain(rt);return;}
	InsertLeft(R[rt],Key[rt]-X);
	Key[rt]=X;PushUp(rt);
}
int w,h,n;
int main(void)
{
	freopen("527C.txt","r",stdin); 
	while(cin>>w>>h>>n){
		//��ʼ�� 
		Init();
		int H=0,V=0;  
		InsertLeft(H,h);InsertLeft(V,w);
		
		for(int i=0;i<n;++i){
			//��ȡ 
			char a;int v;
			scanf(" %c%d",&a,&v);
			//�и� 
			a=='H'?Insert(H,v):Insert(V,v);
			//��� 
			printf("%I64d\n",(long long)Max[H]*Max[V]);
		}
	}	
return 0;
}














