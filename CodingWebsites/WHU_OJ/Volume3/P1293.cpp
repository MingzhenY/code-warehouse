#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int M,N;
int A[10][10]={
    {45},
    {36,46},
    {28,37,47},
    {21,29,38,48},
    {15,22,30,39,49},
    {10,16,23,31,40,50},
    { 6,11,17,24,32,41,51},
    { 3, 7,12,18,25,33,42,52},
    { 1, 4, 8,13,19,26,34,43,53},
    { 0, 2, 5, 9,14,20,27,35,44,54}
};
int main(){
    freopen("P1293.txt","r",stdin);
    while(~scanf("%d%d",&M,&N)&&(M||N)){
        for(int i=10-N;i<10;++i){
            for(int j=0;j<=i+N-10;++j){
                printf("%2d ",A[i][j]+M);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}


