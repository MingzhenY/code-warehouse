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

int bear[1250],cur=0;string a;
long long Func(int,int,int,int);

int main(void)
{
cin>>a;int n=a.length();
int i,j;long long ANS=0;
for(i=0;i<n-3;i++) if(a[i]=='b'&&a[i+1]=='e'&&a[i+2]=='a'&&a[i+3]=='r') bear[cur++]=i;
//if(cur==1) cour<<Func(0,bear[0],bear[0]+3,n-1);
int left,start,end,right;//Func(left,start,end,right)
for(i=1;i<=cur;i++)
{

for(j=0;j<=cur-i;j++)
	{
	if(j==0) left=0; else left=bear[j-1]+1;
	if(j==cur-i) right=n-1;else right=bear[j+i]+2;
	start=bear[j];end=bear[j+i-1]+3;
	ANS+=Func(left,start,end,right);
	}


}

cout<<ANS;
return 0;
}
long long Func(int left,int start,int end,int right)
{
return (long long)((long long)start-(long long)left+1ll)*((long long)right-(long long)end+1ll);
}
