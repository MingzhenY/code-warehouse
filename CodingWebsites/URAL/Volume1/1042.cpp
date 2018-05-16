#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
using namespace std;

bool a[251][251];//a[i][j]==1表示第i个人负责第j个灯。 
int N;
void swap(int t1,int t2){
	int t;
	for(int i=0;i<=N;i++) {
		t=a[t1][i];
		a[t1][i]=a[t2][i];
		a[t2][i]=t;
	}
}
void show(int k){
	printf("测试%d:\n",k);
	FOR(i,N){printf("%d:",i);
			For(j,N+1){
				printf("%d ",a[i][j]);
			}cout<<endl;
	}
}
int main(void)
{freopen("1042.txt","r",stdin); 
	while(cin>>N){
		memset(a,0,sizeof(a));
		//读取数据 
		FOR(i,N){
			int b;
			while(~scanf("%d",&b)&&~b){
				a[b][i]=1;
			}
		}
		FOR(i,N) a[i][0]=1;
		//高斯消元 
		int ERR=0;
		FOR(j,N){//保证第j列只有第j行的数是1，其余为零。 
			int I=-1;
			for(int i=j;i<=N;i++) {
				if(a[i][j]) {
					I=i;break;
				}
			}
			if(!~I) {
				ERR=1;break;
			}
			swap(I,j);//换到第j行。
			for(int i=0;i<=N;i++){
				if(i==j) continue;
				if(a[i][j]){
					for(int k=0;k<=N;k++){
						a[i][k]^=a[j][k];
					}	
				}
			}
		}
		//输出结果 
		if(ERR){
			printf("No solution\n");
		}
		else{
			int T=0;
			for(int i=1;i<=N;i++){
				if(T) printf(" ");
				if(a[i][0])printf("%d",i);
				T++;
			}cout<<endl;
		}
	}
return 0;
}








