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
int F(int);
char b[100001]={};
int main(void)
{
int n=0; long long int M=1;
cin>>b;
//if(a<10) {cout<<"1"; return 0;}


for(int i=0;i<100001;i++)
{
b[i]=b[i]-48;
}	
for(int i=0;i<100001;i++)
{
if(b[i]<10&&b[i]>0)  n++;
}	

for(int i=0;i<n-1;i++)
{
if(b[i]+b[i+1]==9) b[i]=1;
else b[i]=0;  
}	
n-=1;
//for(int i=0;i<n;i++) cout<<" "<<b[i];


int k=0;
for(int i=0;i<n;i++)
{
if(b[i])  {k++;}
else {M*=(long long int)F(k);k=0;} 
}	
M*=(long long int)F(k);

 cout<<M;	
	
return 0;
}
int F(int n)
{
if(n==0)  return 1;
else if (n%2==1) return 1;
else return  n/2+1;
}
