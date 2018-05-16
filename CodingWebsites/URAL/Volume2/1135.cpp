#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;


int main(void)
{freopen("1135.txt","r",stdin); 
	int N;int ANS=0,COUNT=0;
	char a;
	while(cin>>a){
		if(a=='<') ANS+=COUNT;
		else if(a=='>')COUNT++;
		//OUT3(a,ANS,COUNT);
	}
	cout<<ANS<<endl;	
return 0;
}








