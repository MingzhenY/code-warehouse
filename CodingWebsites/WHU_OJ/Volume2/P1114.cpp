#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define eps 1e-7
using namespace std;
int sgn(double x){return (x>-eps)-(x<eps);}
int Point(double x,double y){
    double r = sqrt(x * x + y * y);
    if(sgn(r - 3.0) <= 0) return 100;
    if(sgn(r - 6.0) <= 0) return 80;
    if(sgn(r - 9.0) <= 0) return 60;
    if(sgn(r - 12.0) <= 0) return 40;
    if(sgn(r - 15.0) <= 0) return 20;
    return 0;
}
int main(){
    freopen("P1114.txt","r",stdin);
    double x1,y1,x2,y2,x3,y3;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3){
        if(x1 < -50.0) break;
        int S1 = Point(x1,y1) + Point(x2,y2) + Point(x3,y3);
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        int S2 = Point(x1,y1) + Point(x2,y2) + Point(x3,y3);
        
        printf("SCORE: %d to %d, ",S1,S2);
        
        if(S1 == S2) printf("TIE.\n");
        else printf("PLAYER %d WINS.\n",S1 > S2 ? 1 : 2 );
    }
    return 0;
}


