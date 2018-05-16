#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 320000
#define LL long long
using namespace std;
int maxprime[maxn],minprime[maxn];
LL P[maxn],Pn;//质数表 
map<LL,int> K;//n-Kn对照表 
map<LL,int> J;//n-对应的最大J值。 
void Init(){
	memset(maxprime,Pn=0,sizeof(maxprime));
	for(int i=2;i<maxn;++i){
		if(maxprime[i]) continue;
		P[++Pn]=i;
		for(int j=i;j<maxn;j+=i){
			maxprime[j]=i;
			if(!minprime[j]) minprime[j]=i;
		}
	}
}
int GetK(LL n){//找到最小的k使得P[k]^2 > n 
	int L=1,R=Pn,M;
	while(L^R){
		M = (L+R) >> 1;
		if(P[M]*P[M] <= n) L = M + 1;
		else R = M;
	} 
	return L;
}/*
void GetALL(LL n,LL j){//找到所有的n值 
	if(1==n || 1==j) return;
	if(P[j] > n) return;
	//此时n有效,记录下来 
	//OUT2(n,j);
	if(!K.count(n)) K[n]=GetK(n);
	else return;
	if(K.size()>1000000) return;
	//判断递归 
	for(int t=K[n];t>1;--t){
		GetALL(n,t-1);
		GetALL(n/P[t-1],t-1);
	}
}
 
queue<LL> Q;
void GetALL(LL n){
	while(!Q.empty()) Q.pop();
	Q.push(n);
	//OUT1(Q.size());
	while(!Q.empty()){
		LL cnt = Q.front();Q.pop();
		//OUT1(cnt);
		int k = K[cnt]=GetK(cnt);
		for(int j=k - 1;j > 0;--j){
			LL v = cnt/P[j];
			//OUT3(cnt,P[j],v);
			//system("pause");
			if(v > 1 && !K.count(v)) {
				Q.push(v);
				K[v]=GetK(v);
			}
		}
	}
}*/ 

int PI(int n){
	for(int i=1;i<=Pn;++i){
		if(P[i]>n) return i-1;
	}
	return -1;
}
int Simple_F(LL n,int k){
	int ANS=1;
	for(int i=2;i<=n;++i) ANS+=minprime[i]>=P[k];
	return ANS;
}
int main(void)
{
	//freopen("665F.txt","r",stdin); 
	Init();
	//OUT1(GetK(50));
	K.clear();
	LL n = 100000000000LL;
	GetALL(n);
	OUT1(K.size());
return 0;
}














