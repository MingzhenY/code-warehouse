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

int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int main(void)
{freopen("1197.txt","r",stdin); 
	int N;
	cin>>N;
	For(i,N){
		string a;
		cin>>a;
		int x=a[0]-'a',y=a[1]-49;
		int ANS=0;
		For(j,8){
			int nx=x+dx[j],ny=y+dy[j];
			if(nx>=0&&nx<8&&ny>=0&&ny<8) ANS++;
		}
		cout<<ANS<<endl;
	}
return 0;
}








