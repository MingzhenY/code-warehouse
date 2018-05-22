#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int T;
int N;
int A[100];
int main(){
    freopen("P1419.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;++i) scanf("%d",&A[i]);
        int XAY=0,AMR=0;
        for(int i=0;i<N;++i){
            int Same=-1;
            for(int j=0;j<i;++j){
                if(A[i]==A[j]){
                    Same=j;
                    break;
                }
            }
            if(~Same){
                for(int k=Same;k<=i;++k){
                    if(A[k]){
                        if(i&1) ++AMR;
                        else ++XAY;
                        A[k]=0;
                    }
                }
            }
        }
        printf("%s\n",XAY>AMR?"xay":"amr");
    }
    return 0;
}


