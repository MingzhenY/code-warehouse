#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char str[102];
int main(){
    freopen("P1029.txt","r",stdin);
    while(~scanf("%s",str+1)){
        if(str[1]=='$') break;
        int len=strlen(str+1);
        for(int i=1;i<=len;++i){
            str[i]-='A';
            str[i]=(str[i]+26-i%26)%26;
            str[i]+='A';
        }
        printf("%s\n",str+1);
    }
    return 0;
}


