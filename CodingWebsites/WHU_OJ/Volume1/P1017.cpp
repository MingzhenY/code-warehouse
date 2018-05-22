/*
 镜像对称+三分法
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
#define eps 1e-5
int sgn(double x){return (x>-eps)-(x<eps);}
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator +(Point B){return Point(x+B.x,y+B.y);}
    Point operator -(Point B){return Point(x-B.x,y-B.y);}
    void Show(){printf("(%f,%f)\n",x,y);}
};
struct Vector{
    double x,y;
    Vector(){}
    Vector(Point A):x(A.x),y(A.y){}
    Vector(double x,double y):x(x),y(y){}
    double Length(){return sqrt(x*x+y*y);}
    Vector operator +(Vector B){return Vector(x+B.x,y+B.y);}
    Vector operator -(Vector B){return Vector(x-B.x,y-B.y);}
    double operator *(Vector B){return x*B.x+y*B.y;}
    Vector operator *(double k){return Vector(k*x,k*y);}
    void Show(){printf("(%f,%f)\n",x,y);}
};
Point Mirror(Point A,Point B,Point C){
    Vector VA(B-A),VB(C-A),VC;
    double L = (VA-VB)*(VA-VB);
    VC = VA*(2*(VB*VB-VA*VB)/L)+VB*(2*(VA*VA-VA*VB)/L);
    return Point(A.x+VC.x,A.y+VC.y);
}
Point GetPoint(Point A,Point B,double k){
    Vector V = Vector(B-A)*k;
    return Point(A.x+V.x,A.y+V.y);
}
double GetDist(Point A,Point C,Point _A,Point _C,double k){
    Point P1 = GetPoint(A,C,k);
    Point P2 = GetPoint(_A,_C,k);
    return Vector(P1-P2).Length();
}
double Search(Point A,Point B,Point C){
    Point _A = Mirror(A,B,C);
    Point _C = Mirror(C,B,_A);
    double L = 0.0 , R = 1.0 , M1 , M2 , V1 , V2 ;
    while(sgn(R - L)){
        M1 = L + (R - L) / 3 ;
        M2 = M1 + (R - L) / 3 ;
        V1 = GetDist(A,C,_A,_C,M1);
        V2 = GetDist(A,C,_A,_C,M2);
        if(V1 <= V2) R = M2;
        else L = M1;
    }
    return V1;
}
int main(){
    freopen("P1017.txt","r",stdin);
    int N;
    scanf("%d",&N);
    while(N--){
        Point A,B,C;
        scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
        printf("%.3f\n",Search(A,B,C));
    }
    return 0;
}


