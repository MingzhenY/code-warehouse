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

bool check1(char a,int depth);
bool check2(int depth);
bool Check(int depth);

int main(void)
{freopen("1027.txt","r",stdin); 
	char a;int ERR=0;//没有错误 
	while(~scanf("%c",&a)){
		if(a=='(') ERR+=Check(0);
	}
	if(ERR) printf("NO\n");
	else printf("YES\n");
return 0;
}
bool Check(int depth){
	#ifdef Debug
	For(i,depth) printf("\t") ;OUTS(Check);
	#endif
	char a;int ERR=0;
	scanf("%c",&a);
	if(a=='*'){
		ERR+=check2(depth+1);
	}
	else{
		ERR+=check1(a,depth+1);
	}
	#ifdef Debug
	OUT1(ERR); 
	For(i,depth) printf("\t") ;OUTS(EndCheck);
	#endif
	return ERR;
	
}
bool check1(char a,int depth){//读到 右括号为止， 
	#ifdef Debug
    For(i,depth) printf("\t") ;
    #endif
	int ERR=0,end=0;char last;int start=0;
	do{
		if(a=='(') {
			ERR+=Check(depth+1);
			continue;
		}
		if(!start){
			start=1;
			if(a=='*')start=2;
		}
		if(a==')'){
			end=1;
			if(start==2&&last=='*') ERR=1;
			break;
		}
		
		if(a=='+'||a=='-'||a=='*'||a=='/'||a=='='||a=='\n'||
		a<='9'&&a>='0') ;
		else ERR++;
		last=a;
	}while(~scanf("%c",&a));
	#ifdef Debug
	OUT2(end,ERR);
	For(i,depth) printf("\t") ;OUTS(end1);
	#endif
	return !end||ERR;
}
bool check2(int depth){//读到  *) 为止 
	#ifdef Debug
	For(i,depth) printf("\t") ;OUTS(start2);
	#endif
	char a;int end=0;
	while(~scanf("%c",&a)){
		int T=0;
		start:
		if(a=='*'){
			char b;
			if(~scanf("%c",&b)){
				if(b==')') {
					end=1;break;
				}
				if(b=='*') {
					a=b;goto start;
				}
			}
		}
		
	}
	#ifdef Debug
	OUT1(!end);
	For(i,depth) printf("\t") ;OUTS(end2);
	#endif
	return !end;
}







