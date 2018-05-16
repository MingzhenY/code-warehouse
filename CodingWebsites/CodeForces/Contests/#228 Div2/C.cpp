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
int n,str[100],i;

int main(void)
{cin>>n;int zero=0;
for(i=0;i<n;i++) {scanf("%d",&str[i]);if(str[i]==0) zero++;}
sort(str,str+n);int ans=0,cur=0;
for(i=0;i<n-zero;i++) str[i]=str[i+zero];n-=zero;

while(cur!=n)
{ans++;
if(str[cur]==0) {zero++;ans--;continue;}
int k=0;
for(i=cur;i<n;i++)
{
if(i==n-1) {cur=n;break;}
k+=1;
if(k>str[i+1]) {cur=i+1;break;}
}

}


cout<<max(ans,zero);

return 0;
}
