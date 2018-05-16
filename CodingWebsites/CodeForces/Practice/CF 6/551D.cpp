#include <iostream>
#include <cstdio>
#include <cmath>
#define LL long long
using namespace std;
LL M;
struct Matrix{
	LL a[2][2];
	static Matrix Pow(Matrix X,LL k){
		Matrix ANS;
		ANS.a[0][0]=ANS.a[1][1]=1;
		ANS.a[0][1]=ANS.a[1][0]=0;
		while(k){
			if(k&1) ANS=ANS*X;
			X=X*X;
			k>>=1;
		}
		return ANS;
	}
	Matrix operator*(Matrix &B){
		Matrix C;
		for(int i=0;i<2;++i){
			for(int j=0;j<2;++j){
				C.a[i][j]=0;
				for(int k=0;k<2;++k) C.a[i][j]=(C.a[i][j]+a[i][k]*B.a[k][j])%M;
			}
		}
		return C;
	}
	void show(){
		for(int i=0;i<2;++i){
			for(int j=0;j<2;++j){
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}
}; 
LL qPow(LL x,LL k){
	LL ANS=1;
	while(k){
		if(k&1) ANS=(ANS*x)%M;
		x=(x*x)%M;
		k>>=1;
	}
	return ANS;
}
LL p2[63];
LL GetBit(LL k){
	int L=0,R=62,M_;//[L,R] first > k
	while(L^R){
		M_=(L+R)>>1;
		if(p2[M_]<=k) L=M_+1;
		else R=M_;
	}
	return L;
}
LL CountBits(LL x){
	LL ANS=0;
	while(x){
		if(x&1) ANS++; 
		x>>=1; 
	} 
	return ANS;
}
LL n,k,l;
int main(void)
{
	freopen("551D.txt","r",stdin); 
	p2[0]=1;
	for(int i=1;i<63;++i) p2[i]=p2[i-1]<<1;
	while(cin>>n>>k>>l>>M){
		if(GetBit(k)>l) {cout<<0<<endl;continue;}
		Matrix A;
		A.a[0][0]=1;A.a[0][1]=1;
		A.a[1][0]=1;A.a[1][1]=0;
		A=Matrix::Pow(A,n);
		LL X=(A.a[0][0]+A.a[0][1])%M;
		LL X2=(qPow(2,n)+M-X)%M;
		LL Bits=CountBits(k);
		LL ANS=(qPow(X,l-Bits)*qPow(X2,Bits))%M;
		cout<<ANS<<endl;
	}
return 0;
}

