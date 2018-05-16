#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

using namespace std;

int n,k;
int main(void)
{
	freopen("C.txt","r",stdin); 
	while(cin>>n>>k){
		int L=1,R=n;
		if(k&1){
			for(int i=0;i<n;++i){
				if(i) printf(" ");
				if(~i&1) printf("%d",L++);
				else {
					if(R+(k-1)/2 >n) printf("%d",R--);
					else printf("%d",L++);
				}
			}
			printf("\n");
		}
		else{
			for(int i=0;i<n;++i){
				if(i) printf(" ");
				if(~i&1){
					if(R+k/2>n) printf("%d",R--);
					else printf("%d",L++);
				}
				else printf("%d",L++);
			}
			printf("\n");
		}
	}
	
return 0;
}














