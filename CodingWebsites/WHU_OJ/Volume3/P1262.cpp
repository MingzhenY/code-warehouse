#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int A[7][7];
int D[7],n;
int Test(int K){
    for(int i = 1 ; i < n ; ++i) D[i] = K % n , K /= n;
    //for(int i = 0 ; i < n ; ++i) printf("%d ",D[i]);printf("\n");
    int V,Max = -1000000000;
    for(int j = 0 ; j < n ; ++j){
        V = 0;
        for(int i = 0 ; i < n ; ++i){
            V += A[i][(j+D[i])%n];
        }
        if(V > Max) Max = V;
    }
    return Max;
}
int main(){
    freopen("P1262.txt","r",stdin);
    
    while(~scanf("%d",&n)&&~n){
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                scanf("%d",&A[i][j]);
            }
        }
        int MAX = 1 , ANS = 1000000000;
        for(int i = 1 ; i < n ; ++i) MAX *= n;
        for(int i = 0 ; i < MAX ; ++i) {
            int T = Test(i);
            if(T < ANS) ANS = T;
        }
        printf("%d\n",ANS);
    }
    return 0;
}


