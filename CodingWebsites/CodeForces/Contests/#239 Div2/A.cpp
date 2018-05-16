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
#define FOR(i,n) for(int (i)=1;(i)<=(n);(i)++)
#define out(i) <<#i<<"="<<i<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

using namespace std;
int max(int a,int b) {return a>b?a:b;}
int min(int a,int b) {return a<b?a:b;}
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int lcm(int a,int b){return a/gcd(a,b)*b;} 

struct casher{
	int people;
	int item[100];
	void ReadIn(void){
		for(int i=0;i<people;i++){
			scanf("%d",&item[i]);
		} 
	}
	int TimeNeeded(void){
		int ans=0;
		for(int i=0;i<people;i++){
			ans+=15+5*item[i];
		}
		return ans;
	} 
};

int main(void)
{
	int n;
	casher C[100];
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&C[i].people);
	}
	int ANS=inf;
	for(int i=0;i<n;i++){
		C[i].ReadIn();
		ANS=min(ANS,C[i].TimeNeeded());
	}
	
	cout<<ANS<<endl;
	
	
	
	
	return 0;
}















