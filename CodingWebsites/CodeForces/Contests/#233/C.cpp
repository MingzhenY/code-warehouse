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
#define  inf  0x3fffffffffffffff
#define FOR(i,n) for(int (i)=1;(i)<=(n);(i)++)
#define out(i) <<#i<<"="<<i<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

using namespace std;
long long max(long long a,long long b) {return a>b?a:b;}



long long a,b; 
long long ANS=-inf;
int PART=1;
void f(int,int);
int T=1;//´ú±íbÏÈ 
int main(void)
{
	cin>>a>>b;
	if(b==0) {ANS=a*a;PART=0;}
	else if(b==1) {ANS=a*a-1;PART=1;}
	else if(a==0) {ANS=-b*b;PART=1;}
	else if(a==1) {ANS=1-b*b;PART=2;}
	else{
		for(int part=2;part<=b;part++){
			if(a<part-1) break;
			long long n=b/part;long long dis=b-n*part;
			long long  Bsum=0;
			for(long long i=1;i<=part;i++){
				if(i<=dis) Bsum+=(n+1)*(n+1);
				else Bsum+= n*n;
			}
			if(((a-part+2)*(a-part+2)+part-2-Bsum)>ANS) {ANS=(a-part+2)*(a-part+2)+part-2-Bsum;PART=part;}
		}
	}
	
	cout<<ANS<<endl;
	OUT1(PART);
	//system("pause");
	int na=1,NB=1,nb=1;
	if(PART) nb=b/PART;int DIS=b-nb*PART;
	while(na<=PART||NB<=PART){
		if(T){
			if(NB<=DIS) f(nb+1,T);
			else if(NB<=PART) f(nb,T);
			T=1-T;NB++;
		}
		else{
			if(na<=PART-1) f(1,T);
			if(na==PART)f(na-PART+1,T);
			T=1-T;
			na++;
		}
	}
	
	
return 0;	
}

void f(int n,int c)
{
	if(c) for(int i=0;i<n;i++) printf("x");
	else for(int i=0;i<n;i++) printf("o");
}













