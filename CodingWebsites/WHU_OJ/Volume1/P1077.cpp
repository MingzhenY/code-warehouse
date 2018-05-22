#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char str[201];
int DP[201][201];// [i,j)

int main(){
    freopen("P1077.txt","r",stdin);
    while(~scanf("%s",str)){
        int len=strlen(str);
        for(int i=0;i<len;++i){
            str[i] =str[i]=='('?1:
                    str[i]==')'?8:
                    str[i]=='['?2:
                    str[i]==']'?7:
                    str[i]=='{'?3:
                    str[i]=='}'?6:
                    str[i]=='<'?4:5;
        }
        
        for(int i=len-1;i>=0;--i){
            for(int j=i+1;j<=len;++j){
                if(i+1==j) DP[i][j]=1;
                else if(i+2==j) DP[i][j]=str[i]+str[j-1]==9&&str[i]<str[j-1]?0:2;
                else{
                    DP[i][j]=1<<30;
                    for(int k=i+1;k<j;++k) //[i,k)+[k,j)
                        DP[i][j]=min(DP[i][j],DP[i][k]+DP[k][j]);
                    
                    if(str[i]+str[j-1]==9&&str[i]<str[j-1])
                        DP[i][j]=min(DP[i][j],DP[i+1][j-1]);
                }
            }
        }
        printf("%d\n",DP[0][len]);
    }
    return 0;
}


