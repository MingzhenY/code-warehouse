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

int a[1000][32]; 
int n,q,ANS;
void setbinary(int ,int ,int );
int getbinary(int ,int );
void query(void);

int main(void)
{
//	freopen("C.txt","r",stdin);
	cin>>n;
	int t;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&t);
			setbinary(i,j,t);
		}
	}
	query();
	/*
	//输出矩阵。 
	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<getbinary(i,j)<<" ";
		}
		cout<<endl;
	}
	*/
	cin>>q;
	for(int i=0;i<q;i++){
		int a,b;
		scanf("%d",&a);
		if(a==3) {
			printf("%d",ANS);
		}
		else {
			scanf("%d",&b);
			ANS=1-ANS;
		}
	}
	
	
	
	
	return 0;
}


void setbinary(int x,int y,int t){
	if(t) {
		a[x][y>>5] |= 1<<(y&31) ;//变成1 
	}
	else {
		a[x][y>>5] &= ~( 1<<(y&31) );//变成0 
	}
}
int getbinary(int x,int y){
	return ( a[x][y>>5]>>(y&31) )&1;
} 
void query(void){
	int sum=0;
	for(int i=0;i<n;i++){
			sum+=getbinary(i,i);
	}
	ANS=sum&1;
}











