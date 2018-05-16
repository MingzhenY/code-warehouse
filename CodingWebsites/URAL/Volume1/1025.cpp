#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int a[101];int K;
int main(void)
{freopen("1025.txt","r",stdin); 
	while(cin>>K){
		for(int i=0;i<K;i++){
			scanf("%d",&a[i]);
			a[i]=(a[i]+1)>>1;
		}
		sort(a,a+K);
		K=(K+1)>>1;
		int ANS=0;
		for(int i=0;i<K;i++){
			ANS+=a[i];
		}
		cout<<ANS<<endl;
	}
return 0;
}








