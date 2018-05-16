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

long long n,k; 
long long F[2][44];//F[i][j]：以i开头，长度为j的种类数 
void InitF(){
	F[0][1]=1;F[1][1]=1;
	for(int len=2;len<44;++len){
		F[0][len]=F[0][len-1]+F[1][len-1];
		F[1][len]=F[0][len-1];
		//OUT3(len,F[0][len],F[1][len]);
	}
}
char str[50]; 
int main(void)
{freopen("1081.txt","r",stdin); 
	InitF();
	while(cin>>n>>k){--k;
		if(k>=F[0][n]+F[1][n]) {
			printf("-1\n");
			continue;
		}
		for(int i=0;i<n;++i){
			if(k>=F[0][n-i]){
				str[i]='1';
				str[i+1]='0';
				k-=F[0][n-i];
				++i;
			}
			else{
				str[i]='0';
			}
		}
		str[n]='\0';
		printf("%s\n",str);
	}
return 0;
}








