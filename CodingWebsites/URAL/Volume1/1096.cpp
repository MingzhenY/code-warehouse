#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 1007
using namespace std;
struct ArcNode{
	int to;
	ArcNode *next;
};
struct Node{
	int a,b;
	ArcNode *List;
	int pre,d;
	void init(int x,int y){
		a=x;b=y;
		pre=-1;d=-1;
		List=NULL;
	}
}node[maxn];
void Arc(int from,int to){
	ArcNode *temp=new ArcNode;
	temp->to=to;
	temp->next=node[from].List;
	node[from].List=temp;
}
int K,Target;
queue<int> Q; 
void F(int x){
	if(x) F(node[x].pre),printf("%d\n",x);;
}
int main(void)
{freopen("1096.txt","r",stdin); 
	while(cin>>K){
		// ‰»Î 
		int x,y;
		for(int i=1;i<=K;++i){
			scanf("%d%d",&x,&y);
			node[i].init(x,y);
		}
		scanf("%d%d%d",&Target,&x,&y);
		node[0].init(x,y);
		//Ω®Õº 
		for(int i=0;i<=K;++i){
			for(int j=0;j<=K;++j){
				if(i==j) continue;
				if(node[i].a==node[j].a||node[i].b==node[j].a) {
					Arc(i,j);
				}
			}
		}
		
		//º∆À„ 
		while(!Q.empty()) Q.pop();
		
		node[0].d=0;int T=-1;
		Q.push(0);
		while(!Q.empty()){
			int cnt=Q.front();Q.pop();
			ArcNode *temp=node[cnt].List;
			while(temp){
				if(!~node[temp->to].d){
					node[temp->to].d=node[cnt].d+1;
					node[temp->to].pre=cnt;
					Q.push(temp->to);
					if(node[temp->to].a==Target||node[temp->to].b==Target) {
						T=temp->to;
						break;
					}
				}
				temp=temp->next;
			}
			if(~T) break;
		}
		if(~T){
			printf("%d\n",node[T].d);
			F(T);
		}
		else printf("IMPOSSIBLE\n");
	}
return 0;
}








