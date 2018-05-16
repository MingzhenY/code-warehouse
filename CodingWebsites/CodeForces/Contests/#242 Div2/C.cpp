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
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

using namespace std;
int max(int a,int b) {return a>b?a:b;}
int min(int a,int b) {return a<b?a:b;}
int zdgys(int a,int b){int t;if(a<b) {t=a;a=b;b=t;} while(b){t=a;a=b;b=t%b;}return a;} 
int zxgbs(int a,int b){return a/zdgys(a,b)*b;}


int quickxor(int a,int b){
	if(b==0) return 0;
	if(b==1) return a;
	if(b==2) return a^a;
	int t=quickxor(a,b>>1);
	if(b&1) return a^t^t;
	else return t^t;
}

int quickxorTo(int n){
	 int a=0;
	 n--;
	 switch(n%4){
	 	case 0: return n;
	 	case 1: return 1;
	 	case 2: return n+1;
	 	case 3: return 0;
	 }
	 
} 
int fact(int a,int b){
	if(b==1) return 0;
	int m=0;
	//for(int i=1;i<b;i++){
	//	m^=i;
	//}
	m=quickxorTo(b);
	int d=a%b;
	int ANS=0;
	//for(int i=1;i<=d;i++){
	//	ANS^=i;
	//}
	ANS=quickxorTo(d+1);
	
	return ANS^quickxor(m,a/b);
	
}

int main(void)
{
	/*
	OUT1(quickxorTo(20));
	int m=0;
	for(int i=1;i<20;i++){
		m^=i;
	}
	OUT1(m);
	OUT1(16^17^18^19);
	return 0;*/ 
//	int er=0;
//	for(int i=1;i<30;i++){
//		er^=i;
//		OUT2(er,quickxorTo(i+1));
//	}
//	return 0; 
	freopen("C.txt","r",stdin); 
	int n;
	cin>>n;
	int d=0,e;
	for(int i=0;i<n;i++){
		scanf("%d",&e);
		d^=e;
	}
	for(int i=1;i<=n;i++){
		d^=fact(n,i);
	}
	cout<<d <<endl;
	
return 0;
}














