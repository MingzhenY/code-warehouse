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

int n,c;
int day[100];


int main(void)
{
cin>>n>>c;
int i,j,ANS=0;
for(i=0;i<n;i++) cin>>day[i];
for(j=0;j<n-1;j++){
				int _ANS;
				_ANS=day[j]-day[j+1]-c;
				ANS=max(_ANS,ANS);		
				}


cout<<ANS;



return 0;
}
