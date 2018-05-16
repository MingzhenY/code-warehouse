#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#define maxn 200007
using namespace std;

//Basic
int n,q;
int X[maxn],Y[maxn];
char OP[maxn];

//¿Î…¢ªØ
struct RANK{
	int L;
	bool operator<(const & RANK B){return L < B.L;}
}Rank_U[maxn<<1],Rank_L[maxn<<1];
int nU,nL;
map <int,int> ID_U,ID_L;
void GetRank(){
	nU=nL=0;
	for(int i=0;i<q;++i){
		if(OP[i]=='U'){
			Rank_U[nU++].L=
		}
	}
} 

int main(void)
{
	freopen("555C.txt","r",stdin); 
	while(~scanf("%d%d",&n,&q)){
		int x,y;char op;int ANS;
		for(int i=0;i<q;++i){scanf("%d%d %c",&Y[i],&X[i],&OP[i]);}
	}
return 0;
}

