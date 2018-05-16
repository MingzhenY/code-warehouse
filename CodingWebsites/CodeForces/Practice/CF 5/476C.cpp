#include <iostream>
#include <cstdio>
using namespace std;
#define M 1000000007LL
long long Plus(long long a,long long b){return ((a%M)+(b%M))%M;}
long long mul(long long a,long long b){return ((a%M)*(b%M))%M;}
long long F(long long a,long long b){
	return mul(Plus(mul(a*(a+1)/2,b),a),b*(b-1)/2);
}
int main(void)
{
	freopen("476C.txt","r",stdin); 
	long long a,b;
	while(cin>>a>>b){
		cout<<F(a,b)<<endl;
	}
return 0;
}














