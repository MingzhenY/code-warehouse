#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define M 1000000007
using namespace std;

long long dp[101];
int SumOfdp;
int c[101];
int n,x;

struct A{
	long long a[101][101];
	A operator*(const A &B)const{
		A x;
		for(int i=0;i<101;++i){
			for(int j=0;j<101;++j){
				x.a[i][j]=0;
				for(int k=0;k<101;++k){
					x.a[i][j]=(x.a[i][j]+a[i][k]*B.a[k][j])%M;
				}
			}
		}
		return x;
	}
	A power(int k){
		if(k==1) return *this;
		if(k==2) return *this**this;
		A X=power(k/2);
		if(k&1) return *this*X*X;
		else return X*X;
	}
};
int main(void)
{
	freopen("514E.txt","r",stdin); 
	while(~scanf("%d%d",&n,&x)){
		
		memset(c,0,sizeof(c));
		//输入 
		for(int i=0;i<n;++i){
			int a;scanf("%d",&a);++c[a];
		}
		if(x==0){
			cout<<1<<endl;
			continue;
		}
		//计算dp
		SumOfdp=dp[0]=1;
		for(int i=1;i<=100;++i){
			dp[i]=0;
			for(int j=1;j<=i;++j) dp[i]=(dp[i]+c[j]*dp[i-j])%M;
			SumOfdp=(SumOfdp+dp[i])%M;
			if(i==x) break;
		}
		if(x <=100){
			cout<<SumOfdp <<endl;
			continue;
		}
		//矩阵快速幂
		//printf("矩阵运算开始:\n");
		A X;
		for(int i=0;i<101;++i){
			for(int j=0;j<101;++j){
				if(j<99){
					X.a[i][j]=(i==j+1);
				}
				else{
					if(i<100) X.a[i][j]=c[100-i];
					else{
						X.a[i][j]=(j==100);
					}
				}
				//if(X.a[i][j]!=0) printf("a[%d][%d]=%d\n",i,j,X.a[i][j]);
			}
		}
		//printf("矩阵初始化完成: x=%d\n",x);
		X=X.power(x-100);
		//printf("矩阵运算完成:\n");
		long long ANS=SumOfdp;
		for(int i=1;i<=100;++i){
			ANS=(ANS+dp[i]*X.a[i-1][100])%M;
		}
		//printf("结果计算完成:\n");
		cout<<ANS <<endl;
	}

		
return 0;
}














