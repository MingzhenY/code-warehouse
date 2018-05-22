#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define OUT3(a,b,c) cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<endl;
using namespace std;
int Rank[1001],N;
void SetRank(int n){
    N=n;
    sort(Rank,Rank+N);
    int I=1;
    for(int i=1;i<N;++i) if(Rank[i]!=Rank[i-1]) Rank[I++]=Rank[i];
    N = I;
}
int GetRank(int k){
    int L=0,R=N,M;//[L,R)
    while(L+1!=R){
        M=(L+R)>>1;
        if(Rank[M] <= R) L=M;
        else R=M;
    }
    return L;
}

int n;
int x[1000],y[1000];

int temp[1000],tempn;
vector<int> V[1000];
int main(){
    freopen("P1016.txt","r",stdin);
    while(cin>>n){
        int Min=1<<16,Max=-Min;
        for(int i=0;i<n;++i) {
            scanf("%d%d",&x[i],&y[i]);
            Rank[i]=x[i];
            Min=min(Min,y[i]);
            Max=max(Max,y[i]);
        }
        
        int Mid2 = Min+Max;
        SetRank(n);
        
        for(int i=0;i<n;++i){
            if(2*y[i]!=Mid2) V[GetRank(x[i])].push_back(y[i]);
        }
        
        bool T=true;
        for(int i=0;i<N;++i){
            tempn=0;
            for(int j=0;j<V[i].size();++j){
                temp[tempn++]=V[i][j];
            }
            sort(temp,temp+tempn);
            for(int k=0;k<tempn;++k) if(temp[k]+temp[tempn-k-1]!=Mid2) T=false;
        }
        printf("%s\n",T?"YES":"NO");
        for(int i=0;i<N;++i) V[i].clear();
    }
    
    
    return 0;
}


