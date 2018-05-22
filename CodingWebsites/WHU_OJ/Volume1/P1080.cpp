#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
    freopen("P1080.txt","r",stdin);
    int T,N;
    scanf("%d",&T);
    for(int i=0;i<T;++i){
        scanf("%d",&N);
        printf("%s wins the game!\n",N%14?"flymouse":"snoopy");
    }
    return 0;
}


