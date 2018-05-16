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
#include <cstring>
#define  inf  0x3fffffff
using namespace std;
int max(int a,int b) {return a>b?a:b;}
int min(int a,int b) {return a<b?a:b;}
int zdgys(unsigned int a,unsigned int b){while(a){if(a<b){a=a^b;b=a^b;a=a^b;}  a=a%b;}return (int)b;} 
int zxgbs(int a,int b){return (a*b)/zdgys(a,b);}
char a[27],b[27]; 
int main(void)
{memset(a,-1,27);memset(b,-1,27);
scanf("%s",a);
scanf("%s",b);
int i,n,end,endb,half;
for(i=0;i<27;i++) {
		if(a[i]=='|') {n=i;continue;}
		if(a[i]<65||a[i]>90) {end=i;break;}
		}
for(i=0;i<27;i++) {
		
		if(b[i]<65||b[i]>90) {endb=i;break;}
		}
int L,R;
//cout<<"end="<<end<<endl;
//cout<<"endb="<<endb<<endl;
L=n;R=end-n-1;
//cout<<"n="<<n<<endl;
if((L+R+endb)%2==1) {cout<<"Impossible";return 0;}
half=(L+R+endb)/2;
//cout<<"half="<<half<<endl;
if((L>R?L-R:R-L)>endb) {cout<<"Impossible";return 0;}
int count=0;
for(i=0;i<28;i++)
{
if(i<half) {if(i<n) cout<<a[i]; else {cout<<b[count];count++;}}
if(i==half) cout<<"|";
if(i>=(half)&&i<2*half) {if(n+i-half+1<end) cout<<a[n+i-half+1]; else {cout<<b[count];count++;}} 


}




return 0;
}
