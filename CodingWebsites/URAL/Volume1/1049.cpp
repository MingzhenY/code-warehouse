#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int a;
int p[10001]; 
int num[10001];
int k[50];int kn;
int main(void)
{freopen("1049.txt","r",stdin); 
	memset(p,0,sizeof(p));
	for(int i=2;i<10001;i++){
		if(p[i])continue;
		for(int j=i;j<10001;j+=i) {
			p[j]=i;
		}
	}
	memset(num,0,sizeof(num));
	for(int i=0;i<10;i++){
		scanf("%d",&a);
		while(a>1){
			num[p[a]]++;
			a/=p[a];
		}
	}
	kn=0;
	for(int i=0;i<10001;i++){
		if(num[i]) k[kn++]=num[i];
	}
	int ANS=1;
	for(int i=0;i<kn;i++){
		ANS*=k[i]+1;
		ANS%=10;
	}
	cout<<ANS<<endl;
return 0;
}








