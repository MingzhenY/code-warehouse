#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
using namespace std;
int gcd(LL a,LL b){
    while(b){int t=a%b;a=b;b=t;}
    return a;
}
int main(){
    freopen("P1206.txt","r",stdin);
    int a,b,n;
    while(~scanf("%d%d%d",&a,&b,&n)){
        if(a||b) printf("%s\n",n % gcd(a,b) == 0?"Possible!":"Impossible!");
        else printf("%s\n",!n?"Possible!":"Impossible!");
    }
    return 0;
}


