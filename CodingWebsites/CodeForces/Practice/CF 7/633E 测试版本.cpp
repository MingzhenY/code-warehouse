#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include<iomanip>
#include <cstring>
#include <algorithm>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define LL long long
#define LD long double
#define maxn 1000007
using namespace std;

int n,k,x;
LL V[maxn];//题目数据V 
LL C[maxn];//题目数据C 
LL Q[maxn];//排序前：每个L对应的最优R值对应的答案
LL Q_R[maxn]; 
multiset<LL> SV,MV;
multiset<LL> SC,MC; 
multiset<LL>::iterator it;
LD F(int n,int k){
	if(k > n/2) return F(n,n-k);
	LD ANS=0;
	for(int i=n-k+1;i<=n;++i) ANS+=log((LD)(i));
	for(int i=1;i<=k;++i) ANS-=log((LD)(i));
	return exp(ANS);
}
void G(int L){//给定L找R 
	SC.clear();SV.clear();
	
	for(int R = L;R <= n;++R){
		SV.insert(V[R]);
		SC.insert(C[R]);
		LL NewQ = min(*(--(it=SV.end())),*SC.begin());
		if(L==2) {
			OUT2(*(--(it=SV.end())),*SC.begin());
			OUT2(R,NewQ);
		}
		if(NewQ >= Q[L]) Q[L] = NewQ , Q_R[L]=R;
		//else break;
	}
} 
int main(void)
{
	freopen("633E.txt","r",stdin); 
	while(~scanf("%d%d",&n,&k)){
		SV.clear();SC.clear();
		for(int i=1;i<=n;++i) scanf("%d",&x),V[i]=x*100;
		for(int i=1;i<=n;++i) scanf("%d",&x),C[i]=x;
	
		memset(Q,0,sizeof(Q));
		for(int i=1;i<=n;++i) G(i),OUT3(i,Q_R[i],Q[i]);
	
		
		//从小到大排序 
		sort(Q+1,Q+n+1);
		
		//计算结果 
		LD ANS=(LD)(0);
		for(int t=1;t<=n-k+1;++t){
			OUT3(t,F(n-t,k-1),(LD)Q[t]);
			ANS+=F(n-t,k-1)*(LD)Q[t];
		}
		ANS/=F(n,k);
		cout<<fixed<<setprecision(7)<<ANS<<endl;
	}
return 0;
}














