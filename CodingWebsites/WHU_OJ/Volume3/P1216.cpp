#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
using namespace std;
int maxprime[10011];
int P[1500],P2[1500],Pn;
void Init(){
    Pn = 0;
    memset(maxprime,-1,sizeof(maxprime));
    for(int i=2;i<=10007;++i){
        if(-1 != maxprime[i]) continue;
        P[++Pn] = i;
        P2[Pn] = P[Pn] * P[Pn];
        for(int j=i;j<=10007;j+=i) maxprime[j]=i;
    }
}
bool IsPrime(int n){
    for(int i=1;P2[i]<=n;++i){
        if(n % P[i] == 0) return false;
    }
    return n != 1;
}
set<int> S[9];
int main(){
    freopen("P1216.txt","r",stdin);
    S[0].insert(0);
    Init();
    for(int i=0;i<8;++i){
        for(set<int>::iterator it = S[i].begin();it != S[i].end();++it){
            for(int j=1;j<=9;++j){
                int Num = *it * 10 + j;
                if(IsPrime(Num)){
                    S[i+1].insert(Num);
                }
            }
        }
    }
    
    int N;
    while(~scanf("%d",&N)){
        for(set<int>::iterator it = S[N].begin();it != S[N].end();++it){
            printf("%d\n",*it);
        }
    }
    return 0;
}


