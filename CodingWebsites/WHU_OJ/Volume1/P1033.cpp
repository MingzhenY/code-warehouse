#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
using namespace std;
int gcd(int a,int b,int &x,int &y){
    if (b==0){
        x=1,y=0;
        return a;
    }
    int q=gcd(b,a%b,y,x);
    y-=a/b*x;
    return q;
}
bool Test(LL v,LL a,LL b,LL x,LL y){
    x*=v;y*=v;
    if(x > 0){
        int t = x / b;
        x -= t * b;
        y += t * a;
    }
    if(y > 0){
        int t = y / a;
        y -= t * a;
        x += t * b;
    }
    return x >= 0 && y >= 0;
}
int main(){
    freopen("P1033.txt","r",stdin);
    int a,b,m,n;
    while(~scanf("%d%d%d%d",&a,&b,&m,&n)){
        int Max = a * b - a - b;
        if(n >= Max) n = Max;
        int x,y;
        gcd(a,b,x,y);
        int ANS=0;
        for(int i=m;i<=n;++i) ANS+=!Test(i,a,b,x,y);
        printf("%d\n",ANS);
    }
    return 0;
}


