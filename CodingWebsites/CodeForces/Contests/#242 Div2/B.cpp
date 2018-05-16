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
int zdgys(int a,int b){int t;if(a<b) {t=a;a=b;b=t;} while(b){t=a;a=b;b=t%b;}return a;} 
int zxgbs(int a,int b){return a/zdgys(a,b)*b;}




struct location{
	int x,y,num,r;
	void dis(){
		r=x*x+y*y;
	}
	bool operator <(const location&b)const{
		return r<b.r;
	}
}lo[1000];

int main(void)
{
	freopen("B.txt","r",stdin); 
	int n,s;
	while(cin>>n>>s){
		
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&lo[i].x,&lo[i].y,&lo[i].num);	
			lo[i].dis();
		}
		sort(lo,lo+n);
		int ANS;
		for(int i=0;i<n;i++){
			if(s>=1000000) break;
			s+=lo[i].num;
			ANS=lo[i].r;
		}
		
		if(s<1000000) printf("-1\n");
		else printf("%.7f\n",sqrt((double)ANS)  );
		
		
		
		
		
		
		
		
		
		
		
		
	}
return 0;
}
