#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 100007
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
using namespace std;
//std
int n,q;
char str[maxn];

//segment tree
struct Node{
	int d[26];//计数排序 
	int D;//总数
	bool sorted;//是否排好序 
	bool Inc;//是否升序
	void Insert(int v){ 
		memset(d,0,sizeof(d));
		D=d[v]=1;
		sorted=false;
	}
	void Take(bool Left,int N){//取本区间的N个数，Left指示从左开始还是从右开始 
		D=N;
		if(Left){
			for(int i=0;i<26;++i){
				if(N>=d[i]) N-=d[i];
				else{d[i]=N;N=0;}
			}
		}
		else{
			for(int i=25;i>=0;--i){
				if(N>=d[i]) N-=d[i];
				else{d[i]=N;N=0;}
			}
		}
	}
	void Drop(bool Left,int N){//去掉本区间的N个数，Left指示从左开始还是从右开始 
		D=D-N;
		if(Left){
			for(int i=0;i<26;++i){
				if(N>=d[i]) N-=d[i],d[i]=0;
				else{d[i]-=N;N=0;}
			}
		}
		else{
			for(int i=25;i>=0;--i){
				if(N>=d[i]) N-=d[i],d[i]=0;
				else{d[i]-=N;N=0;}
			}
		}
	}
	Node operator +(const Node &B)const{//重载加法，更新节点 
		Node C;
		C.sorted=false;
		for(int i=0;i<26;++i) C.d[i]=d[i]+B.d[i];
		C.D=D+B.D;
		return C;
	}
	void show(){
		printf("D=%d\n",D);
		for(int i=0;i<26;++i) {
			if(d[i]) printf("d[%d]=%d\n",i,d[i]);
		}
	}
}ST[maxn<<2];
void PushDown(int rt){//下推标记 
	Node &L=ST[rt<<1],&R=ST[rt<<1|1];
	if(ST[rt].sorted){
		int N=L.D;
		L=ST[rt];
		L.Take(ST[rt].Inc,N);
		N=R.D;
		R=ST[rt];
		R.Take(!ST[rt].Inc,N);
		ST[rt].sorted=false;
	}
}
void Build(int l,int r,int rt){//建树 
	if(l==r){ST[rt].Insert(str[l]-'a');return;}
	int m=(l+r)>>1;
	Build(ls);
	Build(rs);
	ST[rt]=ST[rt<<1]+ST[rt<<1|1];
}
Node Query(int L,int R,int l,int r,int rt){
	if(L <= l && r <= R){
		return ST[rt];
	}
	PushDown(rt);
	int m=(l+r)>>1;
	Node LANS,RANS; 
	int X=0;
	if(L <= m) LANS=Query(L,R,ls),X+=1;
	if(R >  m) RANS=Query(L,R,rs),X+=2;
	if(X==1) return LANS;
	if(X==2) return RANS;
	return LANS+RANS;
}
Node Sum;
void Update(int L,int R,int l,int r,int rt){
	if(L <= l && r <= R){
		int N=ST[rt].D;
		ST[rt]=Sum;
		ST[rt].Take(Sum.Inc,N);
		Sum.Drop(Sum.Inc,N);
		return;
	}
	int m=(l+r)>>1;
	if(L <= m) Update(L,R,ls);
	if(R >  m) Update(L,R,rs);
	ST[rt]=ST[rt<<1]+ST[rt<<1|1];
}
void Sort(int L,int R,int Inc){
	Sum=Query(L,R,1,n,1);//求出区间总和 
	Sum.sorted=true;Sum.Inc=Inc;//设置标记 
	Update(L,R,1,n,1);//分配总和给各个子区间，并且向上更新 
}
void Down(int l,int r,int rt){
	if(l==r){
		for(int i=0;i<26;++i){
			if(ST[rt].d[i]){
				str[l]=i+'a';
				break;
			}
		}
		return;
	}
	PushDown(rt);
	int m=(l+r)>>1;
	Down(ls);
	Down(rs);
}
int main(void)
{
	freopen("558E.txt","r",stdin); 
	while(~scanf("%d%d",&n,&q)){
		scanf("%s",str+1);
		Build(1,n,1);
		for(int i=0;i<q;++i){
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			Sort(x,y,k);
		}
		Down(1,n,1);//下推所有标记 
		printf("%s\n",str+1);
	}
return 0;
}


