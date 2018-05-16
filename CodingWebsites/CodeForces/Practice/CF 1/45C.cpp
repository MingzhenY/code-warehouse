#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <cstring>
#define maxn 200007
#define NODE(i,j) Node(i,j,abs(A[i]-A[j]))
using namespace std;
//SBT 
queue<int> Lost;
int next[maxn],last[maxn];
struct Node{
	int L,R,D;
	Node(){}
	Node(int L,int R,int D):L(L),R(R),D(D){}
	bool operator <(const Node &B)const{return D < B.D||D==B.D&&L < B.L;}
	bool operator ==(const Node &B)const{return L==B.L&&R==B.R;}
}K[maxn];
int L[maxn],R[maxn],S[maxn],IP,T;
void zig(int &x){int t=R[x];R[x]=L[t];L[t]=x;S[t]=S[x];S[x]=S[L[x]]+S[R[x]]+1;x=t;}
void zag(int &x){int t=L[x];L[x]=R[t];R[t]=x;S[t]=S[x];S[x]=S[L[x]]+S[R[x]]+1;x=t;}
void lev(int &x,bool left){
	if(left){
		if(S[L[L[x]]]>S[R[x]]) zag(x);
		else if(S[R[L[x]]]>S[R[x]]) zig(L[x]),zag(x);
		else return;
	}
	else{
		if(S[R[R[x]]]>S[L[x]]) zig(x);
		else if(S[L[R[x]]]>S[L[x]]) zag(R[x]),zig(x);
		else return;
	}
	lev(L[x],true);lev(R[x],false);
	lev(x,true);lev(x,false);
}
void Insert(int &rt,Node X){
	if(!rt){
		if(!Lost.empty()) {rt=Lost.front();Lost.pop();}
		else rt=++IP;
		L[rt]=R[rt]=0;
		S[rt]=1;
		K[rt]=X;
		return;
	}
	X < K[rt]?Insert(L[rt],X):Insert(R[rt],X);
	++S[rt];lev(rt,X < K[rt]);
}
Node Delete(int &rt,Node X){
	Node Del;--S[rt];
	if(K[rt]==X || X < K[rt] && !L[rt] || K[rt] < X && !R[rt]){
		Del=K[rt];
		if(!L[rt]||!R[rt]){Lost.push(rt);rt=L[rt]+R[rt];}
		else K[rt]=Delete(L[rt],X);
	}
	else Del=X < K[rt]?Delete(L[rt],X):Delete(R[rt],X);
	lev(rt,K[rt] < X);
	return Del;
}
int Min(int &rt){return L[rt]?Min(L[rt]):rt;}

//信息 
int n;
int A[maxn];
char str[maxn];
int X[maxn],Y[maxn],N;
int main(void)
{
	freopen("45C.txt","r",stdin); 
	while(~scanf("%d",&n)){
		//读取输入 
		scanf("%s",str+1);
		for(int i=1;i<=n;++i) scanf("%d",&A[i]);
		//初始化SBT 
		while(!Lost.empty()) Lost.pop();
		L[0]=R[0]=S[0]=IP=T=N=0;
		//初始化next和last数组 
		for(int i=1;i<n;++i)  next[i]=i+1;next[n]=-1;
		for(int i=2;i<=n;++i) last[i]=i-1;last[1]=-1;
		//加入所有可能的配对 
		for(int i=1;i<n;++i){
			if(str[i]^str[i+1]) Insert(T,NODE(i,i+1));
		}
		//开始计算 
		while(S[T]){// last[L] L R next[R]
			//记录拿出的点 
			++N;
			int rt=Min(T);
			X[N]=K[rt].L;
			Y[N]=K[rt].R;
			//更新平衡树 
			Delete(T,K[rt]);//删除 (L,R) 
			
			if(~last[K[rt].L]) {//如果 L 前面还有 
				if(str[last[K[rt].L]]^str[K[rt].L]){
					Delete(T,NODE(last[K[rt].L],K[rt].L));//删除(last[L],L)
				}
				next[last[K[rt].L]]=next[K[rt].R];
			}
			
			if(~next[K[rt].R]){//如果 R 后面还有 
				if(str[K[rt].R]^str[next[K[rt].R]]){
					Delete(T,NODE(K[rt].R,next[K[rt].R]));//删除(R,next[R]) 
				}
				last[next[K[rt].R]]=last[K[rt].L];
			}
			
			if(~last[K[rt].L]&&~next[K[rt].R]){//如果 前后都有 
				if(str[last[K[rt].L]]^str[next[K[rt].R]]){
					Insert(T,NODE(last[K[rt].L],next[K[rt].R]));//加入(last[L],next[R]) 
				}
			}
		}
		//输出答案 
		printf("%d\n",N);
		for(int i=1;i<=N;++i){
			printf("%d %d\n",X[i],Y[i]);
		}
	}
return 0;
}

