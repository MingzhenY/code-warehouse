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
#define LL int
#define LD long double
#define maxn 1000007
using namespace std;

int n,k,x;
LL V[maxn];//题目数据V 
LL C[maxn];//题目数据C 
int Q[maxn];//排序前：每个L对应的最优R值对应的答案
int Q_RR[maxn]; 
multiset<LL> SV;
multiset<LL> SC; 
multiset<LL>::iterator it;
LD F(int n,int k){
	if(k > n/2) return F(n,n-k);
	LD ANS=0;
	for(int i=n-k+1;i<=n;++i) ANS+=log((LD)(i));
	for(int i=1;i<=k;++i) ANS-=log((LD)(i));
	return exp(ANS);
}
int main(void)
{
	freopen("633E.txt","r",stdin); 
	while(~scanf("%d%d",&n,&k)){
		SV.clear();SC.clear();
		for(int i=1;i<=n;++i) scanf("%d",&x),V[i]=x*100;
		for(int i=1;i<=n;++i) scanf("%d",&C[i]);
		//双指针
		int L,R;//区间--闭区间[L,R] 
		//SV: V的对应于区间[L,R]的多重集合 
		//SC: C的对应于区间[L,R]的多重集合 
		//Q[]:每个L对应的最优答案 
		memset(Q,0,sizeof(Q));
		L=R=1;
		SC.insert(C[1]);
		SV.insert(V[1]);
		
		while(L <= R){
			//第一步：计算[L,R]的答案
			int NewQ = min(*(--(it=SV.end())),*SC.begin());
			bool Flag = NewQ >= Q[L];
			//更新答案 
			if(NewQ > Q[L]) Q_RR[L]=R;
			if(Flag) Q[L]=NewQ;
			
			//更新下标 
			if(Flag && R < n) {
				++R;
				SV.insert(V[R]);
				SC.insert(C[R]);
			}
			else{
				SV.erase(SV.lower_bound(V[L]));
				SC.erase(SC.lower_bound(C[L]));
				++L;
				for(;R>Q_RR[L]&&R>L;){
					SV.erase(SV.lower_bound(V[R]));
					SC.erase(SC.lower_bound(C[R]));
					--R;
				}
			}
		}
		
		//从小到大排序 
		sort(Q+1,Q+n+1);
		//
		
		//计算结果 
		LD ANS=(LD)(0);
		for(int t=1;t<=n-k+1;++t){
			ANS+=F(n-t,k-1)*(LD)Q[t];
		}
		ANS/=F(n,k);
		cout<<fixed<<setprecision(7)<<ANS<<endl;
	}
return 0;
}














