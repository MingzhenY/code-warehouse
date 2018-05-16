#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
int N,K;
int main(void)
{freopen("1194.txt","r",stdin); 
	cin>>N>>K;
	int Cur,M;
	map<int,int> Q;
	Q[1]=N;long long ANS=0;
	while(cin>>Cur>>M){
		int temp=Q[Cur];Q.erase(Cur);
		For(i,M){
			int id,num;
			cin>>id>>num;
			temp-=num;
			ANS+=temp*num;
			Q[id]=num;
		}
	}
	 cout<<ANS<<endl;
return 0;
}








