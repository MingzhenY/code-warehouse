#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
string str;
int main(void)
{
	freopen("514A.txt","r",stdin); 
	while(cin>>str){
		for(int i=1;i<str.length();++i) str[i]=min((int)str[i],(int) (105-str[i]));
		if(str[0]!=57) str[0]=min((int)str[0],(int)(105-str[0]));
		long long x=str[0]-48;
		for(int i=1;i<str.length();++i) x*=10,x+=str[i]-48;
		cout<<x<<endl;
	}

		
return 0;
}














