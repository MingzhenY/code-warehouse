#include <cstdio>
#include <iostream>
#include <algorithm>
#define maxn 1010
#define maxm 15010
using namespace std;
//²¢²é¼¯
int f[maxn]; 
int Find(int x){return x==f[x]?x:f[x]=Find(f[x]);}
void Union(int x,int y){f[Find(x)]=Find(y);}
//Í¼
struct Edge{
    int from,to;
    int w;
    int use;
    bool operator<(const Edge &B)const{return w<B.w;}
}E[maxm];
int n,m;int Count;
int main(){
    freopen("1160.txt","r",stdin);
    while(cin>>n>>m){
        for(int i=1;i<=n;++i) f[i]=i;Count=0;
        for(int i=0;i<m;++i){
            int a,b,c;scanf("%d%d%d",&a,&b,&c);
            E[i].from=a;E[i].to=b;E[i].w=c;E[i].use=0;
        }  
        sort(E,E+m);
        int Max=0;
        for(int i=0;i<m;++i){
            if(Find(E[i].from)!=Find(E[i].to)){
                Max=Max>E[i].w?Max:E[i].w;
                Count++;
                E[i].use=1;
                Union(E[i].from,E[i].to) ; 
            }
        }
        printf("%d\n%d\n",Max,Count);
        for(int i=0;i<m;++i){
            if(E[i].use) printf("%d %d\n",E[i].from,E[i].to);   
        }
        
    }
    return 0;   
}
