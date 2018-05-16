#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,k;
int main(void)
{
	freopen("463A.txt","r",stdin); 
	while(~scanf("%d%d",&n,&k)){
		int ANS=-1;
		for(int i=0;i<n;i++){
			int d,c;
			scanf("%d%d",&d,&c);
			if(d <k||d==k&&c==0){
				if(c){
					if(!~ANS||100-c>ANS){
						ANS=100-c;
					}
				}
				else if(!~ANS){
					ANS=0;
				} 
			}
		}
		printf("%d\n",ANS);
	}	
return 0;
}














