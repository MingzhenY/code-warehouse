#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <cstring>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
using namespace std;
int N,M;
int main(void)
{freopen("1196.txt","r",stdin); 
	while(cin>>N){
		map<int,bool> P;
		For(i,N){
			int a;
			scanf("%d",&a);
			P[a]=1;
		}
		cin>>M;
		int ANS=0;
		For(i,M){
			int a;
			scanf("%d",&a);
			if(P.count(a)) ANS++;
		}
		cout<<ANS<<endl;
	}
return 0;
}








