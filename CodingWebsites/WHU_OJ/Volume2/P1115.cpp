#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char str[256];
int getNumber(int a,int b){//[a,b)
    int ANS=0;
    for(int i=a;i<b;++i){
        ANS*=10;
        ANS+=str[i]-'0';
    }
    return ANS;
}
int D26[7];
int main(){
    D26[0]=1;
    for(int i=1;i<=6;++i) D26[i]=26*D26[i-1];
    freopen("P1115.txt","r",stdin);
    while(~scanf("%s",str)){
        int len=strlen(str),L,R;
        for(int i=0;i<len;++i){
            if(str[i]=='C'){
                L=getNumber(1,i);
                R=getNumber(i+1,len);
                break;
            }
        }
        if(!L || !R) break;
        int ABCN=0;
        char ABC[256];
        for(int i=0;i<=6;++i) {
            if(R >= D26[i])  R-=D26[i],++ABCN;
            else break;
        }
        for(int i=ABCN-1;i>=0;--i){
            ABC[i]=R%26;
            R/=26;
        }
        for(int i=0;i<ABCN;++i){
            printf("%c",ABC[i]+'A');
        }
        printf("%d\n",L);
    }
    return 0;
}
