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
#define maxn 1000000
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
using namespace std;
int number[maxn<<2];
int N;
void add(int X,int C){
	X+=N-1;number[X]+=C;
	while(X>1) number[X>>=1]+=C;
}
int Left; 
int query(int L,int R){
	int ANS=0;
	for(int s=L+N-2,t=R+N;s^t^1;s>>=1,t>>=1){
		if(~s&1) ANS+=number[s^1];
		if(t&1)  ANS+=number[t^1];
	}
	return ANS;
}

int main(void)
{freopen("1316.txt","r",stdin); 
	N=1;while(N <maxn) N <<=1;
	memset(number,0,sizeof(number));
	char op[20];double ANS=0.0;
	double k;int X,n;
	while(~scanf("%s",op)){
		scanf("%lf",&k);
		X=floorl(k*100.0+0.5);
		switch(op[0]){
			case 'B':add(X+1,1);break;
			case 'D':add(X+1,-1);break;
			case 'S':
				scanf("%d",&n);
				ANS+=0.01*min(query(X+1,N),n);
			break;
		}
		if(op[0]=='Q') break;
	}
	printf("%.2f\n",ANS);
return 0;
}








