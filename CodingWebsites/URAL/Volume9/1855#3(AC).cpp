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
#define maxn 100005
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1 
#define cnt l,r,rt
#define LL long long
using namespace std;
LL sum[maxn<<2];
LL sumk[maxn<<2];
LL sumkk[maxn<<2];
LL add[maxn<<2];
LL multi[maxn<<2][3];
void PushUp(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	sumk[rt]=sumk[rt<<1]+sumk[rt<<1|1];
	sumkk[rt]=sumkk[rt<<1]+sumkk[rt<<1|1];
}
void maintain(int rt,LL Add){
	sum[rt]+=Add*multi[rt][0];
	sumk[rt]+=Add*multi[rt][1];
	sumkk[rt]+=Add*multi[rt][2];
}
void PushDown(int rt){
	if(add[rt]){
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		maintain(rt<<1,add[rt]);
		maintain(rt<<1|1,add[rt]);
		add[rt]=0LL;
	}
}
void build(int l,int r,int rt){
	if(l==r){
		sum[rt]=0LL;
		sumk[rt]=0LL;
		sumkk[rt]=0LL;
		add[rt]=0LL;
		multi[rt][0]=1;
		multi[rt][1]=(LL)r;
		multi[rt][2]=(LL)r*r;
		return;
	}
	int m=(l+r)>>1;
	build(ls);
	build(rs);
	PushUp(rt);
	For(i,3){
		multi[rt][i]=multi[rt<<1][i]+multi[rt<<1|1][i];
	}
}
void update(int L,int R,LL C,int l,int r,int rt){
	if(L <= l && r <= R){
		add[rt]+=C;
		maintain(rt,C);
		return;
	}
	PushDown(rt);
	int m=(l+r)>>1;
	if(L <=m) update(L,R,C,ls);
	if(R > m) update(L,R,C,rs);
	PushUp(rt);
}
LL S,SK,SKK;
void query(int L,int R,int l,int r,int rt){
	if(L <= l && r <= R){
		S+=sum[rt];
		SK+=sumk[rt];
		SKK+=sumkk[rt];
		return;
	}
	PushDown(rt);
	int m=(l+r)>>1;
	if(L <=m) query(L,R,ls);
	if(R > m) query(L,R,rs);
}

int N,M;
int main(void)
{freopen("1855.txt","r",stdin); 
	while(cin>>N>>M){
		build(1,N,1);
		FOR(q,M){
			char s[50];scanf("%s",s);
			if(s[0]=='c'){
				int a,b,c;
				scanf("%d%d%d",&a,&b,&c);
				update(a,b-1,(LL)c,1,N,1);
			}
			else{
				int a,b;
				scanf("%d%d",&a,&b);
				S=0LL;SK=0LL;SKK=0LL;
				query(a,b-1,1,N,1);
				double ANS=-SKK+((LL)a+b-1)*SK+(LL)b*(1-a)*S;
				LL D=(LL) (b-a)*(b-a+1)/2LL;
				ANS/=D;
				printf("%.10f\n",ANS); 	
			}
		}
	}
return 0;
}







