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

int N,X,Y,Z;
int main(void)
{freopen("1140.txt","r",stdin); 
	while(cin>>N){
		X=Y=Z=0;
		char op;int step;
		for(int i=0;i<N;++i){
			scanf(" %c%d",&op,&step);
			switch(op){//Z=Y-X
				case 'X':X+=step;break;
				case 'Y':Y+=step;break;
				case 'Z':X-=step;Y+=step;break;
				default:break;
			}
			//OUT3(op,X,Y);
		}
		//OUT2(X,Y);
		if(X*Y < 0){
			int s=min(abs(X),abs(Y));
			if(X < 0){
				X+=s;Y-=s;Z=s;
			} 
			else{
				X-=s;Y+=s;Z=-s;
			}
		}
		printf("%d\n",(!!X)+(!!Y)+(!!Z));
		if(X) printf("X %d\n",-X);
		if(Y) printf("Y %d\n",-Y);
		if(Z) printf("Z %d\n",-Z);
	}
return 0;
}








