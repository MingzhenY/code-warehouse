#include <iostream>
#include <cstdio>
#include <cmath>
#define maxn 200007
using namespace std;
int L[maxn],R[maxn];
int Max[maxn],Sum[maxn],Key[maxn];
int IP;
void Init(){//��ʼ�� 
	L[0]=R[0]=0;
	Max[0]=Sum[0]=Key[0]=0;
	IP=0;
}
void PushUp(int rt){//���½ڵ� 
	Sum[rt]=Key[rt]+Sum[L[rt]]+Sum[R[rt]];
	Max[rt]=max(Key[rt],max(Max[L[rt]],Max[R[rt]]));
}
void InsertLeft(int &rt,int X){//��rt�����������˲��룬Insert�ĸ������� 
	if(rt) {
		InsertLeft(L[rt],X);PushUp(rt);
	}
	else {
		rt=++IP;
		Sum[rt]=Max[rt]=Key[rt]=X;
		L[rt]=R[rt]=0;
	}
}
void Insert(int &rt,int X){//��X���и� 
	if(X < Sum[L[rt]]) {Insert(L[rt],X);PushUp(rt);return;}
	X-=Sum[L[rt]];
	if(X > Key[rt]){Insert(R[rt],X - Key[rt]);PushUp(rt);return;}
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














