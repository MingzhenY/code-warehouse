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

int N;string str;
int D[1001];
int main(void)
{freopen("1007.txt","r",stdin); 
	cin>>N;
	while(cin>>str){
		int n=str.length();int ALL=0; 
		D[0]=str[0]-48;
		for(int i=1;i<n;i++)  D[i]=D[i-1]+str[i]-48;
		for(int i=1;i<=n;i++) ALL+=(str[i-1]-48)*i;
		if(n==N+1){//多了某个1或0 
			int tempA=0;int Mark;
			for(int i=0;i<n;i++){//去掉i的话， 
				if(str[i]-48){
					tempA=ALL-(i+1)-(D[n-1]-D[i]);	
				}
				else{
					tempA=ALL-(D[n-1]-D[i]);
				}
				if(tempA%(N+1)==0) {
					Mark=i;break;
				}
			}
			for(int i=0;i<n;i++) {
				if(i!=Mark) printf("%c",str[i]);
			}
			cout<<endl;
		}
		else if(n==N){//某个0变成了1，或没变。 
			if(ALL%(N+1)==0){
				cout<<str<<endl;
				continue;
			}
			int tempA;int Mark;
			for(int i=0;i<n;i++){//把i变成0 
				if(str[i]-48){
					tempA=ALL-(i+1);
					if(tempA%(N+1)==0) {
						Mark=i;break;
					}
				}
			}
			for(int i=0;i<n;i++) {
				if(i!=Mark) printf("%c",str[i]);
				else printf("%c",str[i]-1);
			}
			cout<<endl;
		}
		else if(n==N-1){//少了一个数
			
			//假设在最后一个插入
			if((ALL+n+1)%(N+1)==0) {
				cout<<str;cout<<1<<endl;continue;
			} 
			if(ALL%(N+1)==0){
				cout<<str;cout<<0<<endl;continue;
			}
			int tempA;int Mark;int Number; 
			for(int i=0;i<n;i++){//假设在i之前插入 
				tempA=ALL+(D[n-1]-D[i]+str[i]-48);
				if(tempA%(N+1)==0){
					Mark=i;Number=0;break;
				}
				if((tempA+i+1)%(N+1)==0){
					Mark=i;Number=1;break;
				}
				
			}
			for(int i=0;i<n;i++){
				if(i==Mark) printf("%c",Number+48);
				printf("%c",str[i]);
			}
			cout<<endl;
		}
		
	}
return 0;
}








