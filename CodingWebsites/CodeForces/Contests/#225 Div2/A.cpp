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
using namespace std;
int max(int a,int b) {return a>b?a:b;}
int min(int a,int b) {return a<b?a:b;}
int zdgys(unsigned int a,unsigned int b){while(a){if(a<b){a=a^b;b=a^b;a=a^b;}  a=a%b;}return (int)b;} 
int zxgbs(int a,int b){return (a*b)/zdgys(a,b);}
int main(void)
{
	int N;
	cin>>N;
	if(N%2==1){
	cout<<(N*N+1)/2<<endl;
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if((i+j)%2==0) printf("C");
			else printf(".");				
		}
		printf("\n");
	}
	
	
	
	
	
	}
	else{
	cout<<(N*N)/2<<endl;
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if((i+j)%2==0) printf("C");
			else printf(".");				
		}
		printf("\n");
	}
	
}


return 0;
}
