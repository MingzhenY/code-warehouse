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

int N,M,P; 
int d[26];
void ReadLine(int k){
	string str;
	cin>>str;
	for(int i=0;i<str.length();++i) d[str[i]-'A']+=k;
}
int main(void)
{freopen("1164.txt","r",stdin); 
	while(cin>>N>>M>>P){
		memset(d,0,sizeof(d));
		for(int i=0;i<N;++i){
			ReadLine(1);
		}
		for(int i=0;i<P;++i){
			ReadLine(-1);
		}
		for(int i=0;i<26;++i){
			for(int j=0;j<d[i];++j){
				cout<<(char)('A'+i);
			}
		}
		cout<<endl;
	}
return 0;
}








