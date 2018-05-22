#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
    freopen("P1203.txt","r",stdin);
    int N,v;
    while(~scanf("%d",&N)){
        int Number,Times=0;
        for(int i=0;i<N;++i){
            scanf("%d",&v);
            if(Times){
                if(Number == v) ++Times;
                else --Times;
            }
            else Number = v , Times = 1;
        }
        printf("%d\n",Number);
    }
    return 0;
}


