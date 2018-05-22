#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
using namespace std;
LL M;
struct Matrix{
    LL a,b,c,d;
    Matrix():a(1),b(0),c(0),d(1){}
    Matrix(LL a,LL b,LL c,LL d):a(a),b(b),c(c),d(d){}
    Matrix PowerSum(LL k){
        if(!k) return Matrix();
        Matrix ANS = (Matrix()+Power((k+1)/2))*(PowerSum((k-1)/2));
        if(k & 1) return ANS;
        else return ANS + Power(k);
    }
    Matrix Power(LL k){
        Matrix A = *this , ANS;
        while(k){
            if(k & 1) ANS = ANS * A;
            A = A * A;
            k >>= 1;
        }
        return ANS;
    }
    Matrix operator +(Matrix B){
        return Matrix((a+B.a)%M,(b+B.b)%M,(c+B.c)%M,(d+B.d)%M);
    }
    Matrix operator -(Matrix B){
        return Matrix((a-B.a)%M,(b-B.b+M)%M,(c-B.c+M)%M,(d-B.d+M)%M);
    }
    Matrix operator *(Matrix B){
        return Matrix((a*B.a+b*B.c)%M,(a*B.b+b*B.d)%M,(c*B.a+d*B.c)%M,(c*B.b+d*B.d)%M);
    }
    void Show(){
        printf("%lld %lld\n%lld %lld\n",a,b,c,d);
    }
};
int main(){
    freopen("P1138.txt","r",stdin);
    LL k,b,n;
    Matrix A(0,1,1,1);
    while(~scanf("%lld%lld%lld%lld",&k,&b,&n,&M)){
        Matrix ANS = A.Power(b) * A.Power(k).PowerSum(n-1);
        printf("%lld\n",ANS.b);
    }
    return 0;
}


