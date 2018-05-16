#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
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
    if(a==0){x=0;y=1;return b;}
    else{
		LL tx,ty;
        LL d=exgcd(b%a,a,tx,ty);
        x=ty-(b/a)*tx;
        y=tx;
        return d;
    }
}
struct AP{
	LL A,B;//A+BT
	LL TA,TB;//T=TA+k*TB
	AP():A(0LL),B(0LL),TA(0LL),TB(0LL){}
	AP(LL A,LL B):A(A),B(B),TA(0LL),TB(1LL){}
	AP(LL A,LL B,LL TA,LL TB):A(A),B(B),TA(TA),TB(TB){}
	AP operator +(AP &R){
		AP C;
		LL LCM=lcm(B,R.B);
		if(A==B.A){
			C=AP(A,LCM);
			TA=0;TB=LCM*qPow(B,M-2);
			B.TA=0;B.TB=LCM*qPow(R.B,M-2);
		}
		else{
			
		}
		
		
		return C;
	}
};
struct Node{
	LL A,B,P;
	Node(){}
	Node(LL A,LL B,LL P):A(A),B(B),P(P){}
};
bool ERR; 
vector<Node> K[256];
vector<Node> operator +(vector<Node> &X,vector<Node> &Y){
	vector<Node> ANS;
	int I=X.size(),J=Y.size(),i=0,j=0;
	//OUT2(I,J);
	while(i<I||j<J){//OUT2(i,j);
		if(i==I){
			if(Y[j].A) {ERR=true;return ANS;}
			else {
				ANS.push_back(Y[j]);
				TL.push_back(Node(0,0,Y[j].P));
				//TR.push_back(Node(0));
			}
			++j;
		}
		else if(j==J){
			if(X[i].A) {ERR=true;return ANS;}
			else ANS.push_back(X[i]);
			++i;
		}
		else{
			//OUT2(X[i].P,Y[j].P);
			if(X[i].P == Y[j].P){
				//OUT2(X[i].A,Y[j].A);
				//OUT2(X[i].B,Y[j].B);
				if(X[i].A==Y[j].A){
					ANS.push_back(Node(X[i].A,lcm(X[i].B,Y[j].B),X[i].P));
				}
				else{
					LL A1,B1,T1,A2,B2,T2;
					if(X[i].A>Y[j].A){
						A1=Y[j].A;B1=Y[j].B;
						A2=X[i].A;B2=X[i].B;
					}
					else{
						A1=X[i].A;B1=X[i].B;
						A2=Y[j].A;B2=Y[j].B;
					}
					LL D=A2-A1;
					if(B1==0){ERR=true;return ANS;}
					if(B2==0){
						if(D%B1==0){
							ANS.push_back(Node(A2,0,X[i].P));
							++i;++j;continue;
						}
						else {ERR=true;return ANS;}
					}
					LL GCD=exgcd(B1,B2,T1,T2);
					LL KT;
					if(D%GCD==0) KT=D/GCD;
					else {ERR=true;return ANS;}
					//OUT2(T1,T2);
					T1*=KT;
					//OUT2(T1,T2);
					ANS.push_back(Node(A1+T1*B1,lcm(B1,B2),X[i].P));
				}
			}
			else {
				if(X[i].P < Y[j].P){
					if(X[i].A) {ERR=true;return ANS;}
					else ANS.push_back(X[i]);
				}
				else{
					if(Y[j].A) {ERR=true;return ANS;}
					else ANS.push_back(Y[j]);
				}
			}
			++i;++j;
		}
	}
	
	return ANS;
}
int PA[10],NA[10],An;
int PB[10],NB[10],Bn;
void F(int X,int *Prime,int *Number,int &Pn){
	Pn=0;
	if(X <100000){
		while(X>1){
			Prime[Pn]=maxprime[X];Number[Pn]=0;
			while(X%Prime[Pn]==0) Number[Pn]++,X/=Prime[Pn];
			++Pn;
		}	
	}
	else{
		for(int i=0;i<pn;++i){
			if(X%prime[pn]==0){
				Prime[Pn]=prime[pn];Number[Pn]=0;
				while(X%Prime[Pn]==0) Number[Pn]++,X/=Prime[Pn];
				++Pn;
			}
		}
		if(X>1){
			Prime[Pn]=X;
			Number[Pn]=1;
			++Pn;
		}
	}
}

int n;
int A[101],B[101];

void Build(int l,int r,int rt){
	if(l==r){
		F(A[l],PA,NA,An);
		F(B[l],PB,NB,Bn);
		int AI=0,BI=0;
		while(AI<An||BI<Bn){
			if(AI==An){//¼ÓÈëB 
				K[rt].push_back(Node(0,NB[BI],PB[BI]));
				BI++;continue;
			}
			else if(BI==Bn){
				K[rt].push_back(Node(NA[AI],0,PA[AI]));
				AI++;continue;
			}
			else{
				if(PA[AI]==PB[BI]){
					K[rt].push_back(Node(NA[AI],NB[BI],PA[AI]));
					AI++;BI++;
				}
				else{
					if(PA[AI]<PB[BI]){
						K[rt].push_back(Node(NA[AI],0,PA[AI]));
						AI++;continue;
					}
					else{
						K[rt].push_back(Node(0,NB[BI],PB[BI]));
						BI++;continue;
					}
				}
			}
		}
		return;
	}
	int m=(l+r)>>1;
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
	if(!ERR) K[rt]=K[rt<<1]+K[rt<<1|1];
	OUT2(l,r);
	for(int i=0;i<K[rt].size();++i){
		OUT3(K[rt][i].A,K[rt][i].B,K[rt][i].P);
	}
}
int main(void)
{
	freopen("571E.txt","r",stdin);
	Init();
	while(~scanf("%d",&n)){
		ERR=false;
		for(int i=1;i<=n;++i) scanf("%d%d",&A[i],&B[i]);
		for(int i=0;i<256;++i) K[i].clear();
		Build(1,n,1);
		//OUT1(ERR);
		//for(int i=0;i<K[1].size();++i) OUT3(K[1][i].A,K[1][i].B,K[1][i].P);
		if(ERR) printf("-1\n");
		else{
			LL ANS=1;
			for(int i=0;i<K[1].size();++i) ANS=(ANS*qPow(K[1][i].P,K[1][i].A%(M-1)))%M;
			printf("%I64d\n",ANS);
		}
	}
return 0;
}

