#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n;
int a[100];
int d1[100],d2[100];
int n1,n2;
int main(void)
{
	freopen("25A.txt","r",stdin); 
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	n1=n2=0;
	for(int i=0;i<n;++i){
		if(a[i]&1) d1[n1++]=a[i];
		else d2[n2++]=a[i];
	}
	int D; 
	if(n1==1) D=d1[0];
	else D=d2[0];
	for(int i=0;i<n;++i) {
		if(D==a[i]) {
			printf("%d\n",i+1);
			break;
		} 
	}
return 0;
}














