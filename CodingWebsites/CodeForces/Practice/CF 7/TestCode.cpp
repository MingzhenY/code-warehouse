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
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

int main(void)
{/* 
	freopen("650D.in","w",stdout);
	printf("400000 1\n");
	for(int i=0;i<400000;++i) printf("%d ",rand()|(rand()<<15));printf("\n");
	printf("1 377777\n");*/
	srand(time(NULL));
	for(int i=0;i<10;++i){
		int a=rand();
		OUT2(a+(a&-a),a|(a+1));
	} 
return 0;
}












