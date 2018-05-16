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
#define OUTS(s) cout<<#s<<endl;
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
//#define Debug
using namespace std;

char a[10001];
char b[10001];
int main(void)
{freopen("1027.txt","r",stdin); 
	
	char ch;int ERR=0;//Ã»ÓÐ´íÎó 
	int N=0; 
	while(~scanf("%c",&ch)){
		a[N++]=ch;
	}
	int Bn=0;int B_On=1;
	for(int i=0;i<N;i++){
		if(i+1<N) {
			if(B_On&&a[i]=='('&&a[i+1]=='*') {
				B_On=0;i++;continue;
			}	
			if(!B_On&&a[i]=='*'&&a[i+1]==')'){
				B_On=1;i++;continue;
			}
		}
		if(B_On){
			b[Bn++]=a[i]; 
		}
	}
	ERR=!B_On;
	//For(i,Bn) putchar(b[i]);
	int L=0;
	if(!ERR){
		For(i,Bn){
			if(b[i]=='(') {L++;continue;}
			if(b[i]==')') {L--;if(L <0) {ERR=1;break;}continue;}
			if(L <0) {ERR=1;break;}
			if(!L) continue;
			if(b[i]=='+'||b[i]=='-'||b[i]=='*'||b[i]=='/'||b[i]=='='||b[i]=='\n'||
			b[i]>='0'&&b[i]<='9') continue;
			ERR=1;break;
		}	
	}
	if(L!=0) ERR=1;
	if(ERR) printf("NO\n");
	else printf("YES\n");
return 0;
}








