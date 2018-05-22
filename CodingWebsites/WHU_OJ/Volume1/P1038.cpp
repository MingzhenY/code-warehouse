#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cmath>
#define UL unsigned int
#define eps 1e-6
using namespace std;
int dcmp(double x){return (x>-eps)-(x<eps);}
int x[100],y[100];
struct Arc{
    int a,b;
    double Dist;
    Arc(int a=0,int b=0,double Dist=0):a(a),b(b),Dist(Dist){}
    bool operator < (const Arc B)const{return dcmp(Dist-B.Dist)>0;}
};

int F[101];
int Find(int x){return x==F[x]?x:F[x]=Find(F[x]);}
void Union(int x,int y){F[Find(x)]=Find(y);}
priority_queue<Arc> Q;
int main(){
    freopen("P1038.txt","r",stdin);
    int n,L;
    while(~scanf("%d",&n)&&n){
        scanf("%d",&L);
        for(int i=0;i<n;++i)
            scanf("%d%d",&x[i],&y[i]);
        
        for(int i=0;i<n;++i) F[i]=i;
        while(!Q.empty()) Q.pop();
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                Q.push(Arc(i,j,sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))));
            }
        }
        int All=n;
        double Cost=0;
        while(All>1){
            Arc cnt=Q.top();Q.pop();
            if(Find(cnt.a)!=Find(cnt.b)){
                Cost+=cnt.Dist;
                Union(cnt.a,cnt.b);
                --All;
            }
        }
        printf("%s\n",dcmp(L-Cost)>=0 ? "Success!" : "Poor magicpig!");
    }
    
    
    return 0;
}


