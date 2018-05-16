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
char str[10000007];
bool vis[7];//0~6
int N,n;
void shift(){
	for(int i=6;i>0;--i) vis[i]=vis[i-1];
}
void F(int k){
	vis[0]=false;
	if(k>=5&&vis[5]){
		if(	str[k-5]=='p'&&
			str[k-4]=='u'&&
			str[k-3]=='t'&&
			str[k-2]=='o'&&
			str[k-1]=='n'||
			str[k-5]=='i'&&
			str[k-4]=='n'&&
			str[k-3]=='p'&&
			str[k-2]=='u'&&
			str[k-1]=='t'
		)
			vis[0]=true;
	}
	if(k>=3&&vis[3]){
		if(	str[k-3]=='o'&&
			str[k-2]=='u'&&
			str[k-1]=='t'||
			str[k-3]=='o'&&
			str[k-2]=='n'&&
			str[k-1]=='e'
		)
			vis[0]=true;
	}
	if(k>=6&&vis[6]){
		if(	str[k-6]=='o'&&
			str[k-5]=='u'&&
			str[k-4]=='t'&&
			str[k-3]=='p'&&
			str[k-2]=='u'&&
			str[k-1]=='t'
		)
			vis[0]=true;
	}
	if(k>=2&&vis[2]){
		if( str[k-2]=='i'&&
			str[k-1]=='n'
		)
			vis[0]=true;
	}
}
int main(void)
{freopen("1102.txt","r",stdin); 
	while(~scanf("%d",&N)){
		for(int i=0;i<N;++i){
			scanf("%s",str);n=strlen(str);
			memset(vis,0,sizeof(vis));
			vis[1]=true;
			for(int j=1;j<n;++j) {
				F(j);
				shift();
			}
			F(n);
			if(vis[0]) printf("YES\n");
			else printf("NO\n");
		}	
	}
return 0;
}








