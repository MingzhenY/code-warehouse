#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int T,N;
int Sx,Sy,Dx,Dy;

int main(){
    freopen("P1028.txt","r",stdin);
    scanf("%d",&T);
    for(int C=1;C<=T;++C){
        scanf("%d%d%d%d%d",&N,&Sx,&Sy,&Dx,&Dy);
        int S = (Sx&1)^(Sy&1);
        int D = (Dx&1)^(Dy&1);
        printf("Case %d:\n%d\n",C,S^D?-1:max(abs(Sx-Dx),abs(Sy-Dy)));
        if(C^T) printf("\n");
    }
    return 0;
}


