#include <iostream>
#include <cstdio>
#include <cmath>
#define LL long long
using namespace std;
LL G(LL x){return x*(x-1)*(x-2)/6;}
LL F(LL x,LL L,LL R){return G(x+R)-G(x+L-1);}
LL SolveA(LL a,LL b,LL c,LL l){
	LL ANS=0;
	for(int i=0;i<=l;++i){
		LL X=min(l-i,a-b-c+i);
		if(X>=0) ANS+=(X+1)*(X+2)/2; 
	}
	return ANS;
}
LL Solve(LL a,LL b,LL c,LL l){
	return G(l+3)-SolveA(a,b,c,l)-SolveA(b,a,c,l)-SolveA(c,a,b,l);
}
LL a,b,c,l; 
int main(void)
{
	freopen("571A.txt","r",stdin); 
	while(cin>>a>>b>>c>>l){
		cout<<Solve(a,b,c,l)<<endl;
	}
return 0;
}

