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

using namespace std;
int max(int a,int b) {return a>b?a:b;}
int min(int a,int b) {return a<b?a:b;}

int main(void)
{
int n,m,i,j,a,b;
cin>>n>>m>>i>>j>>a>>b;

if((i==1 && j==1) || (i==1 && j==m) || (i==n && j==1) || (i==n && j==m)) {cout<<"0";return 0;}
if(a>=n||b>=m) {cout<<"Poor Inna and pony!";return 0;}
int inf=1<<31;inf--;
int ans=inf;
if((i-1)%a==0&&(j-1)%b==0&&((i-1)/a+(j-1)/b)%2==0)  ans=min(ans,max((i-1)/a,(j-1)/b));
if((n-i)%a==0&&(j-1)%b==0&&((n-i)/a+(j-1)/b)%2==0)  ans=min(ans,max((n-i)/a,(j-1)/b));
if((i-1)%a==0&&(m-j)%b==0&&((i-1)/a+(m-j)/b)%2==0)  ans=min(ans,max((i-1)/a,(m-j)/b));
if((n-i)%a==0&&(m-j)%b==0&&((n-i)/a+(m-j)/b)%2==0)  ans=min(ans,max((n-i)/a,(m-j)/b));
if(ans==inf) cout<<"Poor Inna and pony!";
else cout<<ans;
return 0;
}
