#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 131079
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
using namespace std;
const int VN=65536;
const int Off=32001;
const int Clr=255;//无效状态 
const int Nop=254;//空操作 
struct A{
	int L,R,V;
	A():L(0),R(0),V(0){}
	A(int L,int R,int V):L(L),R(R),V(V){}
};
int value[maxn];
void pushdown(int rt){
	if(value[rt]!=Nop){
		value[rt<<1]=value[rt];
		value[rt<<1|1]=value[rt];
		value[rt]=Nop;
	}
}
void build(int l,int r,int rt){
	if(l==r){
		value[rt]=Clr;
		return;
	}
	value[rt]=Clr;
	int m=(l+r)>>1;
	build(ls);
	build(rs);
}
void setValue(int L,int R,int C,int l,int r,int rt){
	if(L <= l && r <= R){
		value[rt]=C;
		return;
	}
	pushdown(rt);
	int m=(l+r)>>1;
	if(L <= m) setValue(L,R,C,ls);
	if(R >  m) setValue(L,R,C,rs);
}
void pushDownValue(int l,int r,int rt){
	if(l==r) return;
	pushdown(rt);
	int m=(l+r)>>1;
	pushDownValue(ls);
	pushDownValue(rs);
}
int N;
int main(void)
{freopen("1116.txt","r",stdin); 
	while(~scanf("%d",&N)){
		build(1,VN,1);
		for(int i=0;i<N;++i){
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			setValue(Off+a,Off+b-1,c,1,VN,1);
		}
		scanf("%d",&N);
		for(int i=0;i<N;++i){
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			setValue(Off+a,Off+b-1,Clr,1,VN,1);
		}
		pushDownValue(1,VN,1);
		vector<A> ANS;
		int S=0,V,L;
		for(int i=VN;i<(VN << 1);++i){
			if(value[i]!=Clr){
				if(!S){//开始新区间
					V=value[i];
					L=i-VN+1-Off;
					S=1;
				}
				else{
					if(V==value[i]) continue;
					else{//结束旧区间+开始新区间 
						ANS.push_back(A(L,i-VN+1-Off,V));
						V=value[i];
						L=i-VN+1-Off;
						S=1;
					}
				}
			}
			else{
				if(S==1){//结束旧区间 
					ANS.push_back(A(L,i-VN-Off+1,V));
					S=0;
				}
			}
		}
		printf("%d",ANS.size());
		for(int i=0;i<ANS.size();++i){
			printf(" %d %d %d",ANS[i].L,ANS[i].R,ANS[i].V); 
		}
	}
return 0;
}








