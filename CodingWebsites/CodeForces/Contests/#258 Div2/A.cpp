#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
template <class T>
T Min(T a,T b) {
	return a<b?a:b;
}
template <class T>
T Max(T a,T b) {
	return a<b?b:a;
}
int main(void)
{
	freopen("A.txt","r",stdin); 
	int m,n;
	while(cin>>m>>n){
	
	int T=Min(m,n)-1;
	T+=1;
	
	if(T&1) cout<<"Akshat"<<endl;
	else cout<<"Malvika"<<endl;
	}
	
		
return 0;
}














