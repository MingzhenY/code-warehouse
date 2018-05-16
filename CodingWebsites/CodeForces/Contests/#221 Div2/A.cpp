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
char s[1000010];int y;


int main(void)
{
long long int i=0,mid=0,left=0,n=0;
long long int right=0;
for(y=0;y<1000010;y++) s[y]=0;
scanf("%s",s);
while((s[i]>=48&&s[i]<=57)||s[i]=='='||s[i]=='^') {n++;i++;}
//cout<<n<<endl;

for(int j=0;j<n;j++){
	if(s[j]=='^') mid=j;
	else if(s[j]=='=')  s[j]=0;
		else if(s[j]==6) s[j]-=6;
		     else s[j]-=48;
			}
/*
while(scanf("%c",&s[i])!=EOF)
	{
	if(s[i]=='^') mid=i;
	else s[i]-=48;
	i++;
	}*/
for(long long int j=0;j<mid;j++) left+=s[j]*(mid-j);
for(long long int j=mid+1;j<n;j++) right=right+s[j]*(j-mid);
//cout<<left<<"  "<<right;
if(left>right) cout<<"left";
if(left<right) cout<<"right";
if(left==right) cout<<"balance";







return 0;
}
