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
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define out(i) <<#i<<"="<<i<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
vector <int> str;



int main(void)
{int n=4;
//sort(str,str+n);
str.push_back(7);
str.push_back(6);
str.push_back(5);
str.push_back(4);
str.push_back(3);
str.push_back(2);
str.push_back(1);
vector <int>::iterator it=::find(str.begin(),str.end(),1);

		if(it==str.end()) printf("NO!\n");
		else cout<<str.end()-it;
		
		
//for(int i=0;i<n;i++) cout<<str[i]<<endl;

return 0;
}
