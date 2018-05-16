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

string M,Key;
int main(void)
{freopen("1236.txt","r",stdin); 
	while(cin>>M>>Key){
		int N=Key.length();
		for(int i=0;i<N-2;i++) {
			if(M[i]<='9')M[i]-='0';
			else if(M[i]<='F') M[i]-='A'-10;
		}
		for(int i=0;i<N;i++){
			if(Key[i]<='9') Key[i]-='0';
			else if(Key[i]<='F') Key[i]-='A'-10;
		}
		char a=2,b=0;
		for(int i=0;i<N/2;i++){
			Key[2*i]^=a;
			Key[2*i+1]^=b;
			a=M[2*i]^Key[2*i];
			b=M[2*i+1]^Key[2*i+1];
		}
		for(int i=0;i<N;i++){
			printf("%X",Key[i]);
		}cout<<endl;
	}
return 0;
}








