//#include <iostream>
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
#define maxn 151
using namespace std;
int  W[maxn][maxn],n;
int Lx[maxn],Ly[maxn];
int Left[maxn];
bool S[maxn],T[maxn];

bool match(int i){
	S[i]=true;
	for(int j=1;j<=n;j++) if(Lx[i]+Ly[j]==W[i][j]&&!T[j]){
		T[j]=true;
		if(!Left[j]||match(Left[j])){
			Left[j]=i;
			return true;
		}
	}
	return false;
}
void update(){
	int a=1<<30;
	for(int i=-1;i<=n;++i) if(S[i]) 
		for(int j=1;j<=n;j++) if(!T[j])
			a=min(a,Lx[i]+Ly[j]-W[i][j]);
	for(int i=1;i<=n;i++){
		if(S[i]) Lx[i]-=a;
		if(T[i]) Ly[i]+=a;
	}
}
void KM(){
	for(int i=1;i<=n;++i){
		Left[i]=Lx[i]=Ly[i]=0;
		for(int j=1;j<=n;++j)
			Lx[i]=max(Lx[i],W[i][j]);
	}
	for(int i=1;i<=n;++i){
		for(;;){
			for(int j=1;j<=n;++j) S[j]=T[j]=0;
			if(match(i)) break;else update();
		}
	}
}

int main(void)
{freopen("1076.txt","r",stdin); 
	while(~scanf("%d",&n)){
		int sum=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				scanf("%d",&W[i][j]),sum+=W[i][j];
		KM();
		int Max=0;
		for(int i=1;i<=n;++i) Max+=W[Left[i]][i];	
		printf("%d\n",sum-Max);
	}
return 0;
}








