#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
bool F[1000001];
int main(){
    freopen("P1300.txt","r",stdin);
    F[0]=F[1]=0;
    F[2]=F[3]=F[4]=1;
    for(int i=5;i<=1000000;++i){
        F[i]=!F[i-2]||!F[i-3]||!F[i-5];
    }
    int c,n;
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        printf("%s\n",F[n]?"Sproblvem":"Dzs");
    }
    return 0;
}


