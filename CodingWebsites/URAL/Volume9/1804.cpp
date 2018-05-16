#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

using namespace std;




void F(int i){
	for(int j=0;j<i;j++) scanf("%*s");
}
int main(void)
{
	freopen("1804.txt","r",stdin); 
	int T;cin>>T;int x,y;
	FOR(t,T){
		string a;
		F(3);cin>>a;
		F(2);scanf("%d",&x);
		F(3);scanf("%d",&y);
		F(1);
		int ANS1,ANS2;
		if(a[0]=='h'){
			for(int i=0;i<=30;i++){
				if(x+i>y||x+i==y&&i>=y){
					ANS1=i;break;
				}
			}
			for(int i=30;i>=0;i--){
				if(y+30>x+i||y+30==x+i&&y>=i){
					ANS2=i;break;
				}
			}
		}
		else{
			for(int i=0;i<=30;i++){
				if(x+i>=y){
					ANS1=i;break;
				}
			}
			for(int i=30;i>=0;i--){
				if(y+30>=x+i){
					ANS2=i;break;
				}
			}
		}
		
		
		printf("%d %d\n",ANS1,ANS2);
		
		
	}
return 0;
}














