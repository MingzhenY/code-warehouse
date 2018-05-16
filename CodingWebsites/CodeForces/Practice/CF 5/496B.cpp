#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n;
char a[2000];
struct A{
	int start;
	bool operator <(const A &B)const{
		for(int i=start,j=B.start;i<start+n;++i,++j){
			int L=(a[i]+(10-a[start]))%10;
			int R=(a[j]+(10-a[B.start]))%10;
			if(L <R) return true;
			if(L >R) return false;
		}
		return false;
	}
}w[1000];

int main(void)
{
	freopen("496B.txt","r",stdin); 
	while(cin>>n){
		scanf("%s",a);
		for(int i=n;i<2*n;++i) a[i]=a[i-n];
		for(int i=0;i<n;++i) w[i].start=i;
		A Min;int MinI;
		Min=w[0];MinI=0;
		for(int i=1;i<n;++i) if(w[i]<Min){
			Min=w[i];
			MinI=i;
		}
		for(int i=w[MinI].start;i<w[MinI].start+n;++i){
			printf("%d",(a[i]+(10-a[w[MinI].start]))%10);
		}
		cout<<endl;
	}

		
return 0;
}














