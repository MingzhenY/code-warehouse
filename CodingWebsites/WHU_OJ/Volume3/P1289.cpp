#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char str1[51],str2[51];

int main(){
    freopen("P1289.txt","r",stdin);
    while(~scanf("%s",str1)){
        if(str1[0]=='#') break;
        else scanf("%s",str2);
        int len=strlen(str1);
        int ANS=0;
        for(int i=0;i<len;++i) str1[i]=  str1[i]=='A'?1:
                                        str1[i]=='T'?4:
                                        str1[i]=='C'?2:3;
        for(int i=0;i<len;++i) str2[i]=  str2[i]=='A'?1:
                                        str2[i]=='T'?4:
                                        str2[i]=='C'?2:3;
        for(int i=0;i<len;++i)
            ANS+=str1[i]+str2[i]!=5;
        printf("%d\n",ANS);
    }
    return 0;
}


