#include <iostream>
#include <cstdio>
#include <cstdlib>
#define maxn 5000001
using namespace std;

int maxPrime[maxn];
bool pure[maxn];
int Ans[maxn],N,k;

int main(){
    freopen("P1092.txt","r",stdin);
    for(int i=2;i<maxn;++i){
        if(!maxPrime[i]){
            for(int j=i;j<maxn;j+=i) maxPrime[j]=i;
            for(int I = 1; I <= 5000000/i;){
                pure[I*=i]=true;
            }
        }
    }
    int N=0;
    for(int i=1;i<=5000000;++i){
        if(pure[i]){
            Ans[++N] = i;
        }
    }
    while(~scanf("%d",&k))
        printf("%d\n",k>N?-1:Ans[k]);
    return 0;
}


