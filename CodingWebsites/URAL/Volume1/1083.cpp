#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int main(void)
{freopen("1083.txt","r",stdin); 
	string a;int N;
	cin>>N>>a;
	int k=a.length();
	long long ANS=1;
	while(N>0) ANS*=N,N-=k;
	cout<<ANS<<endl;
return 0;
}








