#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#define maxn 200007
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
int n,q;
int team[maxn],next[maxn];
int Find(int x){return x==team[x]?x:team[x]=Find(team[x]);}
int Union(int x,int y){team[Find(y)]=Find(x);}
void Init(){for(int i=1;i<=n;++i) team[i]=i,next[i]=i+1;}
void MergeInRange(int L,int R){
	int p=L,NextR=next[R];
	while(p < NextR){
		Union(L,p);
		int Old_p=p;
		p=next[p];
		next[Old_p]=NextR; 
	}
}
int main(void)
{
	freopen("566D.txt","r",stdin); 
	while(~scanf("%d%d",&n,&q)){
		Init();
		for(int i=0;i<q;++i){
			int type,x,y;scanf("%d%d%d",&type,&x,&y);
			switch(type){
				case 1:
					Union(x,y);break;
				case 2:
					MergeInRange(x,y);break;
				case 3:
					printf("%s\n",Find(x)==Find(y)?"YES":"NO");break;
			}
		}
	}
return 0;
}

