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

string s;


int main(void)
{int c_n=0,c_e=0,c_i=0,c_t=0;
	cin>>s;
	FOR(i,s.length()){
		switch(s[i-1])
		{
			case 'n': c_n++;break;
			case 'e': c_e++;break;
			case 'i': c_i++;break;
			case 't': c_t++;break; 
		}
	}
	
	cout<<min((c_n-1)/2,min(c_e/3,min(c_i,c_t)))<<endl; 




return 0;
}















