#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

int N,n;
int d[10];//20¸öÊý×Ö 
int r[7];
void Init(){
	r[0]=3241;r[1]=1324;r[2]=1234;
	r[3]=2341;r[4]=1243;r[5]=1342;r[6]=2134;
}
int main(void)
{freopen("1095.txt","r",stdin); 
	Init();
	cin>>N;
	for(int kkk=0;kkk<N;++kkk){
		string a;cin>>a;n=a.length();
		memset(d,0,sizeof(d));
		for(int i=0;i<n;++i) d[a[i]-'0']++;
		d[1]--;d[2]--;d[3]--;d[4]--;
		long long ANS=0;
		for(int i=9;i>0;--i){while(d[i]>0) {ANS*=10;ANS+=i;d[i]--;}}
		int T;
		for(T=0;T <7;++T){if(((ANS%7)*10000+r[T])%7==0) break;} 
		if(ANS>0) cout<<ANS;
		printf("%d",r[T]);
		for(int i=0;i<d[0];++i) printf("0");
		printf("\n");
	}
return 0;
}








