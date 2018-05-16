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




long long N; 
int main(void)
{
	cin>>N;
	long long x=-N,y=0;
	long long ANS=0;
	while(x<0){
		if(x*x+(y+1)*(y+1)<=N*N) {ANS++;y++;continue;}
		if((x+1)*(x+1)+(y+1)*(y+1)<=N*N){ANS++;x++;y++;continue;}
		if((x+1)*(x+1)+y*y<=N*N){ANS++;x++;continue;}
	}
	ANS=4*ANS;
	cout<<ANS<<endl;

return 0;
}















