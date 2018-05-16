#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
int main(void)
{freopen("1306.txt","r",stdin); 
	int N;
	while(cin>>N){
		priority_queue<unsigned int> Q;
		for(int i=0;i<N/2+1;i++){
			unsigned int a;
			scanf("%ud",&a);
			Q.push(a);
		}
		for(int i=N/2+1;i<N;i++){
			unsigned int a;
			scanf("%ud",&a);
			Q.push(a);
			Q.pop();
		}
		double ANS;
		if(N&1){
			ANS=Q.top();
			
		}
		else{
			ANS=Q.top();Q.pop();
			ANS+=Q.top();
			ANS/=2;
		}
		printf("%.1f\n",ANS);
	}
	
return 0;
}








