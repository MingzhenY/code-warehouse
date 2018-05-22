#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
struct A{
    int n;
    int a[35][35];
    A(){}
    A(int n,int t = 1):n(n){
        memset(a,0,sizeof(a));
        for(int i = 0 ; i < n ; ++i) a[i][i] = t;
    }
    A SumPow(int k){
        if(k == 1) return *this;
        A Half = Pow(k / 2) + A(n,1);
        A Other = SumPow(k / 2);
        if(k & 1) return Half * Other + Pow(k);
        else return Half * Other;
    }
    A Pow(int k){
        A I(n,1),X(*this);
        while(k){
            if(k & 1) I = I * X;
            X = X * X;
            k >>= 1;
        }
        return I;
    }
    A operator *(A B){
        A C(n,0);
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                C.a[i][j] = 0;
                for(int k = 0 ; k < n ; ++k)
                    C.a[i][j] = (C.a[i][j] + a[i][k] * B.a[k][j]) % 1985;
            }
        }
        return C;
    }
    A operator +(A B){
        A C(n,0);
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                C.a[i][j] = (a[i][j] + B.a[i][j]) % 1985;
            }
        }
        return C;
    }
    int Sum(){
        int ANS = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                ANS = (ANS + a[i][j]) % 1985;
            }
        }
        return ANS;
    }
    void Show(){
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
};
int main(){
    freopen("P1128.txt","r",stdin);
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        A T(n,0);
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                scanf("%d",&T.a[i][j]);
            }
        }
        A ANS = T.SumPow(k);
        printf("%d\n",ANS.Sum());
    }
    return 0;
}


