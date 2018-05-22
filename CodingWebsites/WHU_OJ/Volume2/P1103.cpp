#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
    freopen("P1103.txt","r",stdin);
    int N,T;
    char str[8];
    scanf("%d",&T);
    for(int i=0;i<T;++i){
        scanf("%s",str);
        if(str[1]=='%') N = (str[0]-'0');
        else if(str[2]=='%') N = (str[0]-'0')*10+(str[1]-'0');
        else N = 100;
        long double p = N/100.0;
        long double ANS=p*p/(p*p+(1-p)*(1-p));
        printf("%.2f%%\n",(double)ANS*100);
    }
    return 0;
}


