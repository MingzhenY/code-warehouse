#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
    freopen("P1296.txt","r",stdin);
    int n;
    while(~scanf("%d",&n)&&n){
        if(n&1) printf("%d\n",n-1);
        else printf("No Solution!\n");
    }
    return 0;
}


