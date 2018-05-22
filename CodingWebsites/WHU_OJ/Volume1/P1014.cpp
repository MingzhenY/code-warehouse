#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int a,b,c,d,e,f,g,h,i;
struct V{
    int x,y,z;
    V(){}
    V(int x,int y,int z):x(x),y(y),z(z){}
    double Len(){return sqrt(x*x+y*y+z*z);}
};
int Dot(V A,V B){return A.x*B.x+A.y*B.y+A.z*B.z;}
V Cross(V A,V B){return V(A.y*B.z-B.y*A.z,A.z*B.x-A.x*B.z,A.x*B.y-B.x*A.y);}
int main(){
    freopen("P1014.txt","r",stdin);
    while(~scanf("%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&i)){
        V A(c,f,i),B(b,e,h),C(a,d,g);
        int ANS = abs(Dot(A,Cross(B,C)));
        printf("%.2f\n",double(ANS));
    }
    return 0;
}


