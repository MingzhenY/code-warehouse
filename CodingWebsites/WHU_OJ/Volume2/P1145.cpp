#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main(){
    freopen("P1145.txt","r",stdin);
    int N;
    while(~scanf("%d",&N) && N){
        printf("%d\n",N < 4 ? N * (N - 1) / 2 : 2 * N - 4);
    }
    return 0;
}


