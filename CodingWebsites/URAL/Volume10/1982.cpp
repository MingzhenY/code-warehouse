#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 110
using namespace std;
int Left;
//²¢²é¼¯
int f[maxn];
int Find(int x){return x==f[x]?x:f[x]=Find(f[x]);}
void Union(int x,int y){f[Find(x)]=Find(y);--Left;}
bool Is(int x,int y){return Find(x)==Find(y);}
//Í¼ 
int n,k,t;
int c[maxn][maxn];
int elec[maxn];
struct A{
	int x,y;
	int w;
	bool operator <(const A &B)const{
		return w <B.w; 
	}
}edge[maxn*maxn]; 

int main(void)
{freopen("1982.txt","r",stdin); 
	while(cin>>n>>k){
		for(int i=0;i<n;++i) f[i]=i;Left=n;
		for(int i=0;i<k;++i){
			scanf("%d",&t);
			elec[i]=t-1;
		}
		for(int i=1;i<k;++i) Union(elec[i],elec[i-1]);
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				scanf("%d",&c[i][j]);
			}
		}
		int T=0;
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				edge[T].x=i;
				edge[T].y=j;
				edge[T].w=c[i][j];
				++T;
			}
		}
		sort(edge,edge+T);
		int ANS=0;
		for(int i=0;i<T;++i){
			if(Is(edge[i].x,edge[i].y)) continue;
			ANS+=edge[i].w;
			Union(edge[i].x,edge[i].y);
			if(Left==1) break;
		}
		cout<<ANS<<endl;
	}
return 0;
}








