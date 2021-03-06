/* 暴力（4461ms  900KB）*/ 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 30001
using namespace std;
//题目数据 
int n,m,q;
struct T{
	int A,id;
	bool operator <(const T &B)const{return A < B.A;}
}I[maxn];
int Fibs[maxn];
int ANS[maxn]; 
int Step[maxn];
int Last[maxn];
int L[maxn],R[maxn]; 

int main(void)
{
	freopen("633H.txt","r",stdin); 
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;++i)
			scanf("%d",&I[I[i].id=i].A);
		sort(I+1,I+n+1);
		scanf("%d",&q);
		for(int i=1;i<=q;++i)
			scanf("%d%d",&L[i],&R[i]),ANS[i]=Step[i]=Last[i]=0;;
		Fibs[0]=0;Fibs[1]=1;
		for(int i=2;i<=n;++i) Fibs[i]=(Fibs[i-1]+Fibs[i-2])%m;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=q;++j){
				if(I[i].id < L[j] || I[i].id > R[j] || I[i].A == Last[j]) continue;
				ANS[j]=(ANS[j]+(Last[j]=I[i].A)%m*Fibs[++Step[j]])%m;
			}
		}
		for(int i=1;i<=q;++i) printf("%d\n",ANS[i]);
	}
return 0;
}


