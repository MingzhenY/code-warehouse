#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int count[26];
int n;
char a[50007];
char b[2700];
bool Step1(){
	for(int i=0;i<26;++i){
		if(count[i]>=100){
			for(int j=0;j<100;++j) printf("%c",'a'+i);
			printf("\n");
			return true;
		}
	}
	return false;
}
int dp[2600][2600];
int path[2600][2600][3];
char pal[2700];
int main(void)
{
	freopen("335B.txt","r",stdin); 
	while(~scanf("%s",a)){
		memset(count,0,sizeof(count));
		memset(path,0,sizeof(path));
		memset(pal,0,sizeof(pal));
		int n=strlen(a);//printf("%d\n",n);
		for(int i=0;i<n;++i) count[a[i]-'a']++;
		if(Step1()) continue;
		for(int i=0;i<n;++i) b[i]=a[n-i-1];
		if(a[0]==b[0]){
			dp[0][0]=1;
			path[0][0][0]=0;
			path[0][0][1]=0;
			path[0][0][2]=a[0];
		}
		else{dp[0][0]=0;}
		for(int i=1;i<n;++i){
			if(a[0]==b[i]){
				dp[0][i]=1;
				path[0][i][0]=0;
				path[0][i][1]=i;
				path[0][i][2]=a[0];
			}
			else{
				dp[0][i]=dp[0][i-1];
				path[0][i][0]=0;
				path[0][i][1]=i-1;
				path[0][i][2]=0;
			}
			if(a[i]==b[0]){
				dp[i][0]=1;
				path[i][0][0]=i;
				path[i][0][1]=0;
				path[i][0][2]=a[i];
			}
			else{
				dp[i][0]=dp[i-1][0];
				path[i][0][0]=i-1;
				path[i][0][1]=0;
				path[i][0][2]=0;
			}
		}
		for(int i=1;i<n;++i){
			for(int j=1;j<n;++j){
				if(a[i]==b[j]){
					dp[i][j]=dp[i-1][j-1]+1;
					path[i][j][0]=i-1;
					path[i][j][1]=j-1;
					path[i][j][2]=a[i];
				}
				else{
					if(dp[i][j-1]>dp[i-1][j]){
						dp[i][j]=dp[i][j-1];
						path[i][j][0]=i;
						path[i][j][1]=j-1;
						path[i][j][2]=0;
					}
					else{
						dp[i][j]=dp[i-1][j];
						path[i][j][0]=i-1;
						path[i][j][1]=j;
						path[i][j][2]=0;
					}
				}
			}
		}
		//printf("×î³¤Îª£º%d\n",dp[n-1][n-1]);
		int I=n-1,J=n-1;
		int N=0;
		while(1){
			if(path[I][J][2]) pal[N++]=path[I][J][2];
			int X=path[I][J][0],Y=path[I][J][1];
			if(X==I&&Y==J) break;
			I=X;J=Y;
		}
		if(N>100){
			for(int i=0;i<50;++i) printf("%c",pal[i]);
			for(int i=N-50;i<N;++i) printf("%c",pal[i]);
			printf("\n");
		}
		else{
			printf("%s\n",pal);
		}
	}
return 0;
}














