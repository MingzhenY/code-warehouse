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
int zdgys(int a,int b){while(b){int t=a;a=b;b=t%b;}return a;} 
int zxgbs(int a,int b){return a/zdgys(a,b)*b;}




int N,a,ALL,ANS;;

int main(void)
{
	freopen("A.txt","r",stdin); 
	
	while(cin>>N){
		ALL=0;ANS=0;
		for(int i=0;i<N;i++){
			scanf("%d",&a);
			
			if(a==-1){
				if(ALL>0) ALL--;
				else ANS++;
			} 
			else{
				ALL+=a;
			}
		}
		
		
		cout<<ANS<<endl;
		
	}
return 0;
}














