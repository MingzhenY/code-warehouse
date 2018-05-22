#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
using namespace std;

int main(){
    freopen("P1358.txt","r",stdin);
    int t,a,b;
    scanf("%d",&t);
    while(t-->0){
        scanf("%d%d",&a,&b);
        LL ANS = (LL) a * b - a - b;
        cout<<ANS<<endl;
    }
    return 0;
}


