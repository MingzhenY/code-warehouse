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
int w[300];

int main(void)
{int n,i,j,all=0;
cin>>n;
for(i=0;i<n;i++) {scanf("%d",&w[i]);all+=w[i];}
int cur=0;
if(w[cur]>0) {printf("P");w[cur]--;all--;} 
while(all){
int M=0; 

if(cur>0) for (j=cur-1;j>=0;j--) {
				if(w[j]!=0) {
				for(i=0;i<cur-j;i++) printf("L");
				printf("P");
				w[j]--;M=1;cur=j;all--;
						} 	
				 }
if(M==1) {M--;continue;}
if(cur<n-1) for (j=cur+1;j<n;j++) {
				if(w[j]!=0) {
					for(i=0;i<j-cur;i++) printf("R");
					printf("P");
					w[j]--;M=1;cur=j;all--;
						} 	
				 }
if(M==1) {M--;continue;}

if(cur>0&&w[cur]>0){ printf("LRP");w[cur]--;M=1;all--;}
if(M==1) {M--;continue;}
if(cur<n-1&&w[cur]>0){ printf("RLP");w[cur]--;M=1;all--;}
if(M==1) {M--;continue;}
M=0;
}



return 0;
}
