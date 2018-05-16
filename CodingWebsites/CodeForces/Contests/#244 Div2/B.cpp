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



int n,t,c;
int k[200000];
int binary_search(int *a,int n,int value);
 
int main(void)
{
	freopen("B.txt","r",stdin); 
	
	while(cin>>n>>t>>c){
		int a;
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			k[i]=a;
		}
		
		sort(k,k+n);
		
		int ANS=binary_search(k,n,t);
		
		OUT1(ANS);
		//if(ANS+1-c>0) printf("%d\n",ANS+1-c);
		//else printf("0\n");
		//for(int i=0;i<n;i++) printf("%d ",k[i]); cout<<endl;
		
		
		
		
		
		
		
		
		
	}
return 0;
}

int binary_search(int *a,int n,int value){//查到小于等于value的最大下标 
	int l=0,r=n,m;
	while(l<=r){
		m=(l+r)>>1;
		if(a[m]<=value&&a[m+1]>value){
			return m;
		}
		//OUT3(l,m,r);
		if(a[m]<=value) l=m+1;
		else r=m-1;
	}
	if(a[0]>value) return -1;
	if(a[n-1]<=value) return n-1;
} 
