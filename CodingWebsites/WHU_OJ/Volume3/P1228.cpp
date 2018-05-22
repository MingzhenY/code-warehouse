#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int F,K,a,b;
bool vis[10001];
int main(){
    freopen("P1228.txt","r",stdin);
    while(~scanf("%d%d",&F,&K)){
        for(int i=1;i<=F;++i) vis[i]=false;
        for(int i=0;i<K;++i){
            scanf("%d%d",&a,&b);
            while(a<=F) vis[a]=true,a+=b;
        }
        int ANS=0;
        for(int i=1;i<=F;++i) ANS+=!vis[i];
        printf("%d\n",ANS);
    }
    return 0;
}


