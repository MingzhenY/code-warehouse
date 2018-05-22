#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int A[10001],Sum[10001];
void Init(){
    for(int step = 1 ; step <= 10000 ; ++step){
        for(int i = step ; i <= 10000 ; i += step){
            A[i] = !A[i];
        }
    }
    for(int i = 1 ; i <= 10000 ; ++i) Sum[i] = Sum[i-1] + A[i];
}
int main(){
    freopen("P1184.txt","r",stdin);
    Init();
    int n;
    while(~scanf("%d",&n)){
        printf("%d\n",Sum[n]);
    }
    
    return 0;
}


