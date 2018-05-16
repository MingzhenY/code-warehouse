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
using namespace std;

int p[1000001];
//int np[80000];int Np;
int I,J; 
int P[8],num[8],N;
int Power(int a,int b){
	int ANS=1;
	For(i,b) ANS*=a;
	return ANS;
}
int dfs(int i,int mul,int Target){
	if(i==N)  {
		//printf("\t\tend:mul:%d\n",mul);
		if(Target==mul) return 0;
		else return mul; 
	}
	int ANS=0;
	for(int j=0;j<=num[i];j++){
		ANS+=dfs(i+1,mul*Power(P[i],j),Target);
	}
	return ANS;
}
double Tri(int t){
	int ALL=t;
	if(t>1000000) return 0;
	N=0;memset(num,0,sizeof(num));
	int T=1;
	while(t>1){
		for(int i=0;i<N;i++){
			if(p[t]==P[i]) {
				num[i]++;
				T=0;
				break;	
			}
		}
		if(T){
			P[N]=p[t];
			num[N]=1;
			N++;
		}
		t/=p[t];
	}
	//OUT1(ALL);
	//for(int i=0;i<N;i++){
		//printf("\tp:%d num:%d\n",P[i],num[i]);
	//}
	//OUT1(dfs(0,1));
	
	return (double) dfs(0,1,ALL)/ALL;
}
int main(void)
{freopen("1118.txt","r",stdin); 
	
	memset(p,-1,sizeof(p));//Np=0;
	for(int i=2;i<1000001;i++){
		if(~p[i]) continue;
		for(int j=i;j<1000001;j+=i){
			p[j]=i;
		}
	}
	//OUT3(Tri(1),Tri(2),Tri(3));
	while(cin>>I>>J){
		double ANS=Tri(J);int ANSI=J;
		for(int i=I;i<=J;i++){
			double D=Tri(i);
			if(D <ANS) ANS=D,ANSI=i;
		}
		cout<<ANSI<<endl;
	}
return 0;
}








