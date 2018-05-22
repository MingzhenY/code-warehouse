#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int A[100007],D[100007],N;
int main(){
    freopen("P1398.txt","r",stdin);
    while(~scanf("%d",&N)){
        for(int i = 1 ; i <= N ; ++i) scanf("%d",&A[i]);
        int Len = 1;
        D[1] = A[1];
        for(int i = 2 ; i <= N ; ++i){
            if(A[i] > D[Len]) D[++Len] = A[i];
            else{
                int L = 0 , R = Len, M ;//first M that D[M] >= A[i]
                while(L ^ R){//[L,R]
                    M = (L + R) >> 1;
                    if(D[M] >= A[i]) R = M;
                    else L = M + 1;
                }
                D[L] = A[i];
            }
        }
        printf("%d\n",Len);
    }
    return 0;
}



