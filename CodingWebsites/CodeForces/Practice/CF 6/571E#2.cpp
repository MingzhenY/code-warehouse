#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#define out(i) #i<<"="<<i<<" "
#define OUT1(x) cout<< out(x) <<endl;
#define OUT2(x,y) cout<< out(x) << out(y) <<endl;
#define OUT3(x,y,z) cout<< out(x) out(y) out(z)  <<endl;
#define LL long long 
#define M 1000000007 
#define maxn 107
using namespace std;
int maxprime[100000];
int prime[10000],pn;
LL gcd(LL a,LL b){while(b){LL t=a%b;a=b;b=t;}return a;}
LL lcm(LL a,LL b){return (a/gcd(a,b)*b)%(M-1);}
LL qPow(LL x,LL k){
	LL ANS=1;
	while(k){
		if(k&1) ANS=(ANS*x)%M;
		x=(x*x)%M;
		k>>=1;
	}
	return ANS;
}
void Init(){
	memset(maxprime,-1,sizeof(maxprime));pn=0;
	for(int i=2;i<100000;++i){
		if(~maxprime[i]) continue;
		if(i<32000) prime[pn++]=i;
		for(int j=i;j<100000;j+=i) maxprime[j]=i;
	}
}
LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if(!b){x=1;y=0;return a;}
    else{
		LL tx,ty;
        LL d=exgcd(b,a%b,tx,ty);
        x=ty;
        y=tx-(a/b)*ty;
        return d;
    }
}
bool ERR;
struct AP{
	LL A,B;//A+BT
	AP():A(0LL),B(1LL){}
	AP(LL A,LL B):A(A),B(B){}
	bool Invalid(){return !~A&&!~B;}
	AP operator +(AP R){
		AP &L=(*this);
		if(L.Invalid()||R.Invalid()) {ERR=true;return AP(-1,-1);}
		AP ANS;
		if(L.A==R.A){
			if(L.B&&R.B) return AP(L.A,lcm(L.B,R.B));
			else return AP(L.A,0);
		}
		if(L.B&&R.B){//都不为0,扩展欧几里得 
			LL x,y;
			LL D=exgcd(L.B,R.B,x,y),K=(R.A-L.A)/D;
			if((R.A-L.A)%D) {ERR=true;return AP(-1,-1);}
			while(x<0||y>0){x+=R.B;y-=L.B;}
			return AP((L.A+x*L.B)%(M-1),lcm(L.B,R.B));
		}
		else{//有0 
			if(!L.B&&R.B&&L.A>R.A&&(L.A-R.A)%R.B==0){return AP(L.A,0);}
			if(L.B&&!R.B&&R.A>L.A&&(R.A-L.A)%L.B==0){return AP(R.A,0);}
			ERR=true;return AP(-1,-1);
		}
	}
	void show(){
		printf("(%d,%d)\n",A,B);
	}
};
map<LL,LL> AX,BX;
void F(int X,map<LL,LL> &MP){
	MP.clear();
	if(X <100000){
		Fast:
		while(X>1){
			LL Prime=maxprime[X],D=0;
			while(X%Prime==0) D++,X/=Prime;
			MP[Prime]+=D;
		}	
	}
	else{
		for(int i=0;i<pn;++i){
			if(X%prime[pn]==0){
				LL Prime=maxprime[X],D=0;
				while(X%Prime==0) D++,X/=Prime;
				MP[Prime]+=D;
			}
			if(X<100000) goto Fast;
		}
		if(X>1){
			MP[X]++;
		}
	}
}


int n;
int A[101],B[101];
map<LL,AP> MP[256];
void PushUp(int rt){
	map<LL,AP> &L=MP[rt<<1],&R=MP[rt<<1|1];
	AP T;
	map<LL,AP>::iterator i=L.begin(),j=R.begin();
	while(i!=L.end()||j!=R.end()){
		if(i==L.end()){
			while(j!=R.end()){++j;}
		}
		else if(j==R.end()){
			while(i!=L.end()){
				AP ANS=AP(0,0)+(i->second);
				if((i->second).B) T=T+AP((ANS.A-(i->second).A)/(i->second).B,ANS.B/(i->second).B);
				++i;
			}
		}
		else{
			if(i->first==j->first){
				AP ANS=(i->second)+(j->second);
				if((i->second).B) T=T+AP((ANS.A-(i->second).A)/(i->second).B,ANS.B/(i->second).B);
				++i;++j;
			}
			else if(i->first < j->first){
				AP ANS=AP(0,0)+(i->second);
				if((i->second).B) T=T+AP((ANS.A-(i->second).A)/(i->second).B,ANS.B/(i->second).B);
				++i;
			}
			else{
				AP ANS=AP(0,0)+(j->second);
				++j;
			}
		}
	}
	MP[rt].clear();
	i=L.begin(),j=R.begin();
	while(i!=L.end()||j!=R.end()){
		if(i==L.end()){
			while(j!=R.end()){
				MP[rt][j->first]=AP((j->second).A+T.A*(j->second).B,(j->second).B*T.B);
				++j;
			}
		}
		else if(j==R.end()){
			while(i!=L.end()){
				MP[rt][i->first]=AP((i->second).A+T.A*(i->second).B,(i->second).B*T.B);
				++i;
			}
		}
		else{
			if(i->first==j->first){
				MP[rt][i->first]=AP((i->second).A+T.A*(i->second).B,(i->second).B*T.B);
				++i;++j;
			}
			else if(i->first < j->first){
				MP[rt][i->first]=AP((i->second).A+T.A*(i->second).B,(i->second).B*T.B);
				++i;
			}
			else{
				MP[rt][j->first]=AP((j->second).A+T.A*(j->second).B,(j->second).B*T.B);
				++j;
			}
		}
	}
}
void Build(int l,int r,int rt){
	if(l==r){
		F(A[l],AX);
		F(B[l],BX);
		map<LL,LL>::iterator i=AX.begin(),j=BX.begin();
		MP[rt].clear();
		while(i!=AX.end()||j!=BX.end()){
			if(i==AX.end()){
				while(j!=BX.end()){
					MP[rt][j->first]=AP(0,j->second);
					++j;
				}
			}
			else if(j==BX.end()){
				while(i!=AX.end()){
					MP[rt][i->first]=AP(i->second,0);
					++i;
				}
			}
			else{
				if(i->first == j->first){
					MP[rt][i->first]=AP(i->second,j->second);
					++i;++j;
				}
				else if(i->first < j->first){
					MP[rt][i->first]=AP(i->second,0);
					++i;
				}
				else{
					MP[rt][j->first]=AP(0,j->second);
					++j;
				}
			}
		}
		return;
	}
	int m=(l+r)>>1;
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
	if(!ERR) PushUp(rt);
	map<LL,AP>::iterator k=MP[rt].begin();
	OUT2(l,r);
	while(k!=MP[rt].end()){
		OUT3(k->first,(k->second).A,(k->second).B);
		++k;
	}
} 
int main(void)
{
	freopen("571E.txt","r",stdin);
	Init();
	while(~scanf("%d",&n)){
		ERR=false;
		for(int i=1;i<=n;++i) scanf("%d%d",&A[i],&B[i]);
		Build(1,n,1);
		if(ERR) printf("-1\n");
		else{
			LL ANS=1;
			map<LL,AP>::iterator i=MP[1].begin();
			while(i!=MP[1].end()){
				ANS=(ANS*qPow(i->first,(i->second).A))%M;
				++i;
			}
			printf("%lld\n",ANS);
		}
		
	}
return 0;
}

