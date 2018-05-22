#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#define maxn 100007
using namespace std;
int N,M,a,b;
multiset<int> MS[maxn];
int F[maxn];
int Find(int x){
    int t=x;
    while(F[t]!=t) t=F[t];
    return F[x]=t;
}
int main(){
    freopen("P1093.txt","r",stdin);
    while(~scanf("%d",&N)){
        for(int i=1;i<=N;++i){
            F[i]=i;
            scanf("%d",&a);
            MS[i].clear();
            MS[i].insert(a);
        }
        scanf("%d",&M);
        for(int i=0;i<M;++i){
            scanf("%d%d",&a,&b);
            int Fa=Find(a),Fb=Find(b);
            if(Fa!=Fb){
                int Max_a = *MS[Fa].rbegin();
                int Max_b = *MS[Fb].rbegin();
                MS[Fa].erase(MS[Fa].find(Max_a));
                MS[Fb].erase(MS[Fb].find(Max_b));
                MS[Fa].insert(Max_a>>1);
                MS[Fb].insert(Max_b>>1);
                for(multiset<int>::iterator it=MS[Fa].begin();it!=MS[Fa].end();++it){
                    MS[Fb].insert(*it);
                }
                MS[Fa].clear();
                F[Fa]=Fb;
                printf("%d\n",*MS[Fb].rbegin());
            }
            else printf("-1\n");
        }
    }
    return 0;
}


