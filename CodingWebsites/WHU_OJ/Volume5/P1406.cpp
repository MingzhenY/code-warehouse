#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
    freopen("P1406.txt","r",stdin);
    int N,C;
    while(cin>>N>>C){
        if(N==0||C==0) {
            printf("0\n");
        }
        else{
            long long T=C/(N<<1);
            printf("%d\n",int(T*(C-T*N) >= (T+1)*(C-(T+1)*N)?T:T+1));
        }
    }
    return 0;
}


