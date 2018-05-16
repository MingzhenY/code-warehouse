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
#include <cstring>
#define  inf  0x7fffffff
#define FOR(i,n) for(long long  (i)=1;(i)<=(n);(i)++)
#define out(i) <<#i<<"="<<i<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

using namespace std;
int  min(int  a,int  b) {return a<b?a:b;}
int  n,k;
int  a[1001];
int d[1001];


int  main(void)
{
//	cout<<inf<<endl; 
	cin>>n>>k;
	memset(d,0,sizeof(d));
	FOR(i,n) {
		scanf("%d",&a[i-1]);
	}
	for(int i=0;i<n;i++){
		if(a[i]>i*k)  d[a[i]-i*k]++;
	}
	
	int  D;
	
	int  ANS=0; 
	for(int  i=1;i<=1000;i++){
		
		if(ANS<d[i]){
			D=i;
			ANS=d[i];
		}
	}
	//cout<<"D="<<D<<endl;
	/* 
	
	int  l=1,r=inf;
	while(true){
		//cout<<"~D="<<D<<endl;
		int  m=(l+r)>>1;
	//OUT3(m,l,r);
		int  D1,D2;
		D1=f(m+1)-f(m);
		D2=f(m-1)-f(m);
		if(D1>=0&&D2>=0||l==r)  {
			D=m;
			//cout<<"~D="<<D<<endl;
			break;
		}
		if(D1>0) {
			r=m;
			continue;
		}
		if(D2>0){
			l=m;
			continue;
		}
	}
	
	if(f(D+1)<=f(D)) D++;
	if(f(D-1)<f(D)&&D>1) D--;
	
	
	*/ 
	//cout<<"D="<<D<<endl;
	
	
	int  all=0;
	for(int  i=0;i<n;i++){
		all+=(a[i]!=i*k+D);
	}
	cout<<all<<endl;
	for(int  i=0;i<n;i++){
		int  temp=i*k+D-a[i];
		if(temp>0) printf("+ %d %d\n",i+1,temp);
		if(temp<0) printf("- %d %d\n",i+1,-temp);
	}



return 0;
}












