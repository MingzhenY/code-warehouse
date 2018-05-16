#include <iostream>
#include <cstdio>
#include <cmath>
#define maxn 200001
using namespace std;
int L[maxn<<2][2];//����ʼ��������� 
int R[maxn<<2][2];//���� 
int Max[maxn<<2][2];//������������� 
bool Pure[maxn<<2][2];//�Ƿ�ȫ�� 
int M[2];
void PushUp(int rt,int k){//����rt�ڵ���ĸ����� 
	Pure[rt][k]=Pure[rt<<1][k]&&Pure[rt<<1|1][k]; 
	Max[rt][k]=max(R[rt<<1][k]+L[rt<<1|1][k],max(Max[rt<<1][k],Max[rt<<1|1][k]));
	L[rt][k]=Pure[rt<<1][k]?L[rt<<1][k]+L[rt<<1|1][k]:L[rt<<1][k];
	R[rt][k]=Pure[rt<<1|1][k]?R[rt<<1|1][k]+R[rt<<1][k]:R[rt<<1|1][k];
}
void Build(int n,int k){//����������ֵ
	for(int i=0;i<M[k];++i) L[M[k]+i][k]=R[M[k]+i][k]=Max[M[k]+i][k]=Pure[M[k]+i][k]=i<n;
	for(int i=M[k]-1;i>0;--i) PushUp(i,k);
}
void Change(int X,int k){//�и���� 
	int s=M[k]+X-1;
	Pure[s][k]=Max[s][k]=R[s][k]=L[s][k]=0;
	for(s>>=1;s;s>>=1) PushUp(s,k);
} 
int main(void)
{
	freopen("527C.txt","r",stdin); 
	int w,h,n;
	while(cin>>w>>h>>n){
		//����3�У��ҳ��ǵݹ��߶����ĵ�һ������λ�á� 
		M[0]=M[1]=1;
		while(M[0]<h-1) M[0]<<=1;
		while(M[1]<w-1) M[1]<<=1;
		//���� 
		Build(h-1,0);Build(w-1,1);
		
		for(int i=0;i<n;++i){
			//��ȡ���� 
			char x;int v;
			scanf(" %c%d",&x,&v);
			//�и� 
			x=='H'?Change(v,0):Change(v,1);
			//��� 
			printf("%I64d\n",(long long)(Max[1][0]+1)*(Max[1][1]+1));
		}
	}
return 0;
}














