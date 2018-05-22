#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int K;
int A[1001];
int main(){
    freopen("P1313.txt","r",stdin);
    while(~scanf("%d",&K)&&K){
        long long X = 1 , Big = 0 ;
        memset(A,-1,sizeof(A));
        for(int i = 1 ; i <= 2000 ; ++i){
            X *= K;
            if((Big = Big || X >= 1000)){
                X %= 1000;
                if(-1 == A[X]){
                    A[X] = i;
                }
                else{
                    printf("%d\n",A[X]+i);
                    break;
                }
            }
        }
    }
    return 0;
}


