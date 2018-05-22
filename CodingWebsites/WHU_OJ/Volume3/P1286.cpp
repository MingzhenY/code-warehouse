#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
struct Vector{
    double x,y,z;
    Vector(){}
    Vector(double x,double y,double z):x(x),y(y),z(z){}
    double Len(){return sqrt(x*x+y*y+z*z);}
    Vector operator-(Vector B){return Vector(x-B.x,y-B.y,z-B.z);}
};
int main(){
    freopen("P1286.txt","r",stdin);
    int x1,y1,z1,x2,y2,z2,x3,y3,z3;
    while(~scanf("%d%d%d%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2,&x3,&y3,&z3)){
        Vector A(x2-x1,y2-y1,z2-z1),B(x3-x1,y3-y1,z3-z1);
        double a,b,c;
        a = A.Len();
        b = B.Len();
        c = (A-B).Len();
        double ANS = (b+c-a)*(a+c-b)*(a+b-c)/(2*a*b*c);
        printf("%.3lf\n",ANS*ANS);
    }
    return 0;
}


