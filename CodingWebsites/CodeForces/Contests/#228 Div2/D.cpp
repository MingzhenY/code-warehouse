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
#define MAX 100001 
int maxprime[MAX]={};int chain;
void PrePrimes(void);
vector <int> Primes(int);vector <int> primes;
vector <int> con[1000];
void Dfs(int,int,int,int,int);
int main(void)
{
	
PrePrimes();

int k;int sum=0;int i,j;

cin>>k; 
if(k==1) {cout<<"NY\nYN";return 0;}
primes=Primes(k);
for(i=0;i<primes.size();i++) sum+=primes[i];
int N=sum+2;
Dfs(0,0,1,2,primes[0]);

cout<<N<<endl; 
for(i=0;i<N;i++) 
{
for(j=0;j<N;j++)
	{vector <int>::iterator it=::find(con[i].begin(),con[i].end(),j);
		if(it==con[i].end()) printf("N");
		else printf("Y");
	}
printf("\n");
}

return 0;
}
void Dfs(int k,int ls,int ln,int rs,int rn)
{
for(int i=ls;i<ls+ln;i++) for(int j=rs;j<rs+rn;j++)
{
con[i].push_back(j);
con[j].push_back(i);
}

if(rs==1&&rn==1) return;
if(k+1==primes.size()) Dfs(k+1,rs,rn,1,1);
 else  Dfs(k+1,rs,rn,rs+rn,primes[k+1]);
}



vector <int> Primes(int k)
{vector <int>  _primes;int T;
if(k==1) return _primes;
if(k%2==0) {T=2;_primes=Primes(k/T);_primes.push_back(T);return _primes;}
if(k<MAX) 
	{
	T=maxprime[k];
	_primes=Primes(k/T);_primes.push_back(T);return _primes;
	}
for(int i=3;i<MAX;i+=2)
	if(i==maxprime[i]&&k%i==0) {T=i;_primes=Primes(k/T);_primes.push_back(T);return _primes;}
T=k;_primes=Primes(k/T);_primes.push_back(T);return _primes;
}
void PrePrimes(void)
{
for(int i=1;i<MAX;i++) 	{if(i==1) {maxprime[i]=1;continue;}
			if(maxprime[i]!=0) continue;
			for(int j=i;j<MAX;j+=i) maxprime[j]=i;
			}
}
