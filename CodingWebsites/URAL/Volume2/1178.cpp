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

struct P{
	int x,y;
	int id;
	P(){}
	P(int x,int y,int id):x(x),y(y),id(id){}
	bool operator <(const P &B)const{
		return x < B.x || x == B.x && y < B.y;
	}
}D[10001];
int n;
int main(void)
{freopen("1178.txt","r",stdin); 
	ios::sync_with_stdio(false);
	while(cin>>n){
		int x,y;
		for(int i=0;i<n;++i){
			cin>>x>>y;
			D[i]=P(x,y,i+1);
		}
		sort(D,D+n);
		for(int i=0;i<n;++i){
			if(i&1) cout<<D[i].id<<endl;
			else cout<<D[i].id<<" "; 
		}
		
	}
return 0;
}








