#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int T,h,l;
int A[50][50];


int main(){
    freopen("P1311.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&h,&l);
        int ANS=0;
        for(int i=0;i<h;++i){
            for(int j=0;j<l;++j){
                scanf("%d",&A[i][j]);
            }
        }
        
        
        
        printf("%d\n",ANS);
    }
    return 0;
}


