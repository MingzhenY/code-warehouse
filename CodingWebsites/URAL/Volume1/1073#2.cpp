/*
四平方定理 
穷举 
*/
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
template <class T>
T Min(T a,T b) {
	return a<b?a:b;
}
int a[60001];
int b[60001];
int main(void)
{freopen("1073.txt","r",stdin); 
	int N;
	while(cin>>N){
		int ANS=0;memset(a,0,sizeof(a));memset(b,0,sizeof(b)); 
		for(int i=1;i<245;i++){
			if(i*i==N) {
				ANS=1;
				printf("%d->",i);
				break;
			}
		}
		
		if(!ANS){
			for(int i=1;i<245;i++){if(ANS) break;
				for(int j=i;j<245;j++){if(ANS) break;
					if(N==(i*i+j*j)){
						ANS=2;printf("(%d,%d)->",i,j);
					}
				}
			}
		}
		
		if(!ANS){
			for(int i=1;i<245;i++){if(ANS) break;
				for(int j=i;j<245;j++){if(ANS) break;
					for(int k=j;k<245;k++){if(ANS) break;
						if(N==(i*i+j*j+k*k)){
							ANS=3;
							printf("(%d,%d,%d)->",i,j,k);
						}
					}
				}
			}
		}
		if(!ANS) ANS=4;
		cout<<ANS<<endl;
	}
	

	
return 0;
}








