#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#define OUT3(a,b,c) cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<endl;
using namespace std;

vector<int> V[3001];

int main(){
    freopen("P1022.txt","r",stdin);
    int T,N;
    scanf("%d",&T);
    for(int C = 1;C <= T; ++C){
        scanf("%d",&N);
        for(int i=1;i<=3000;++i) V[i].clear();
        int Ans=0,Time,Cost;
        for(int i=1;i<=N;++i){
            scanf("%d%d",&Time,&Cost);
            Ans+=Cost;
            V[Time].push_back(Cost);
        }
        
        priority_queue<int> Q;
        for(int t=3000;t>=1;--t){
            for(int i=0;i<V[t].size();++i) {
                Q.push(V[t][i]);
                
            }
            if(!Q.empty()){
                
                Ans-=Q.top();Q.pop();
            }
        }
        printf("Case %d:\n%d\n",C,Ans);
        if(C < T) printf("\n");
    }
    return 0;
}


