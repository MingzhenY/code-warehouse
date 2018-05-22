#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
    freopen("P1037.txt","r",stdin);
    int N,V,a;
    while(~scanf("%d",&N)&&N){
        V=0;
        for(int i=0;i<N;++i) {
            scanf("%d",&a);
            V+=a;
        }
        for(int i=0;i<N;++i) {
            scanf("%d",&a);
            V-=a;
        }
        printf("%s\n",V>=0?"YES":"NO");
    }
    return 0;
}


