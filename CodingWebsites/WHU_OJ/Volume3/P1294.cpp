#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int A[31],B[31],C[31];

int main(){
    freopen("P1294.txt","r",stdin);
    A[0] = 1 ; B[0] = C[0] = 0 ;
    for(int i = 1 ; i <= 30 ; ++i){
        C[i] = B[i - 1] + C[i - 1];
        B[i] = A[i - 1];
        A[i] = C[i] << 1;
    }
    int t,n;
    scanf("%d",&t);
    while(t-->0){
        scanf("%d",&n);
        n <<= 1;
        printf("%d\n",A[n]+B[n]+C[n]);
    }
    
    return 0;
}


