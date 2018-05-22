#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int N;
int x[300],y[300];

int main(){
    freopen("P1087.txt","r",stdin);
    while(~scanf("%d",&N)){
        int ANS = 2;
        for(int i = 0 ; i < N ; ++i){
            double a,b;
            scanf("%lf%lf",&a,&b);
            x[i] = int(a * 10);
            y[i] = int(b * 10);
        }
        for(int i = 0 ; i < N ; ++i){
            for(int j = i + 1 ; j < N ; ++j){
                int Count = 2;
                for(int k = 0 ; k < N ; ++k){
                    if(k == i || k == j) continue;
                    Count += (x[j] - x[i]) * (y[k] - y[i]) == (x[k] - x[i]) * (y[j] - y[i]);
                }
                if(Count > ANS) ANS = Count;
            }
        }
        printf("%d\n",ANS);
    }
    return 0;
}


