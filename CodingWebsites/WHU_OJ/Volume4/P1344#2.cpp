#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define maxn 100007
using namespace std;
struct M{
    int Max,Min;
    M(int Max=0,int Min=0):Max(Max),Min(Min){}
    M operator +(const M B)const{
        return M(max(Max,B.Max),min(Min,B.Min));
    }
}D[maxn<<2];
int N;
int AMax,AMin;
void Build(int l,int r,int rt){
    if(l==r){
        scanf("%d",&D[rt].Max);
        D[rt].Min=D[rt].Max;
        return;
    }
    int m=(l+r)>>1;
    Build(l,m,rt<<1);
    Build(m+1,r,rt<<1|1);
    D[rt]=D[rt<<1]+D[rt<<1|1];
}

void Update(int L,int C,int l,int r,int rt){
    if(l==r){
        D[rt].Min=D[rt].Max=C;
        return;
    }
    int m=(l+r)>>1;
    if(L <= m) Update(L,C,l,m,rt<<1);
    else       Update(L,C,m+1,r,rt<<1|1);
    D[rt]=D[rt<<1]+D[rt<<1|1];
}
M Query(int L,int R,int l,int r,int rt){
    if(l==r) return D[rt];
    int m=(l+r)>>1;
    M LM,RM;
    int X=0;
    if(L <= m) LM=Query(L,R,l,m,rt<<1),X+=1;
    if(R >  m) RM=Query(L,R,m+1,r,rt<<1|1),X+=2;
    if(X==1) return LM;
    if(X==2) return RM;
    return LM+RM;
}


int T,n,q;
int main(){
    freopen("P1344.txt","r",stdin);
    scanf("%d",&T);
    while(T-->0){
        scanf("%d%d",&n,&q);
        Build(1,n,1);
        for(int i=0;i<q;++i){
            char ch[5];
            int a,b;
            scanf("%s%d%d",ch,&a,&b);
            if(ch[0]=='C') Update(a,b,1,n,1);
            else {
                M cnt=Query(a,b,1,n,1);
                printf("%d\n",cnt.Max-cnt.Min);
            }
        }
    }
    return 0;
}


