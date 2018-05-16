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






int main(void)
{
	freopen("A.txt","r",stdin); 
	int n ;
	while(cin>>n){
		
		string a;int ANS=0;
		cin>>a;
		int low=0,high=0;
		for(int i=0;i<a.length();i++){
			if(a[i]>'Z') low++;
			else high++; 
		}
		if(high>low){
			int k=high-low;int cur=0;k/=2;
			ANS=k;
			while(k>0){
				if(a[cur++]<='Z') a[cur-1]+=32,k--;
				if(cur>=a.length()) break;
			}
			
		}
		else if(high<low){
			int k=low-high;int cur=0;k/=2;ANS=k;
			while(k>0){
				if(a[cur++]>'Z') a[cur-1]-=32,k--;
				if(cur>=a.length()) break;
			}
		}
		
		
		printf("%d\n",ANS);
		cout<<a<<endl;
		
		
		
	}
return 0;
}














