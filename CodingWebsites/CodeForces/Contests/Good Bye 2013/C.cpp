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

struct peo
{   int x,y;//Öµ£¬Ô­Î»
}a[300001];

int cmp1(peo c,peo d)
{
    return c.x<d.x;
}
int cmp2(peo c,peo d)
{
    return c.y<d.y;
} 
int main(void)
{
int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i].x);a[i].y=i;
    }
    sort(a+1,a+1+n,cmp1);
    for(i=2;i<=n;i++)
    {
        if(a[i].x<=a[i-1].x)
            a[i].x=a[i-1].x+1;
    }
    sort(a+1,a+1+n,cmp2);
    for(i=1;i<=n;i++)
        printf("%d ",a[i].x);



return 0;
}
