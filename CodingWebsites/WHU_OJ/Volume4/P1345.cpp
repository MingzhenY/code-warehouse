#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
#define M 1000000000LL
using namespace std;
struct Int{
    LL a[21];
    int len;
    Int(){memset(a,0,sizeof(a));}
    Int(LL k){
        memset(a,0,sizeof(a));
        if(!k){
            len = 1;
            a[0] = 0;
        }
        else{
            len = 0;
            while(k){
                a[len++] = k % M;
                k /= M;
            }
        }
    }
    Int operator +(Int B){
        Int C;
        C.len = max(len,B.len);
        int d = 0;
        for(int i = 0 ; i < C.len ; ++i){
            C.a[i] = a[i] + B.a[i] + d;
            d = C.a[i] / M;
            C.a[i] %= M;
        }
        if(d) C.a[C.len++] = d;
        return C;
    }
    Int operator *(Int B){
        Int C;
        C.len = len + B.len;
        for(int i = 0 ; i < len ; ++i){
            for(int j = 0 ; j < B.len ; ++j){
                int IJ = i + j;
                C.a[IJ] += a[i] * B.a[j];
                while(C.a[IJ] >= M){
                    C.a[IJ + 1] += C.a[IJ] / M;
                    C.a[IJ++] %= M;
                }
            }
        }
        while(C.len && !C.a[C.len - 1]) --C.len;
        return C;
    }
    void Show(){
        printf("%lld",a[len - 1]);
        for(int i = len - 2 ; i >= 0 ; --i) printf("%09lld",a[i]);
        printf("\n");
    }
};
Int A[301];
void Init(){
    A[0] = 1;
    for(int i = 1 ; i <= 300 ; ++i){
        A[i] = 0;
        for(int k = 0 , t = i - 1 ; t >= 0 ; ++k , --t){
            A[i] = A[i] + A[k] * A[t];
        }
    }
}
int main(){
    freopen("P1345.txt","r",stdin);
    Init();
    int T,n;
    scanf("%d",&T);
    while(T-- >0){
        scanf("%d",&n);
        A[n].Show();
    }
    return 0;
}


