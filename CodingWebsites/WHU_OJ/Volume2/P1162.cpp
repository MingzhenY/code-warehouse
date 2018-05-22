#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
struct Int{
    char a[1002];
    int len;
    Int(){len=1;a[0]=0;}
    Int(char *str){
        len = strlen(str);
        for(int i = 0 ; i < len ; ++i) a[i] = str[len - i - 1] - '0';
    }
    Int operator + (Int B){
        Int C;
        C.len=max(len,B.len);
        for(int i=len;i<C.len;++i) a[i]=0;
        for(int i=B.len;i<C.len;++i) B.a[i]=0;
        
        int d = 0;
        for(int i=0;i<C.len;++i){
            C.a[i]=a[i]+B.a[i]+d;
            d=C.a[i]/10;
            C.a[i]%=10;
        }
        if(d){
            C.a[C.len++]=d;
        }
        return C;
    }
    void Show(){
        for(int i=len-1;i>=0;--i){
            printf("%d",a[i]);
        }
        printf("\n");
    }
};
char num1[1002],num2[1002];
int main(){
    freopen("P1162.txt","r",stdin);
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%s%s",num1,num2);
        Int A(num1),B(num2);
        (A+B).Show();
    }
    
    
    return 0;
}


