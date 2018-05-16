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
int a,b;
cin>>a>>b;
int c=0;int count=0;
while(a--){c++;if(c>=b) {a++;c-=b;}  count++;}
cout<<count;

return 0;
}
