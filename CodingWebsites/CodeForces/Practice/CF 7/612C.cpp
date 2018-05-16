#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

char str[1000007];
int match[1000007];
int S[1000007],SP;
bool isL(char ch){
	return ch=='['||ch=='('||ch=='<'||ch=='{';
}
int main(void)
{
	freopen("612C.txt","r",stdin); 
	while(~scanf("%s",&str)){
		int n=strlen(str);
		int ANS=0,ERR=0;
		SP=0;
		for(int i=0;i<n;++i){
			if(isL(str[i])) S[++SP]=i;
			else{
				int V=S[SP--];//[V,i]
				if(SP < 0){ERR=1;break;}
				ANS+=str[V]=='('&&str[i]!=')'||
				     str[V]=='{'&&str[i]!='}'||
					 str[V]=='['&&str[i]!=']'||
					 str[V]=='<'&&str[i]!='>';
			}
		}
		if(ERR||SP) printf("Impossible\n");
		else printf("%d\n",ANS);
	}
	return 0;
}

