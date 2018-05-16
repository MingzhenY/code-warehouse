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



int n,m; 
int k[100];

int main(void)
{
	freopen("A.txt","r",stdin); 
	
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) scanf("%d",&k[i]);
		int sum=0,ANS=0,t=0;
		S:
		sum=0;
		while(sum+k[t]<=m&&t<n){
			sum+=k[t++];
		}
		ANS++;
		if(t<n) goto S;
		/*
		for(int i=0;i<n;i++){
			
			
			
			if(i==n-1) {ANS++;break;}
			
			if(sum<=m&&sum+k[i]>m) {
				ANS++;sum=k[i];
			}
			else {
				sum+=k[i];
			}
		}
		*/
		printf("%d\n",ANS);
		
		
		
		
		
		
		
		
		
		
		
		

return 0;
}














