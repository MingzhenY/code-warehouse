/*
 WA: 估计是精度不够
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define LL long long
using namespace std;
struct Matrix{
    double a,b,c,d;
    Matrix():a(1),b(0),c(0),d(1){}
    Matrix(double a,double b,double c,double d):a(a),b(b),c(c),d(d){}
    Matrix PowerSum(LL k){/*
        Matrix AN(0,0,0,0),K;
        for(int i = 0 ; i < k ; ++i) {
            AN = AN + K;
            K = K * *this;
        }
        return AN;*/
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
        return Matrix(a+B.a,b+B.b,c+B.c,d+B.d);
    }
    Matrix operator *(Matrix B){
        return Matrix(a*B.a+b*B.c,a*B.b+b*B.d,c*B.a+d*B.c,c*B.b+d*B.d);
    }
    void Show(){
        printf("%.2f %.2f\n%.2f %.2f\n",a,b,c,d);
    }
};

int main(){
    freopen("P1140.txt","r",stdin);
    double X,Y,A,k;
    while(~scanf("%lf%lf%lf%lf",&X,&Y,&A,&k)){
        double d = A * M_PI / 180.0 ;
        Matrix T(k*cos(d),k*sin(d),-k*sin(d),k*cos(d));
        T = T.PowerSum(1000000000);
        double DX,DY;
        DX = X * T.a + Y * T.c;
        DY = X * T.b + Y * T.d;
        printf("(%.3f,%.3f)\n",DX,DY);
    }
    return 0;
}


