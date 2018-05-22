#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
}P[1000000];
int main(){
    freopen("P1402.txt","r",stdin);
    int N;
    while(~scanf("%d",&N) && N){
        for(int i = 0 ; i < N ; ++i){
            scanf("%lf%lf",&P[i].x,&P[i].y);
        }
        double ANS = 0.0;
        if(N >= 3){
            for(int i = 0 ; i < N ; ++i){
                ANS += P[i].x * P[(i+1)%N].y - P[i].y*P[(i+1)%N].x;
            }
        }
        if(ANS < 0.0) ANS = - ANS;
        printf("%.0f\n",ANS/2.0);
    }
    return 0;
}


