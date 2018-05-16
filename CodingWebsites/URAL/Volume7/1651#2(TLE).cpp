#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 100001
using namespace std;
int getint()
{
    int a,f;
    while(a=getchar(),!(a>='0'&&a<='9'));
    a-='0';
    while(f=getchar(),f>='0'&&f<='9')
        a=a*10+f-'0';
    return a;
}
//建图方法二：按列表位置建图……（按原图建图不会算） 

int n;
int chain[maxn];
int ans[maxn];
//图
struct ArcNode{
	int to,value;
	ArcNode *next;
}; 
struct Node{
	ArcNode *List;
	int path,dis;//编号，路径，最短路 
}node[maxn];
void Show(int k){
	printf("\t节点%d=> dis:%d path=%d\n",k,node[k].dis,node[k].path);
}
ArcNode *val[10001];
void Arc(int from,int to,int value){
	ArcNode *temp=new ArcNode;
	temp->to=to;temp->value=value; 
	temp->next=node[from].List;
	node[from].List=temp;
}
void Cal(int t){
	ArcNode *temp=node[t].List;
	while(temp){
		if(!~node[temp->to].dis||node[temp->to].dis>node[t].dis+temp->value){
			node[temp->to].dis=node[t].dis+temp->value;
			node[temp->to].path=t;
			//Show(temp->to);
		}
		temp=temp->next;
	}
}
int main(void)
{freopen("1651.txt","r",stdin); 
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;++i) node[i].List=NULL,node[i].dis=-1;//初始化 
		memset(val,0,sizeof(val));
		for(int i=1;i<=n;++i){chain[i]=getint();}//scanf("%d",&chain[i]);}//读取数据 
		for(int i=1;i<n;++i) {//建边
			Arc(i,i+1,1);
			ArcNode *temp=val[chain[i]];
			while(temp){
				Arc(temp->to,i,0);
				temp=temp->next;
			}
			temp=new ArcNode;
			temp->to=i;
			temp->next=val[chain[i]];
			val[chain[i]]=temp;
		}
		ArcNode *temp=new ArcNode;
			temp->to=n;
			temp->next=val[chain[n]];
			val[chain[n]]=temp;
		
		//计算
		node[1].dis=0;
		for(int i=1;i<=n;++i) Cal(i);
		temp=val[chain[n]];int T=-1,Min=inf;
		while(temp){
			if(node[temp->to].dis<Min){
				Min=node[temp->to].dis;
				T=temp->to;
			}
			temp=temp->next;
		}
		//输出 
		int I=0;
		while(T>1){
			if(chain[T]!=chain[node[T].path])ans[++I]=chain[T];
			T=node[T].path;
		}
		ans[++I]=chain[T];
		for(int i=I;i>0;--i) {
			printf("%d",ans[i]);
			if(i==1) printf("\n");
			else printf(" ");
		}
		for(int i=1;i<=n;++i){
			while(node[i].List){
				ArcNode *temp=node[i].List;
				node[i].List=node[i].List->next;
				delete temp;
			}
		} 
	}
return 0;
}








