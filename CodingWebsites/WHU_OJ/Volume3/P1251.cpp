#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char str1[256],str2[256];
int A[400];
int main(){
    freopen("P1251.txt","r",stdin);
    while(~scanf("%s%s",str1,str2)){
        int Len1=strlen(str1),Len2=strlen(str2),Len = max(Len1,Len2);
        memset(A,0,sizeof(A));
        for(int i = 0 ; i < Len1 ; ++i) A[100 + i] = str1[i] -= '0';
        for(int i = 0 ; i < Len2 ; ++i) str2[i] -= '0';
        int ANS = 1000 ;
        for(int i = 100 - Len2 ; i <= 100 + Len1 ; ++i){
            int L = min(i,100);
            int R = max(i + Len2,100 + Len1);//[L,R)
            bool Fit = true;
            for(int j = L ; j < R ; ++j){
                int J = j - i < Len2 ? str2[j - i] : 0;
                if(A[j] + J > 3) Fit = false;
            }
            if(Fit && R - L < ANS) ANS = R - L;
        }
        printf("%d\n",ANS);
    }
    return 0;
}


