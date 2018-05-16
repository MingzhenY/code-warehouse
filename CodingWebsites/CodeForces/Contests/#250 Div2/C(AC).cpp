#include <iostream>
#include <cstdio>
#include <cmath>
#include<algorithm>
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
using namespace std;
struct Node{
	int v;//¼ÛÖµ
	int n; 
	int order;
	Node():v(0),n(0),order(0){}
}N[1001];
int n,m;
bool cmp1(Node A,Node B) {return A.v>B.v;}
bool cmp2(Node A,Node B) {return A.n<B.n;}
int main(void)
{
	freopen("C.txt","r",stdin); 	
	while(cin>>n>>m){
		FOR(i,n) scanf("%d",&N[i].v),N[i].n=i;
		//FOR(i,n) OUT2(N[i].v,i);
		sort(N+1,N+n+1,cmp1);
		FOR(i,n) N[i].order=i;
		sort(N+1,N+n+1,cmp2);
		int ANS=0;
		FOR(i,m){
			int a,b;
			scanf("%d%d",&a,&b);
			if(N[a].order>N[b].order) ANS+=N[a].v;
			else ANS+=N[b].v;			
		}
		cout<<ANS<<endl;
	}	
return 0;
}














