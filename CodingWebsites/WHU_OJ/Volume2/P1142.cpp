#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define M 1000000000
using namespace std;
struct Int{
    int len;
    int a[34];
    Int(){}
    Int(int v){
        if(!v){
            len = 1;
            a[0] = 0;
        }
        else{
            len = 0;
            while(v){
                a[len++] = v % M;
                v /= M;
            }
        }
    }
    Int operator +(Int B){
        Int C;
        C.len = max(len,B.len);
        for(int i = len ; i < C.len ; ++i) a[i] = 0;
        for(int i = B.len ; i < C.len ; ++i) B.a[i] = 0;
        int d = 0;
        for(int i = 0 ; i < C.len ; ++i){
            C.a[i] = a[i] + B.a[i] + d;
            d = C.a[i] / M;
            C.a[i] %= M;
        }
        if(d) C.a[C.len++] = d;
        return C;
    }
    void show(){
        printf("%d",a[len - 1]);
        for(int i = len - 2 ; i >= 0 ; --i) printf("%09d",a[i]);
        printf("\n");
    }
};
Int A[1001];
int main(){
    freopen("P1242.txt","r",stdin);
    A[0] = 1;
    for(int i = 1 ; i <= 1000 ; ++i){
        A[i] = A[i - 1] + A[i - 1] + Int(1);
    }
    int N;
    while(~scanf("%d",&N)) A[N].show();
    return 0;
}


