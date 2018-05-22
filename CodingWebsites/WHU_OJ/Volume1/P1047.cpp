#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int T;
unsigned int dp[2001][2001];
char str1[2002],str2[2002];
int main(){
    freopen("P1047.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",str1+1,str2+1);
        int len1=strlen(str1+1);
        int len2=strlen(str2+1);
        int MaxLen=0;
        for(int i=1;i<=len1;++i){
            for(int j=1;j<=len2;++j){
                dp[i][j]=str1[i]==str2[j]?dp[i-1][j-1]+1:0;
                MaxLen=max(MaxLen,(int)dp[i][j]);
            }
        }
        printf("%d\n",MaxLen);
    }
    return 0;
}


