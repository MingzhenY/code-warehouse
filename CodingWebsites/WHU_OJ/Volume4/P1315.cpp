#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
using namespace std;

LL Pow(LL a,LL k,LL m){
    LL ANS=1;
    while(k){
        if(k&1) ANS=ANS*a%m;
        a=a*a%m;
        k>>=1;
    }
    return ANS;
}
int main(){
    freopen("P1315.txt","r",stdin);
    int a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c)&&(a||b||c)){
        printf("%d\n",int(Pow(a,b,c)));
    }
    return 0;
}


