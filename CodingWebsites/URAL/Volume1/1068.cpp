#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(void)
{freopen("1068.txt","r",stdin); 
	int N;int T;
	while(cin>>N){
		if(N<0) T=-1,N=-N;
		else T=1; 
		cout<<(T*N*(N+1)/2+(!~T)+(N==0))<<endl;
	}
return 0;
}








