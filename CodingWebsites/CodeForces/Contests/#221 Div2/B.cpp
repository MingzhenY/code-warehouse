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
int main(void)
{
int n,m,P[101]={},a,b,c,sum=0;
cin>>n>>m;
while(m--) {
	scanf("%d%d%d",&a,&b,&c);
	P[a]-=c;P[b]+=c;
 		}
for(int i=1;i<101;i++)  if(P[i]>0) sum+=P[i];
cout<<sum;

return 0;
}
