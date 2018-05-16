#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[2001];
char p[501];
int A[2001];
int DP[2001][2001];
int main(void)
{
	freopen("476E.txt","r",stdin); 
	while(~scanf("%s%s",s,p)){
		int ns=strlen(s),np=strlen(p);
		//A[i]表示，从i开始，要完成一个 p 至少需要连续多少字符(包含i)，-1表示不可能。
		
		for(int i=0;i<ns;++i){
			int state=0;
			A[i]=-1;
			for(int j=i;j<ns;++j){
				if(s[j]==p[state]) state++;
				if(state==np) {
					A[i]=j-i+1;
					break;
				}
			}
		}
	
		memset(DP,0,sizeof(DP));
		for(int i=0;i<ns;++i){
			for(int j=0;j<=i;++j){
				if(DP[i][j]>DP[i+1][j]) DP[i+1][j]=DP[i][j];
				if(DP[i][j]>DP[i+1][j+1])DP[i+1][j+1]=DP[i][j];
				if(~A[i]){
					if(DP[i][j]+1>DP[i+A[i]][j+A[i]-np]) DP[i+A[i]][j+A[i]-np]=DP[i][j]+1;
				}
			}
		}
		printf("%d",DP[ns][0]);
		for(int i=1;i<=ns;++i){
			printf(" %d",DP[ns][i]);
		}
		printf("\n");
	} 

		
return 0;
}














