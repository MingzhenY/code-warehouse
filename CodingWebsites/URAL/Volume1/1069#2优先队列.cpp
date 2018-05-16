#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue> 
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

priority_queue<int, vector<int>, greater<int> > List[7500]; 
void DArc(int from,int to){
	List[from].push(to);
	List[to].push(from);
}

int N;
int d[7500];
int a[7500];
int main(void)
{freopen("1069.txt","r",stdin); 

	int t;memset(d,0,sizeof(d));int N=0;
	while(cin>>t){
		a[N++]=t-1;d[t-1]++;
	}
	For(i,N+1) d[i]++;
	priority_queue<int, vector<int>, greater<int> > Q;
	For(i,N+1){
		if(d[i]<2) Q.push(i); 
	}
	For(i,N){
		int t=Q.top();Q.pop();
		DArc(a[i],t);d[a[i]]--;
		if(d[a[i]]==1) Q.push(a[i]); 
	}
	For(i,N+1){
		printf("%d:",i+1);
		while(!List[i].empty()){
			int t=List[i].top();List[i].pop();
			printf(" %d",t+1);
		}
		cout<<endl;
	}
return 0;
}








