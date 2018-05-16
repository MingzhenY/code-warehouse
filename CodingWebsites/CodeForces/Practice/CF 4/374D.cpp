#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define maxn 1000010
using namespace std;
int N,n,m,Now,op;
int a[maxn];
int index[maxn<<2];
int value[maxn];
void ST_Init(){
	N=1;while(N <n+2) N <<=1;
	memset(index,0,sizeof(index));
}
void PushUp(int rt){
	index[rt]=index[rt<<1]+index[rt<<1|1];
}
void Set(int X,int C,int l,int r,int rt){
	if(l==r){
		value[l]=C;
		index[rt]=1;
		++Now;
		return;
	}
	int m=(l+r)>>1;
	if(X <=m) Set(X,C,l,m,rt<<1);
	else Set(X,C,m+1,r,rt<<1|1);
	PushUp(rt);
}
void Del(int X,int l,int r,int rt){
	if(l==r){
		index[rt]=0;
		return;
	}
	int m=(l+r)>>1;
	if(X <= index[rt<<1]) Del(X,l,m,rt<<1);
	else Del(X-index[rt<<1],m+1,r,rt<<1|1);
	PushUp(rt);
}
void show(){
	for(int i=0;i<Now;++i){
		if(index[N+i]){
			printf("%d",value[i+1]);
		}
	}
	cout<<endl;
}
int main(void)
{
	freopen("374D.txt","r",stdin); 
	while(~scanf("%d%d",&n,&m)){
		Now=1;ST_Init();
		for(int i=0;i<m;++i) scanf("%d",&a[i]);
		for(int i=0;i<n;++i) {
			scanf("%d",&op);
			if(~op){
				Set(Now,op,1,N,1);
			}
			else{
				for(int j=0;j<m&&a[j]-j<=index[1];j++){
					Del(a[j]-j,1,N,1);
				}
			}
		}
		if(index[1]){
			show();
		}
		else{
			printf("Poor stack!\n");
		}
	}
return 0;
}














