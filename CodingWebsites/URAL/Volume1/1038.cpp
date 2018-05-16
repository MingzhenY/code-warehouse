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
char str[20007];
bool Is_Letter(int i){return str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z';}
bool Is_End_of_Sentence(char i){return str[i]=='.'||str[i]=='!'||str[i]=='?';}
int Check_Word(int L,int R){
	int ANS=0;
	//for(int i=L;i<=R;++i) printf("%c",str[i]);
	//printf("  :");
	//OUT3(L,R,ANS);
	for(int i=L+1;i<=R;++i){
		if(str[i]>='A'&&str[i]<='Z') ANS++;
	}
	
	return ANS;
} 
int Check_Sentence(int L,int R){//[L,R]
	int ERR=0;
	for(int i=L;i<=R;++i){
		if(Is_Letter(i)){
			if(str[i]>='a'&&str[i]<='z') ERR++;
			break;
		}
	}
	//¾ä×Ó·Ö´Ê
	for(int i=L;i<=R;++i){
		if(Is_Letter(i)){
			int j=i;
			while(j<R&&Is_Letter(j+1)) j++;
			ERR+=Check_Word(i,j);
			i=j;
		}
	}
	return ERR;
}
int Check_ALL(int L,int R){
	int ANS=0;
	for(int i=L;i<=R;++i){
		if(str[i]=='.'||str[i]=='?'||str[i]=='!'||i==R) {
			ANS+=Check_Sentence(L,i);
			//OUT3(Check_Sentence(L,i),L,i); 
			L=i+1;
		}
	}
	return ANS;
}
int main(void)
{freopen("1038.txt","r",stdin); 
	int n=0;
	while(~scanf("%c",&str[n]))  ++n;
	printf("%d\n",Check_ALL(0,n-1));
return 0;
}








