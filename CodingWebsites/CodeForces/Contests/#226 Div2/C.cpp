#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define  inf  0x3fffffff
using namespace std;
int max(int a,int b) {return a>b?a:b;}
int min(int a,int b) {return a<b?a:b;}
int zdgys(unsigned int a,unsigned int b){while(a){if(a<b){a=a^b;b=a^b;a=a^b;}  a=a%b;}return (int)b;} 
int zxgbs(int a,int b){return (a*b)/zdgys(a,b);}

int x[1000000],n,m,l[50000],r[50000];
int F(int);
bool isprime(int);

int main(void)
{
int i,j;int ANS=0;int low=2000000000,high=0;
cin>>n;
for(i=0;i<n;i++) scanf("%d",&x[i]);
cin>>m;
for(i=0;i<m;i++) {scanf("%d%d",&l[i],&r[i]);low=min(low,l[i]);high=max(high,r[i]);}


for(i=0;i<m;i++) {ANS=0;
			for(j=l[i];j<=r[i];j++)
				{
				if(isprime(j)) ANS+=F(j);
				}
			cout<<ANS<<endl;
			}
return 0;
}
int F(int k)
{int i,ANS=0;
for(i=0;i<n;i++) if(x[i]%k==0) ANS++;
return ANS;
}
bool isprime(int k)
{
if(k==2) return 1;
if(k%2==0) return 0;
int T=1,i,sq=sqrt(k)+1;
for(i=3;i<=sq;i+=2) if(k%i==0) {T=0;break;}
return T;
}




