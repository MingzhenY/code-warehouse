#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int D[100][100];

int F[100];
void Init(int n){for(int i=0;i<n;++i) F[i]=i;}
int Find(int x){return x==F[x]?x:Find(F[x]);}

struct Arc{
    int from,to,dist;
    Arc(){}
    Arc(int from,int to,int dist):from(from),to(to),dist(dist){}
    bool operator < (const Arc &B)const{return dist < B.dist;}
}Arcs[10000];

int main(){
    freopen("P1050.txt","r",stdin);
    int t,n;
    scanf("%d",&t);
    while(t-->0){
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                scanf("%d",&D[i][j]);
            }
        }
        Init(n);
        int An = 0,Dist = 0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                Arcs[An++] = Arc(i,j,D[i][j]);
            }
        }
        sort(Arcs,Arcs+An);
        for(int i=0;i<An;++i){
            int Fa=Find(Arcs[i].from),Fb=Find(Arcs[i].to);
            if(Fa!=Fb){
                F[Fa]=Fb;
                Dist += Arcs[i].dist;
            }
        }
        printf("%d\n",Dist);
    }
    return 0;
}


