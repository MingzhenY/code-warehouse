#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

int ALL,ANS,tempA; 
int h[10101];
int Ih[102];
int N,K;
int main(void)
{freopen("1090.txt","r",stdin); 
	while(cin>>N>>K){
		
		ALL=-1;ANS=1;
		for(int i=0;i<K;i++){
			memset(h,0,sizeof(h));memset(Ih,0,sizeof(Ih));
			tempA=0;
			for(int j=0;j<N;j++){
				int temp;
				scanf("%d",&temp);
				for(int i=temp;i<temp/100*100+100;i++) tempA+=h[i];
				for(int i=temp/100+1;i<=101;i++) tempA+=Ih[i];
				h[temp]++;Ih[temp/100]++;
			}
			if(~ALL) {
				if(tempA>ALL) ALL=tempA,ANS=i+1;
			}
			else ALL=tempA,ANS=i+1;
		}
		cout<<ANS<<endl;
	}
return 0;
}








