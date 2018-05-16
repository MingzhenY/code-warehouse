#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

struct A{
	int d;
	double p;
	A(){}
	A(double p):d(1),p(p){}
	A operator+(const A&B)const{
		A C;
		C.d=d+B.d;
		C.p=p+B.p-p*B.p;
		return C;
	}
	bool operator<(const A&B)const{
		return d <B.d||d==B.d&&p<B.p;
	}
}; 
struct Node{
	A dis;
	int path;
	vector<int> V;
	vector<float> P;
	Node(){
		dis.d=inf;dis.p=0.0;
	}
}node[100000]; 
void Arc(int from,int to,int p){
	node[from].V.push_back(to);
	node[from].P.push_back(p/100.0);
	node[to].V.push_back(from);
	node[to].P.push_back(p/100.0); 
}
queue<int> Q;
void BFS(int i){
	For(j,node[i].V.size()){
		int to=node[i].V[j];
		double p=node[i].P[j];
		if(node[i].dis+A(p)<node[to].dis){
			node[to].dis=node[i].dis+A(p);
			node[to].path=i;
			Q.push(to);
		}
	}
}
int N,M,s,t; 
void F(int i){
	if(i!=node[i].path){
		F(node[i].path);
		printf(" %d",i+1);
	}
}
int main(void)
{freopen("1934.txt","r",stdin); 
	
	while(cin>>N>>M>>s>>t){
		For(i,M){
			int a,b,p;
			scanf("%d%d%d",&a,&b,&p);
			Arc(a-1,b-1,p); 
		}
		For(i,N) node[i].path=i;
		s--,t--;
		Q.push(s);
		node[s].dis.d=0;
		while(!Q.empty()){
			int cnt=Q.front();Q.pop();
			BFS(cnt);
		}
		printf("%d %f\n",node[t].dis.d+1,node[t].dis.p);
		printf("%d",s+1);
		F(t);
		cout<<endl;
		
	}
return 0;
}








