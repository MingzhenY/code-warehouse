#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(void)
{
	long long n,m;
	while(cin>>n>>m){
		if(n==1) cout<<1<<endl;
		else if(m-1>=n-m) cout<<(m-1)<<endl;
		else cout<<(m+1)<<endl;
	}
return 0;
}

