#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int A[10001];
int main(){
    freopen("P1290.txt","r",stdin);
    int n;
    while(~scanf("%d",&n)&&n){
        for(int i = 1 ; i <= n ; ++i) scanf("%d",&A[i]);
        int Ans = 0;
        for(int i = 1 ; i <= n ; ++i){
            for(int j = i + 1 ; j <= n ; ++j){
                Ans += A[i] > A[j];
            }
        }
        printf("%d\n",Ans);
    }
    return 0;
}


