#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define LL long long
using namespace std;
LL m,n,a,b,c,d,x,y;
char ANS[1000000];
char temp[100];
char *p;
int main(void)
{
	//freopen("585C.txt","r",stdin); 
	while(~scanf("%I64d%I64d",&m,&n)){
		//freopen("CON","r",stdin);
		ANS[0]=0;
		p=ANS;
		a=1,b=0;
		c=0,d=1;
		x=1,y=1;
		while(x < m || y < n){
			if(y*m==x*n) break;
			if(m*y <= n*x){
				LL k=(a*n-b*m-1)/(d*m-c*n);
				sprintf(temp,"%I64dB",k);
				a+=k*c;b+=k*d;
			}
			else{
				LL k=(d*m-c*n-1)/(a*n-b*m);
				sprintf(temp,"%I64dA",k);
				c+=k*a;d+=k*b;
			}
			x=a+c;y=b+d;
			strcat(p,temp);
			while(!*p) p++;
		}
		if(x==m&&y==n) printf("%s\n",ANS);
		else printf("Impossible\n");
	}
return 0;
}

