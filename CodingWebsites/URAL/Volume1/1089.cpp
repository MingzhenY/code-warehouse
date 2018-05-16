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

struct Word{
	string str;
	int len;
	void Init(){len=str.length();}
	bool operator <(const Word &B)const{return len < B.len;}
}words[207];
int N,n; 
char str[2007];
bool IsLetter(char ch){return ch>='a'&&ch<='z';}
bool Correct(int i,int j){
	for(int k=0;k <N;++k){
		if(j-i+1==words[k].len){
			int T=0;
			for(int t=0;t<words[k].len;++t) T+=(words[k].str[t]==str[i+t]);
			if(T+i==j) {
				//printf("Found Correct Word: %s\n",words[k].a);
				for(int t=0;t<words[k].len;++t) str[i+t]=words[k].str[t];
				return true;
			}
		}
	}
	return false;
}
int main(void)
{freopen("1089.txt","r",stdin); 
	N=0;
	while(~scanf("%s",str)&&str[0]!='#'){
		words[N].str.assign(str);
		words[N].Init();N++;
	}
	n=0;scanf("%*c");
	while(~scanf("%c",&str[n])) ++n;
	int ANS=0;
	for(int i=0;i<n;++i){
		if(!IsLetter(str[i])) continue;
		int j=i;
		while(j+1<n&&IsLetter(str[j+1])) j++;
		if(Correct(i,j))ANS++;
		i=j;
	}
	for(int i=0;i<n;++i) printf("%c",str[i]);
	printf("%d\n",ANS);
return 0;
}








