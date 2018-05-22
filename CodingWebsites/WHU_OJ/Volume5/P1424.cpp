#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
using namespace std;

int Test(int n,int k){
    LL ANS = 1;
    for(int t = n ; t < n + k; ++t){
        int C = t/k;
        ANS *= C;
    }
    return ANS;
}
void Show(int n,int k){
    for(int t = n ; t < n + k; ++t){
        int C = t/k;
        printf("%d",C);
        if(t + 1 == n + k) printf("\n");
        else printf(" ");
    }
}
int main(){
    freopen("P1424.txt","r",stdin);
    int N;
    while(~scanf("%d",&N) && N){
        Show(N,(N-1)/3+1);
    }
    return 0;
}


