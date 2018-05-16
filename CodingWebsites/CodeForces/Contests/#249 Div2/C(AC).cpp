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
#define out(i) <<#i<<"="<<i<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

using namespace std;
int max(int a,int b) {return a>b?a:b;}
int min(int a,int b) {return a<b?a:b;}
int zdgys(int a,int b){while(b){int t=a;a=b;b=t%b;}return a;} 
int zxgbs(int a,int b){return a/zdgys(a,b)*b;}



int N;
char B[2000][1000];
int H,L;
int k[1000];
int main(void)
{
	freopen("C.txt","r",stdin); 
	cin>>N;L=0,H=0;int up=0,down=0;
	
	for(int i=0;i<N;i++) {
		scanf("%d",&k[i]),L+=k[i];
		if(i%2){
			H-=k[i];
		}
		else{
			H+=k[i];
		}
		if(H>up) up=H;
		if(H<down) down=H;
	}
	H=up-down;if(N==1) H=up;
	for(int i=0;i<H;i++) for(int j=0;j<L;j++) B[i][j]=' ';
	
	int X=up-1,Y=0;int count=1;
	B[X][Y]='/';
	while(count<k[0]) B[--X][++Y]='/',count++;
	int t=1;
	while(t<N){
		if(t%2){
			B[X][++Y]='\\';count=1;
			while(count<k[t]) B[++X][++Y]='\\',count++;
		}
		else{
			B[X][++Y]='/';count=1;
		while(count<k[t]) B[--X][++Y]='/',count++;
		}
		t++;
	}
	for(int i=0;i<H;i++) {
		for(int j=0;j<L;j++) printf("%c",B[i][j]);
		printf("\n");
	}
//	printf("%d %d\n",H,L);
	
	
	
return 0;
}














