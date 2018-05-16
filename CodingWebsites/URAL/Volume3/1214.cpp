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

void P(long& x, long& y)
{
  int i, j;
  if (x>0 && y>0)
  {
    for (i = 1; i <= x+y; i++)
    {
      y = x*x+y;
      x = x*x+y;
      y = sqrt(x+(y/labs(y))*(-labs(y)));
      for (j = 1; j <= 2*y; j++)
        x = x-y;
    }
  }
}
int main(void)
{freopen("1214.txt","r",stdin); 
	long int A,B;
	while(cin>>A>>B){
		if(A>0&&B>0){
			if((A+B)&1) printf("%d %d\n",B,A);
			else printf("%d %d\n",A,B);
		}
		else{
			printf("%d %d\n",A,B);
		}
	}
return 0;
}








