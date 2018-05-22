#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
using namespace std;

int main(){
    freopen("P1384.txt","r",stdin);
    int t,n,m;
    scanf("%d",&t);
    for(int Case = 1 ; Case <= t ; ++Case){
        scanf("%d%d",&n,&m);
        LL N = n , M = m ;
        LL ANS = (M+N)*(M-N+1)/2;
        cout<<"Case #"<<Case<<": "<<ANS<<endl;
    }
    return 0;
}


