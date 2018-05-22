#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <set>
#define maxn 100001
using namespace std;
int T,N,M,a,b;
int IN[maxn];//入度
set<int> Zero;//入度为零的节点集合
list<int> L[maxn];//出边

int main(){
    freopen("P1083.txt","r",stdin);
    scanf("%d",&T);
    for(int C=1;C<=T;++C){
        scanf("%d%d",&N,&M);
        Zero.clear();
        for(int i=1;i<=N;++i){
            IN[i]=0;
            L[i].clear();
        }
        
        for(int i=0;i<M;++i){
            scanf("%d%d",&a,&b);
            IN[a]++;
            L[b].push_back(a);
        }
        
        for(int i=1;i<=N;++i){
            if(!IN[i]){
                Zero.insert(i);
            }
        }
        
        int Left = N;
        while(!Zero.empty()){
            set<int>::iterator it = Zero.begin();
            int id = *it;
            Zero.erase(it);
            if(Left == N) printf("%d",id);
            else printf(" %d",id);
            Left--;
            
            for(list<int>::iterator it = L[id].begin();it!=L[id].end();++it){
                if(!--IN[*it]) Zero.insert(*it);
            }
        }
        if(Left) printf("-1\n");
        else printf("\n");
    }
    return 0;
}


