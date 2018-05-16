#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define K 137
using namespace std;
char str[50][21];
int n,m;
int F(int x){
	int ANS=0;
	while(x) ANS+=x&1,x>>=1;
	return ANS;
}
double M(int x){
	double ANS=1.0;
	for(int i=0;i<x;++i) ANS/=m-i;
	return ANS;
}
double C(int N,int M){
	double ANS=0;
	for(int i=2;i<=N;++i) ANS+=log2(i);
	for(int i=2;i<=M;++i) ANS-=log2(i);
	for(int i=2;i<=N-M;++i)ANS-=log2(i);
	return ANS;
}
queue<int>Q;double DANS=0.0;
bool Inq[1<<20];
int BFS(int x){
	int ANS[50];
	memset(ANS,0,sizeof(ANS));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if((x>>j)&1) ANS[i]*=K,ANS[i]+=str[i][j];
		}
	}
	int T=0;
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			if(ANS[i]==ANS[j]) {
				T=1;break;
			}
		}
		if(T) break;
	}
	if(T){
		for(int j=0;j<m;++j){
			int Next=x|(1<<j);
			Q.push(Next);
		}
	}
	else{
		DANS+=M(F(x))*F(x);
		OUT3(M(F(x)),F(x),M(F(x))*F(x));
	}
}
int main(void)
{
	freopen("E.txt","r",stdin); 
	while(~scanf("%d",&n)){
		for(int i=0;i<n;++i) scanf("%s",str[i]);
		m=strlen(str[0]);
		memset(Inq,0,sizeof(Inq));
		while(!Q.empty()) Q.pop();
		Q.push(0);DANS=0.0;Inq[0]=1;
		while(!Q.empty()){
			int cnt=Q.front();Q.pop();
			BFS(cnt);
		}
		printf("%.10f\n",DANS);
	}
	
	
return 0;
}














