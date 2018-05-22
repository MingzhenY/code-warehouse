#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct Int{
    char a[500];
    int len;
    Int(){len=1;a[0]=0;}
    Int(int num){
        if(!num) Int();
        else{
            len=0;
            while(num){
                a[len++]=num%10;
                num/=10;
            }
        }
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
int main(){
    freopen("P1036.txt","r",stdin);
    Int DP[501];
    DP[1]=Int(1);
    DP[2]=Int(2);
    DP[3]=Int(4);
    for(int i=4;i<=500;++i) DP[i]=DP[i-1]+DP[i-2]+DP[i-3];
    
    int n;
    while((cin>>n)&&n)
        DP[n].Show();
    return 0;
}


