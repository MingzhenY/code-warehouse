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

char str[100001];
int N,M; 
bool check(int L,int R){
	while(L <=R){
		if(str[L++]!=str[R--]) return 0;
	}
	return 1;
}
int main(void)
{freopen("1989.txt","r",stdin); 
	while(~scanf("%s",str+1)){
		str[0]='0';N=strlen(str)-1;
		cin>>M;
		For(i,M){
			char op[20];scanf("%s",op);
			if(op[0]=='c'){
				int a;char b;
				scanf("%d %c",&a,&b);
				str[a]=b;
			}
			else{
				int a,b;
				scanf("%d%d",&a,&b);
				int T=check(a,b);
				if(T) printf("YES\n");
				else printf("NO\n");
			}
		} 
		
	}
return 0;
}








