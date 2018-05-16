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
#define C(a,i) a###i;
using namespace std;
#define B(i)  unsigned bit##i:1;
//#define D(1) B(1)
//#define D(n) if((n)>1) { D((n-1)) B(n) } else { B(n) }

 #define TO_STRING( x ) TO_STRING1( x )
   #define TO_STRING1( x ) #x
union A{
	long int a;
	unsigned bit0:1;
	unsigned bit1:2;
	unsigned bit2:3;
	unsigned bit3:1;
	unsigned bit4:1;
	unsigned bit5:1;
	unsigned bit6:1;
	unsigned bit7:1;
	unsigned bit8:1;
	unsigned bit9:1;
	unsigned bit10:1;
	unsigned bit11:1;
	unsigned bit12:1;
	unsigned bit13:1;
	unsigned bit14:1;
	unsigned bit15:1;
	unsigned bit16:1;
	unsigned bit17:1;
	unsigned bit18:1;
	unsigned bit19:1;
	unsigned bit20:1;
	unsigned bit21:1;
	unsigned bit22:1;
	unsigned bit23:1;
	unsigned bit24:1;
	unsigned bit25:1;
	unsigned bit26:1;
	unsigned bit27:1;
	unsigned bit28:1;
	unsigned bit29:1;
	unsigned bit30:1;
	unsigned bit31:1;
	
	bool bit(int n){
		switch(n){
			case 0: return bit0;
			case 1: return bit1;
			case 2: return bit2;
			case 3: return bit3;
			case 4: return bit4;
			case 5: return bit5;
			case 6: return bit6;
			case 7: return bit7;
			case 8: return bit8;
			case 9: return bit9;
			case 10: return bit10;
			case 11: return bit11;
			case 12: return bit12;
			case 13: return bit13;
			case 14: return bit14;
			case 15: return bit15;
			case 16: return bit16;
			case 17: return bit17;
			case 18: return bit18;
			case 19: return bit19;
			case 20: return bit20;
			case 21: return bit21;
			case 22: return bit22;
			case 23: return bit23;
			case 24: return bit24;
			case 25: return bit25;
			case 26: return bit26;
			case 27: return bit27;
			case 28: return bit28;
			case 29: return bit29;
			case 30: return bit30;
			case 31: return bit31;
		}
	}
};

int main(void)
{
	
	A a;
	a.a=1;
	for(int i=0;i<=31;i++) printf("%d: %d\n",i,a.bit(i));
	//OUT1(a.bit1);

	//const char *str TOSTRING(D(32));






return 0;
}












