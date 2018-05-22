#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n,t[10000],a;
int main(){
    freopen("P1007.txt","r",stdin);
    while(~scanf("%d",&n)){
        for(int i=0;i<n;++i) scanf("%d",&t[i]);
        for(int j=0;j<7;++j){
            for(int i=0;i<n;++i){
                scanf("%d",&a);
                t[i]=min(t[i],a);
            }
        }
        int Ans=0;
        for(int i=0;i<n;++i) Ans+=t[i];
        printf("%d\n",Ans);
    }
    return 0;
}


