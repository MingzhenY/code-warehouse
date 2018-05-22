#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int N,M[1000],a;

int main(){
    freopen("P1064.txt","r",stdin);
    while(~scanf("%d",&N)){
        memset(M,0,sizeof(M));
        for(int i=0;i<N;++i){
            scanf("%d",&a);
            M[a]=1;
        }
        int First=1;
        for(int i=0;i<1000;++i){
            if(M[i]){
                if(First) printf("%d",i),First=0;
                else printf(" %d",i);
            }
        }
        printf("\n");
    }
    return 0;
}


