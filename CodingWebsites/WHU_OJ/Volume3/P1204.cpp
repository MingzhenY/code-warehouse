#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int A[500000];
int main(){
    freopen("P1204.txt","r",stdin);
    int N;
    long long v;
    while(~scanf("%d",&N)){
        for(int i=0;i<N;++i) scanf("%d",&A[i]);
        sort(A,A+N);
        int half = (N-1)>>1;
        for(int i=half;i<N;++i){
            if(A[i]==A[i-half]){
                printf("%d\n",A[i]);
                break;
            }
        }
    }
    return 0;
}

