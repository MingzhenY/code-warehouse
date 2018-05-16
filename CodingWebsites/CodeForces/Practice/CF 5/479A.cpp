#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a,b,c;
int main(void)
{
	freopen("479A.txt","r",stdin); 
	int d[8];
	while(cin>>a>>b>>c){
		d[0]=(a+b)+c;
		d[1]=(a+b)*c;
		d[2]=(a*b)+c;
		d[3]=(a*b)*c;
		d[4]=a+(b+c);
		d[5]=a+(b*c);
		d[6]=a*(b+c);
		d[7]=a*(b*c);
		int ANS=d[0];
		for(int i=1;i<8;++i) if(d[i]>ANS) ANS=d[i];
		cout<<ANS<<endl;
	}

		
return 0;
}














