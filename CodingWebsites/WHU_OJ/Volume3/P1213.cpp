#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
int X[100],Y[100];
int area(int x1,int y1,int x2,int y2){return x1 * y2 - x2 * y1;}
int main(){
    freopen("P1213.txt","r",stdin);
    while(~scanf("%d",&n)){
        for(int i=0;i<n;++i) scanf("%d%d",&X[i],&Y[i]);
        int ANS = 0;
        for(int i=0;i<n;++i){
            ANS += area(X[i],Y[i],X[(i+1)%n],Y[(i+1)%n]);
        }
        printf("%d\n",ANS>>1);
    }
    return 0;
}


