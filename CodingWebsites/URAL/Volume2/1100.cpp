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

struct A{
	int ID,M;
	bool operator <(const A&B)const{
		return M>B.M;
	}
}a[150000];
int N;
int main(void)
{freopen("1100.txt","r",stdin); 
	cin>>N;
	For(i,N){
		scanf("%d%d",&a[i].ID,&a[i].M);
	}
	stable_sort(a,a+N);
	For(i,N){
		printf("%d %d\n",a[i].ID,a[i].M);
	}
	
	
return 0;
}








