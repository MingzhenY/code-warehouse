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

int a,b,c,a1,b1,q1=0,q2=0,q3=0;
cin>>a>>b;
for(int i=1;i<=6;i++) {
		a1=a>i?a-i:i-a;
		b1=b>i?b-i:i-b;
		if(a1<b1) q1++;
		if(a1==b1) q2++;
		if(a1>b1) q3++;
				}

printf("%d %d %d",q1,q2,q3);




return 0;
}
