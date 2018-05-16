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

int A[37];
void Modify(char *str){
	while(*str){
		if(*str>='A') *str-='A'-10-'0';
		++str;
	}
}
void F(char *str,int k){//k进制 
	int Cnt=0;//计数 
	int S=0; //0:非数字  1:数字
	while(*str){
		if(*str< k+'0'&&S==0) ++Cnt,S=1;
		if(*str>=k+'0'&&S==1) S=0;
		++str;
	}
	A[k]+=Cnt;
}
char str[1049576];
int main(void)
{freopen("1179.txt","r",stdin); 
	memset(A,0,sizeof(A));
	while(~scanf("%s",str)){
		Modify(str);
		for(int i=2;i<=36;++i){
			F(str,i);
		}
	}
	int K=2,ANS=A[2];
	for(int i=3;i<=36;++i){
		if(A[i]>ANS){
			ANS=A[i];
			K=i;
		}
	}
	printf("%d %d\n",K,ANS);
return 0;
}








