#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n;
int a[100];
int main(void)
{
	freopen("496A.txt","r",stdin); 
	while(cin>>n){
		for(int i=0;i<n;++i) scanf("%d",&a[i]);
		int Min=a[2]-a[0],MinI=0;
		for(int i=0;i<n-2;++i){
			if(a[i+2]-a[i]<Min){
				Min=a[i+2]-a[i];
				MinI=i;
			}
		}
		a[MinI+1]=a[MinI];
		int ANS=0;
		for(int i=0;i<n-1;++i){
			if(a[i+1]-a[i]>ANS) ANS=a[i+1]-a[i];
		}
		cout<<ANS<<endl;
	}

		
return 0;
}














