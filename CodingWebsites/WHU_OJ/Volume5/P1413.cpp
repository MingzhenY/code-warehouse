#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
    freopen("P1413.txt","r",stdin);
    int T,A,B,H;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&A,&B,&H);
        double ANS=B*1.0*H/A;
        printf("%.2f\n",ANS);
    }
    
    return 0;
}


