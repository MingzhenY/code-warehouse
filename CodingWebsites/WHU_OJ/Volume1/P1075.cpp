#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int A[6][2];
int main(){
    freopen("P1075.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int c=0;c<T;++c){
        int k,M;
        char ch;
        scanf("%d %c%d",&k,&ch,&M);
        A[0][0]=1;
        A[1][0]=A[2][0]=A[3][0]=A[4][0]=A[5][0]=0;
        for(int i=0;i<k;++i){
            int I=i&1,_I=!I;
            A[0][_I]=(A[5][I]+A[1][I])%M;
            A[1][_I]=(A[0][I]+A[2][I])%M;
            A[2][_I]=A[1][I];
            A[3][_I]=(A[2][I]+A[4][I])%M;
            A[4][_I]=A[5][I];
            A[5][_I]=(A[4][I]+A[0][I])%M;
        }
        printf("%d\n",A[ch-'a'][k&1]);
    }
    return 0;
}


