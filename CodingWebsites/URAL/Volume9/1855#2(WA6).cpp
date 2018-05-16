/*
主体算法没错。是求最后的精度有误差…… 
*/

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
void PushUp(int rt){
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	sumk[rt]=sumk[rt<<1]+sumk[rt<<1|1];
	sumkk[rt]=sumkk[rt<<1]+sumkk[rt<<1|1];
}
void maintain(int l,int r,int rt,LL Add){
	LL D1=(LL) r*(r+1)/2LL - (LL) l*(l-1)/2LL;
	LL D2=(LL) r*(r+1)*(2*r+1)/6LL - (LL) l*(l-1)*(2*l-1)/6LL;
	sum[rt]+=Add*(r-l+1);
	sumk[rt]+=Add*D1;
	sumkk[rt]+=Add*D2;
}
void PushDown(int l,int r,int rt){
	if(add[rt]){
		add[rt<<1]+=add[rt];
		add[rt<<1|1]+=add[rt];
		int m=(l+r)>>1;
		maintain(ls,add[rt]);
		maintain(rs,add[rt]);
		add[rt]=0LL;
	}
}
void build(int l,int r,int rt){
	if(l==r){
		sum[rt]=0LL;
		sumk[rt]=0LL;
		sumkk[rt]=0LL;
		add[rt]=0LL;
		return;
	}
	int m=(l+r)>>1;
	build(ls);
	build(rs);
	PushUp(rt);
}
void update(int L,int R,LL C,int l,int r,int rt){
	if(L <= l && r <= R){
		add[rt]+=C;
		maintain(cnt,C);
		return;
	}
	PushDown(cnt);
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
	PushDown(cnt);
	int m=(l+r)>>1;
	if(L <=m) query(L,R,ls);
	if(R > m) query(L,R,rs);
}
/*
void F(LL a,LL b){
	LL ANS=a/b;a%=b;
	cout<<ANS;
	printf(".");
	For(i,10){
		a*=10;
		printf("%d",a/b);
		a%=b;
	}
	cout<<endl;
}*/
int N,M;
int main(void)
{freopen("1855.txt","r",stdin); 
	while(cin>>N>>M){N--; 
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
				LL D=(b-a)*(b-a+1)/2LL;
				if(D){
					ANS/=D;
					//F(ANS,D);
					cout.setf(ios::fixed);    
					cout.precision(10); 
					cout<<ANS<<endl;	
				}
				else{
					ANS=0.0;
					cout.setf(ios::fixed);    
					cout.precision(10); 
					cout<<ANS<<endl;	
				}
			}
		}
	}
return 0;
}








