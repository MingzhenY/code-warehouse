#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1 
using namespace std;
// 
#define K 137
#define maxn 100001 
char str[maxn];
int Pow[maxn];//K的各个次方 
int N,M; 
struct Node{
	int KeyL,KeyR;
	Node():KeyL(0),KeyR(0){}
	void init(){KeyL=KeyR=0;}
}node[maxn<<2];
void PushUp(int L,int R,int rt){
	node[rt].KeyL=node[rt<<1].KeyL+node[rt<<1|1].KeyL*Pow[L];
	node[rt].KeyR=node[rt<<1].KeyR*Pow[R]+node[rt<<1|1].KeyR;
}
void build(int l,int r,int rt){
	if(l==r){
		node[rt].KeyL=node[rt].KeyR=str[l];
		return;
	}
	int m=(l+r)>>1;
	build(ls);
	build(rs);
	PushUp(m-l+1,r-m,rt);
}
void update(int a,char b,int l,int r,int rt){
	if(l==r){
		node[rt].KeyL=node[rt].KeyR=b;
		return;
	}
	int m=(l+r)>>1;
	if(a<=m) update(a,b,ls);
	if(a> m) update(a,b,rs);
	PushUp(m-l+1,r-m,rt);
}
Node query(int L,int R,int l,int r,int rt){
	if(L <=l && r <=R){
		return node[rt];
	}
	Node ANS,ANS1,ANS2;int T=0;
	int m=(l+r)>>1;
	if(L <= m) ANS1=query(L,R,ls),T+=1;
	if(R >m  ) ANS2=query(L,R,rs),T+=2;
	if(T==1){ANS=ANS1;}
	else if(T==2) {ANS=ANS2;}
	else if(T==3) {
		ANS.KeyL=ANS1.KeyL+ANS2.KeyL*Pow[m-max(L,l)+1];
		ANS.KeyR=ANS1.KeyR*Pow[min(R,r)-m]+ANS2.KeyR;
	}
	return ANS;
}

int main(void)
{freopen("1989.txt","r",stdin); 
	while(~scanf("%s",str+1)){
		str[0]='0';N=strlen(str)-1;
		Pow[0]=1;FOR(i,N) Pow[i]=Pow[i-1]*K;
		For(i,maxn<<2) node[i].init();
		scanf("%d",&M);
		build(1,N,1);
		For(i,M){
			char op[20];scanf("%s",op);
			if(op[0]=='c'){
				int a;char b;
				scanf("%d %c",&a,&b);
				update(a,b,1,N,1);
			}
			else{
				int a,b;
				scanf("%d%d",&a,&b);
				Node ANS=query(a,b,1,N,1);
				bool T=ANS.KeyL==ANS.KeyR;
				if(T) printf("Yes\n");
				else printf("No\n");
			}
		} 
	}
return 0;
}








