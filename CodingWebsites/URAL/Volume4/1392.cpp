#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
//结构 
int sqr(int x){return x*x;}
struct P{
	int x,y,z,r;
	void ReadIn(){scanf("%d%d%d%d",&x,&y,&z,&r);}
	bool operator*(const P &B)const{
		return sqr(x-B.x )+sqr(y-B.y)+sqr(z-B.z) <sqr(r+B.r);
	}
}p[1000];
//并查集 
int fa[1000];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void Union(int x,int y){
	int a=find(x),b=find(y);
	if(a>b){int t=a;a=b;b=t;}
	fa[b]=a;
}
int K;
//记录答案 
vector<int> V[1000];
int main(void)
{freopen("1392.txt","r",stdin); 
	while(cin>>K){
		for(int i=0;i<K;++i)	p[i].ReadIn(),fa[i]=i,V[i].clear();
		for(int i=0;i<K;++i){
			for(int j=i+1;j<K;++j){
				if(p[i]*p[j]) Union(i,j);
			}
		}
		for(int i=0;i<K;++i) V[find(i)].push_back(i);
		for(int i=0;i<K;++i){
			if(fa[i]==i){
				printf("%d",i);
				int n=V[i].size();
				for(int j=1;j<n;j++) printf(", %d",V[i][j]);
				printf("\n");
			}
		}
		break;
	}
return 0;
}








