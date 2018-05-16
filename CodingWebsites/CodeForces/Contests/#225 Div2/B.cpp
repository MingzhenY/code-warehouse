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
int array[1000][100],M,N,T,trace[5000][2];

int main(void)
{
cin>>N>>M>>T;
int i,j,F=0,count=0;
for(i=0;i<N;i++) for(j=0;j<M;j++) scanf("%d",&array[i][j]);

for(i=0;i<M;i++) for(j=i;j<M;j++) {
	int i1;
	for(i1=0;i1<N;i1++){int G; if(T) G=array[i1][i]<array[i1][j];else G=array[i1][i]>array[i1][j];
		 if (G)  {array[i1][i]=array[i1][i]^array[i1][j];
								array[i1][j]=array[i1][i]^array[i1][j];
								array[i1][i]=array[i1][i]^array[i1][j];	
								F=1;							
								}
					}
	if(F==1) {F=0;trace[count][0]=i;trace[count][1]=j;count++;}
}
cout<<count<<endl;
if(T) for(i=0;i<count;i++) cout<<trace[i][1]+1<<" "<<trace[i][0]+1<<endl;
else for(i=0;i<count;i++) cout<<trace[i][0]+1<<" "<<trace[i][1]+1<<endl;


return 0;
}
