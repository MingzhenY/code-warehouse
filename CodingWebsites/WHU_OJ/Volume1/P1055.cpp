#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
string str;
char msg[1024];
int main(){
    freopen("P1055.txt","r",stdin);
    int T=0;
    while(gets(msg)){
        if(++T%3==2){
            int len=strlen(msg);
            for(int i=0;i<len;++i){
                if(isupper(msg[i])){
                    msg[i]-='A';
                    msg[i]=(msg[i]+26-5)%26;
                    msg[i]+='A';
                }
            }
            printf("%s\n",msg);
        }
    }
    return 0;
}


