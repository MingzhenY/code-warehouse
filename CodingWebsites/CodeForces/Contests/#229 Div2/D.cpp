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
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define out(i) <<#i<<"="<<i<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

using namespace std;
int max(int a,int b) {return a>b?a:b;}
int min(int a,int b) {return a<b?a:b;}
int zdgys(unsigned int a,unsigned int b){while(a){if(a<b){a=a^b;b=a^b;a=a^b;}  a=a%b;}return (int)b;} 
int zxgbs(int a,int b){return (a*b)/zdgys(a,b);}



int n,m,k;int penalty=0;int rol=2;

int bord[51][51]={};
vector <int> x,y;
void D(int,int,int);
void show(int,int);
int main(void)
{
	cin>>n>>m>>k;
	D(1,1,0);
	cout<<penalty<<endl;
	for(int i=0;i<x.size();i++)
		show(x[i],y[i]);







return 0;
}

void D(int i,int j,int num)
{
	if(num==k) return;
	if(bord[i][j]==0) {x.push_back(i);y.push_back(j);penalty=penalty+i+j-1;bord[i][j]=1;}
	else return;
	if(i-1>=1&&j+1<=m) D(i-1,j+1,num+1);
	else {D(rol++,1,num+1);}
}
void show(int i,int j)
{    int k=1,s=1;
	for(k=1;k<=i;k++) {printf("(%d,%d) ",k,s);}
	for(s=1;s<=j;s++) {printf("(%d,%d)",k,s);if(s<j)printf(" ");else printf("\n"); }
}











