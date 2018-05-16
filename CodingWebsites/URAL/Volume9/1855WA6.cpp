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
using namespace std;
double sum[maxn<<2];
double sumk[maxn<<2];
double sumk2[maxn<<2];
double add[maxn<<2];
void maintain(int l,int r,int rt,double Add){
	double D1=(double) r*(r+1)/2.0 - (double)l*(l-1)/2.0 ;
	double D2=(double)r*(r+1)*(2*r+1)/6.0 - (double)l*(l-1)*(2*l-1)/6.0 ;
	sum[rt]+=Add*(r-l+1);
	sumk[rt]+=Add*D1;
	sumk2[rt]+=Add*D2;
}
void PushUp(int l,int r,int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	sumk[rt]=sumk[rt<<1]+sumk[rt<<1|1];
	sumk2[rt]=sumk2[rt<<1]+sumk2[rt<<1|1];
}

void PushDown(int l,int r,int rt){
	int m=(l+r)>>1;
	if(add[rt]){
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		maintain(ls,add[rt]);
		maintain(rs,add[rt]);
		add[rt]=0;
	}
}
void update(int L,int R,double C,int l,int r,int rt){
	if(L <=l && r <=R){
		add[rt]+=C;
		maintain(l,r,rt,C);
		return;
	}
	int m=(l+r)>>1;
	PushDown(l,r,rt);
	if(L <= m) update(L,R,C,ls);
	if(R >  m) update(L,R,C,rs);
	PushUp(l,r,rt);
}
double S,SK,SK2;
void query(int L,int R,int l,int r,int rt){
	if(L <=l && r <=R){
		S+=sum[rt];
		SK+=sumk[rt];
		SK2+=sumk2[rt];
		return;
	}
	int m=(l+r)>>1;
	PushDown(l,r,rt);
	if(L <=m) query(L,R,ls);
	if(R > m) query(L,R,rs);
}
int N,M;
int main(void)
{freopen("1855.txt","r",stdin); 
	while(cin>>N>>M){
		memset(sum,0,sizeof(sum));
		memset(add,0,sizeof(add));
		memset(sumk,0,sizeof(sumk));
		memset(sumk2,0,sizeof(sumk2));
		FOR(q,M){
			char s[20];scanf("%s",s);
			if(s[0]=='c'){
				int a,b,c;
				scanf("%d%d%d",&a,&b,&c);
				update(a,b-1,(double)c,1,N-1,1);
			}
			else{
				int a,b;
				scanf("%d%d",&a,&b);
				double ANS=0;S=0;SK=0;SK2=0;
				query(a,b-1,1,N-1,1);
				ANS=(1.0-a)*b*S+(a+b-1)*SK-SK2;
				ANS/=(b-a+1)*(b-a)/2.0;
				printf("%.10f\n",ANS);
			}
		}
	}
return 0;
}








