#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
    freopen("P1137.txt","r",stdin);
    int N,M,a,Min;
    while(~scanf("%d%d",&N,&M)){
        Min=1<<30;
        for(int i=0;i<N;++i){
            scanf("%d",&a);
            Min=min(Min,a);
        }
        printf("%d\n",M/Min);
    }
    
    return 0;
}


