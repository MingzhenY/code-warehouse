#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define eps 1e-9
using namespace std;
int sgn(double x){return (x > -eps) - (x < eps);}
struct PV{
    double x,y;
    int p;
    PV(){}
    PV(double x,double y,int p):x(x),y(y),p(p){}
    PV operator +(PV B){return PV(x+B.x,y+B.y,p+B.p);}
    PV operator -(PV B){return PV(x-B.x,y-B.y,p-B.p);}
    PV operator *(double k){return PV(x*k,y*k,p);}
    double Length(){return sqrt(x*x+y*y);}
    PV Turn(){return PV(-y,x,p);}
    PV e(){return *this * (1.0/Length());}
    void show(){
        printf("%s:(%.2f,%.2f)\n",p?"Point":"Vector",x,y);
    }
};
PV Points[200];
int N;
int Test(PV C,double r){
    int ANS = 0;
    for(int i = 0 ; i < N ; ++i){
        ANS += sgn((Points[i] - C).Length() - r) <= 0;
    }
    return ANS;
}
int GetCircleCenter(PV A,PV B,double r){//return answer or -1
    double L = (A - B).Length();
    double D = r * r - L * L / 4.0;
    if(sgn(D) < 0) return -1;
    PV M = (A + B) * 0.5;
    PV R = (B - A).Turn().e();
    PV C1 = M + R * sqrt(D);
    PV C2 = M - R * sqrt(D);
    int ANS1 = Test(C1,r);
    int ANS2 = Test(C2,r);
    return max(ANS1,ANS2);
}
int MaxCover(double r){
    int ANS = -1;
    for(int i = 0 ; i < N ; ++i){
        for(int j = i + 1 ; j < N ; ++j){
            int Cur = GetCircleCenter(Points[i],Points[j],r);
            if(~Cur){
                ANS = max(ANS,Cur);
            }
        }
    }
    return ANS;
}
int main(){
    freopen("P1201.txt","r",stdin);
    int r,x,y;
    while(~scanf("%d%d",&N,&r)){
        for(int i = 0 ; i < N ; ++i){
            scanf("%d%d",&x,&y);
            Points[i] = PV(x,y,1);
        }
        printf("%d\n",N >= 2 ? max(1,MaxCover(r)) : N);
    }
    return 0;
}


