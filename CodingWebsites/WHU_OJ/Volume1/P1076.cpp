#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

int N,K,M;
//优先队列
struct Arc{
    int a,b,w;
    Arc(int a=0,int b=0,int w=0):a(a),b(b),w(w){}
    bool operator < (const Arc B)const{return w > B.w;}
};
priority_queue<Arc> Q;
//并查集
int F[1001];
int Find(int x){return x==F[x]?x:F[x]=Find(F[x]);}
void Union(int x,int y){F[Find(x)]=Find(y);}

int main(){
    freopen("P1076.txt","r",stdin);
    while(~scanf("%d%d%d",&N,&K,&M)){
        //初始化
        for(int i=1;i<=N;++i) F[i]=i;
        while(!Q.empty()) Q.pop();
        
        //读取数据
        int a,b,w;
        for(int i=0;i<M;++i){
            scanf("%d%d%d",&a,&b,&w);
            Q.push(Arc(a,b,w));
        }
        
        //计算
        int Ans = 0,Count = N;
        while(!Q.empty() && Count > K){
            Arc temp=Q.top();Q.pop();
            if(Find(temp.a)!=Find(temp.b)){
                Ans+=temp.w;
                --Count;
                Union(temp.a,temp.b);
            }
        }
        
        //输出答案
        printf("%d\n",Count==K?Ans:-1);
    }
    return 0;
}


