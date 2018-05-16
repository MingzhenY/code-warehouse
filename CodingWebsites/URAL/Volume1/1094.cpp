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

char sc[81];int P;
void SetP(int &P){
	if(P>=80) P=0;
	if(P<0) P=0;
}
int main(void)
{freopen("1094.txt","r",stdin); 
	
	P=0;For(i,80) sc[i]=' ';sc[80]='\0';
	char a;//int count=0;
	while(scanf("%c",&a)==1){
		if(a=='\n') continue;
		//count++;if(count>50) break;printf("%d:",count);
		switch(a){
			case '<':P--;break;
			case '>':P++;break;
			default:sc[P++]=a;break;
		} 
		SetP(P);
		//for(int i=0;i<80;i++) printf("%c",sc[i]);
		//cout<<endl;
		
	}
	for(int i=0;i<80;i++) printf("%c",sc[i]);
	cout<<endl;
return 0;
}








