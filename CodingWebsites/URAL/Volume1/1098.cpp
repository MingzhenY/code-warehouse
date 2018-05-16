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

char str[30007]; 
int n;
int main(void)
{freopen("1098.txt","r",stdin); 
	n=0;
	while(~scanf("%c",&str[n])) if(str[n]!='\n') n++;
	long long D=1;
	long long p=1999;
	long long Top=n*(p-1);
	while(D <= Top){D=(D*p+p-2)/(p-1);}
	char ch=str[n*p-D];
	if(ch=='?') printf("Yes\n");
	else if(ch==' ')  printf("No\n");
	else printf("No comments\n");
return 0;
}








