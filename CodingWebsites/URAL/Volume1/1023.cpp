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

int p[100001];int K;
int main(void)
{freopen("1023.txt","r",stdin); 
	memset(p,0,sizeof(p));
	for(int i=2;i<100001;i++){
		if(p[i]) continue;
		for(int j=i;j<100001;j+=i){
			p[j]=i;
		}
	}
	//for(int i=1;i<100;i++) OUT2(i,p[i]);
	cin>>K;
	if(!(K%3)) {
		cout<<2<<endl;return 0;
	}
	if(!(K%4)) {
		cout<<3<<endl;return 0;
	}
	if(!(K&1)) K>>=1;
	int ANS=K;
	if(K<100001){
		while(K>1){
			K/=p[K];
			if(K==1) break;
			else ANS=K;
		}
	}
	else{
		for(int i=3;i<=10000;i++){
			if(p[i]==i&&((K%i)==0)){
				ANS=i;break;
			}
		}
	}
	ANS--;
	cout<<ANS<<endl;
	
	
return 0;
}








