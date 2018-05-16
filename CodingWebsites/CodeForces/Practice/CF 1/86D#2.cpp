/*
 1996 ms	8600 KB
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define maxn 200001
#define LL long long
using namespace std;
//题目数据 
int n,t,p;
int a[maxn];
//Mo's Algotithm
LL ans[maxn];
struct Interval{
	int L,R,id;
	bool operator <(const Interval &B)const{
		return L/p < B.L/p || L/p == B.L/p && R < B.R;
	}
}I[maxn];
LL RANS;
int Num[1000001];
void Clear(){memset(Num,0,sizeof(Num));RANS=0;}
void Add(LL v){RANS+=((++Num[v]<<1)-1)*v;}
void Remove(LL v){RANS-=((--Num[v]<<1)+1)*v;}
int main(void)
{
	freopen("86D.txt","r",stdin); 
	while(~scanf("%d%d",&n,&t)){
		p = sqrt(n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1;i<=t;++i)
			scanf("%d%d",&I[I[i].id=i].L,&I[i].R);
		//区间排序 
		sort(I+1,I+t+1);
		
		Clear();
		//计算 
		int L=1,R=0;//[L,R]
		for(int i=1;i<=t;++i){
			//修改边界 
			while(R > I[i].R) Remove(a[R--]); 
			while(R < I[i].R) Add(a[++R]);
			while(L < I[i].L) Remove(a[L++]);
			while(L > I[i].L) Add(a[--L]);
			//记录答案 
			ans[I[i].id]=RANS;
		}
		for(int i=1;i<=t;++i) printf("%I64d\n",ans[i]);
	}
return 0;
}

