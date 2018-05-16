#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(void)
{
	freopen("A.txt","r",stdin); 
	int a,b;
	while(cin>>a>>b){
		int i;
		for(i=1;;i++){
			a--;
			if(i%b==0) a++;
			if(!a) break;
		}
		cout<<i<<endl;
		
	} 
return 0;
}














