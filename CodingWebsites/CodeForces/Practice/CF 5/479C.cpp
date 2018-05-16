#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
struct A{
	int a,b;
	bool operator<(const A&B)const{return a <B.a||a==B.a&&b < B.b;}
	void ReadIn(){scanf("%d%d",&a,&b);}
}exam[5000];
int main(void)
{
	freopen("479C.txt","r",stdin); 
	while(~scanf("%d",&n)){
		for(int i=0;i<n;++i) exam[i].ReadIn();
		sort(exam,exam+n);
		int Day=0;
		for(int i=0;i<n;++i){
			if(exam[i].b>=Day){
				Day=exam[i].b;
				continue;
			}
			else{
				Day=exam[i].a;
			}
		}
		cout<<Day<<endl;
	}

		
return 0;
}














