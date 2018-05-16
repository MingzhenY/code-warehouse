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

char ch[107];
int dp[107][107];
int op[107][107];
void Show(int i,int j){
	if(~op[i][j]){
		if(op[i][j]){//positive value : split at op[i][j]
			Show(i,op[i][j]);
			Show(op[i][j]+1,j);
		}
		else{//op[i][j]=0 :add the one that matches
			if(ch[i]=='('||ch[i]==')') printf("()");
			else printf("[]");
		}
	}
	else{//op[i][j] = -1 £ºch[i] and ch[j] matches 
		printf("%c",ch[i]);
		if(i+1!=j) Show(i+1,j-1);
		printf("%c",ch[j]);
	}
}
int main(void)
{freopen("1183.txt","r",stdin); 
	while(~scanf("%s",ch+1)){
		int n=strlen(ch+1);
		for(int i=n;i>0;--i){
			for(int j=i;j<=n;++j){
				if(i==j){
					dp[i][j]=1;
					op[i][j]=0;//0 means add the one that matches
					continue;
				}
				int K=i,ANS=dp[i][K]+dp[K+1][j];
				for(int k=K+1;k <j;++k){
					if(dp[i][k]+dp[k+1][j]<ANS){
						ANS=dp[i][k]+dp[k+1][j];
						K=k;
					}
				}
				dp[i][j]=ANS;op[i][j]=K;//positive value means to split at op[i][j] 
				if(ch[i]=='['&&ch[j]==']'||ch[i]=='('&&ch[j]==')'){
					if(i+1==j){
						dp[i][j]=0;
						op[i][j]=-1;
					}
					else if(dp[i+1][j-1]<dp[i][j]) {
						dp[i][j]=dp[i+1][j-1];
						op[i][j]=-1;//-1 means ch[i] and ch[j] matches
					}
				}
			}
		}
		//OUT1(dp[1][n]); 
		Show(1,n);
		printf("\n");
	} 
return 0;
}


