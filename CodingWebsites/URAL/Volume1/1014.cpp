#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

int count[10];
void F(int i,int n){
	for(int j=0;j<n;j++){
		printf("%d",i);
	}
}
int main(void)
{freopen("1014.txt","r",stdin); 
	int a;
	while(cin>>a){
		//printf("%d:",a);
		memset(count,0,sizeof(count));
	
		if(a<10){
			if(!a){
				cout<<"10"<<endl;
				continue;
			}
			cout<<a<<endl;
			continue;
		}
		
		for(int i=9;i>1;i--){
			while(!(a%i)) count[i]++,a/=i;
		}
		//int Dig=0;
		//for(int i=1;i<=9;i++) Dig+=count[i];
		if(a>1) {
			printf("-1");
			continue;
		}
		for(int i=1;i<=9;i++){
			F(i,count[i]);
		}
		cout<<endl;
	}
	
	
return 0;
}








