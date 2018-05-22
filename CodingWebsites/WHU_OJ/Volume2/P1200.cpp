#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int F[10007];
int Find(int x){return x == F[x] ? x : F[x] = Find(F[x]);}
int main(){
    freopen("P1200.txt","r",stdin);
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        int Part = n;
        for(int i = 1 ; i <= n ; ++i) F[i] = i;
        for(int i = 0 ; i < m ; ++i){
            int a,b;
            scanf("%d%d",&a,&b);
            int Ra = Find(a), Rb = Find(b);
            if(Ra != Rb){
                --Part;
                F[Ra] = Rb;
            }
        }
        printf("%d\n",Part);
    }
    return 0;
}


