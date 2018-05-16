#include <iostream>
#include <cstdio>
#include <cmath>
#define M (1<<30)
using namespace std;
int a,b,c;
int num[2001];
int Sum[2001];
int Mul(int a,int b){return (a*b)%M;}
int Plus(int a,int b){return (a+b)%M;}
int Minus(int a,int b){return (a+M-b)%M;}
int main(void)
{
	freopen("235E.txt","r",stdin);
	for(int i=2;i<=2000;++i){
		if(num[i]) continue;
		int temp=i;
		while(temp<=2000){
			for(int j=temp;j<=2000;j+=temp){
				++num[j];
			}
			temp*=i;	
		}
	}
	for(int i=1;i<=2000;++i) ++num[i];
	for(int i=1;i<=2000;++i){
		Sum[i]=Sum[i-1]+num[i];
		printf("%d->%d\n",i,num[i]);
	}
	while(cin>>a>>b>>c){
		int ANS=Plus(
		 Plus(Mul(Mul(a,c),Sum[b]),Mul(Mul(c,b),Sum[a]))
		,Minus(Mul(Mul(a,b),Sum[c]),Mul(Mul(a,b),c<<1))
		);
		cout<<ANS<<endl;
		ANS=0;
		for(int i=1;i<=a;++i){
			for(int j=1;j<=b;++j){
				for(int k=1;k<=c;++k){
					ANS+=num[i*j*k];
				}
			}
		}
		cout<<ANS<<endl;
	}
return 0;
}














