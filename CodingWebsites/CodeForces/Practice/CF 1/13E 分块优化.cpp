#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define maxn 100007
using namespace std;
int FloorSqrt(int x){
	int L=1,R=800,M;//[L,R) last <= x
	while((L+1)^R){
		M=(L+R)>>1;
		if(M*M <=x) L=M;
		else R=M;
	}
	return L;
}
int next[maxn];
int qnext[maxn];
int last[maxn];
int step[maxn];
int N,M;
int d,k,r;
void Set(int X){
	int g=X/d,n=g==k?r:d;
	int L=g*d,R=L+n;//[L,R)
	int Next=X+next[X];
	if(Next>=R){
		if(Next>N){
			qnext[X]=N+1;
			step[X]=1;
			last[X]=X;
		}
		else{
			qnext[X]=Next;
			step[X]=1;
			last[X]=X;
		}
	}
	else{
		qnext[X]=qnext[Next];
		last[X]=last[Next];
		step[X]=step[Next]+1;
	}
}
void Init(){
	for(int i=N;i>0;--i) Set(i);
}
void Update(int X){
	int L=X/d*d;
	for(int i=X;i>=L;--i) Set(i);
}
int main(void)
{
	freopen("13E.txt","r",stdin); 
	while(~scanf("%d%d",&N,&M)){
		d=FloorSqrt(N);k=N/d;r=N-k*d+1;
		for(int i=1;i<=N;++i) scanf("%d",&next[i]);
		Init();
		//for(int i=N;i;--i) printf("i=%d next=%d qnext=%d last=%d step=%d\n",i,next[i],qnext[i],last[i],step[i]);
		for(int i=1;i<=M;++i){
			int op,a,b;
			scanf("%d",&op);
			if(op){scanf("%d",&a);
				int ANS=0,PreX=a,I=a;
				while(I<=N){
					ANS+=step[I];
					PreX=last[I];
					I=qnext[I];
				}
				printf("%d %d\n",PreX,ANS);
			}
			else{scanf("%d%d",&a,&b);
				next[a]=b;
				Update(a);
			}
		}
	}
return 0;
}


