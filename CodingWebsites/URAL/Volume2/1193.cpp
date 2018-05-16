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

struct Student{
	int T1,T2,T3;
	int D;
	bool operator <(const Student&B)const{
		return T1<B.T1;
	}
}S[40];
int N;
int main(void)
{freopen("1193.txt","r",stdin); 
	while(cin>>N){
		//预处理 
		For(i,N)
			scanf("%d%d%d",&S[i].T1,&S[i].T2,&S[i].T3);
		//排序
		sort(S,S+N);
		//计算
		int Now=0;
		For(i,N){
			if(S[i].T1>Now) Now=S[i].T1;
			Now+=S[i].T2;
			S[i].D=Now;
		}
		int ANS=0;
		For(i,N){
			ANS=max(ANS,S[i].D-S[i].T3);
		}
		//输出 
		cout<<ANS<<endl;
	}
return 0;
}








