#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <list>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 100007
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
using namespace std;
int n,m,q;
struct Bitmap{
	unsigned char bitmap[125];
	Bitmap(){clear();}
	int at(int pos){return (bitmap[pos/8]>>(pos%8))&1;}
	void set(int pos){bitmap[pos/8]|=(1<<(pos%8));}
	void unset(int pos){bitmap[pos/8]&=~(1<<(pos%8));}
	void clear(){memset(bitmap,0,sizeof(bitmap));}
	void show(){
		printf("Bitmap :");
		for(int i=0;i<m;++i) if(at(i)) printf("%d ",i);
		printf("\n");
	}
	int count(){
		int ANS=0;
		for(int i=0;i<125;++i){
			unsigned char t = bitmap[i];
			t = (t&85) + ((t&170)>>1);
			t = (t&51) + ((t&204)>>2);
			t = (t&15) + ((t&120)>>4);
			ANS += t;
		}
		return ANS;
	}
	void rotate(int x){
		Bitmap C;
		for(int i=0;i<m;++i) if(at(i)) C.set((i+x)%m);
		*this = C;
	}
	Bitmap operator&(Bitmap B){
		Bitmap C;
		for(int i=0;i<m;++i) if(at(i)&&B.at(i)) C.set(i);
		return C;
	}
	Bitmap operator|(Bitmap B){
		Bitmap C;
		for(int i=0;i<m;++i) if(at(i)||B.at(i)) C.set(i);
		return C;
	}
};
Bitmap PrimeBit;
void SetPrimeBit(){
	int p[1001];
	memset(p,-1,sizeof(p));
	PrimeBit.clear();
	for(int i=2;i<m;++i){
		if(~p[i]) continue;
		PrimeBit.set(i);
		for(int j=i;j<m;j+=i) p[j]=i;
	}
}
list<int> List[maxn];
int V[maxn],L[maxn],R[maxn],IP,Q[maxn];
list<int>::iterator S[maxn];int T[maxn], SP;
bool vis[maxn];
void F(int rt){
	memset(vis,0,sizeof(vis));
	IP=SP=0;
	S[++SP]=List[rt].begin();
	T[SP]=rt;
	L[rt]=++IP;
	Q[IP]=V[rt]%m;
	vis[1]=1;
	while(SP>0){
		if(S[SP]!=List[T[SP]].end()){
			rt = *(S[SP]++);
			if(vis[rt]) continue;
			else vis[rt]=1;
			S[++SP]=List[rt].begin();
			T[SP]=rt;
			L[rt]=++IP;
			Q[IP]=V[rt]%m;
		}
		else{
			R[T[SP]]=IP;
			--SP;
		}
	}
}

//Ïß¶ÎÊ÷ 
Bitmap bm[maxn<<2];
int Rotate[maxn<<2];
void PushUp(int rt){
	bm[rt]=bm[rt<<1]|bm[rt<<1|1];
}
void PushDown(int rt){
	if(Rotate[rt]){
		Rotate[rt<<1]=(Rotate[rt<<1]+Rotate[rt])%m;
		Rotate[rt<<1|1]=(Rotate[rt<<1|1]+Rotate[rt])%m;
		bm[rt<<1].rotate(Rotate[rt]);
		bm[rt<<1|1].rotate(Rotate[rt]);
		Rotate[rt]=0;
	}
}
void Build(int l,int r,int rt){
	if(l==r){
		bm[rt].clear();
		bm[rt].set(Q[l]%m);
		Rotate[rt]=0;
		return;
	}
	int m=(l+r)>>1;
	Build(ls);
	Build(rs);
	PushUp(rt);
}
void Update(int L,int R,int X,int l,int r,int rt){
	if(L <= l && r <= R){
		Rotate[rt]=(Rotate[rt]+X)%m;
		bm[rt].rotate(X%m);
		return;
	}
	PushDown(rt);
	int m=(l+r)>>1;
	if(L <= m) Update(L,R,X,ls);
	if(R >  m) Update(L,R,X,rs);
	PushUp(rt);
}
Bitmap Query(int L,int R,int l,int r,int rt){
	if(L <= l && r <= R){
		return bm[rt];
	}
	PushDown(rt);
	int m=(l+r)>>1;
	Bitmap ANS;
	if(L <= m) ANS = ANS | Query(L,R,ls);
	if(R >  m) ANS = ANS | Query(L,R,rs);
	return ANS;
} 
void Report(int l,int r,int rt){
 	printf("%d:",rt);
 	for(int i=0;i<m;++i) if(bm[rt].at(i)) printf("%d ",i);
 	printf("\n");
 	if(l==r) return;
 	int m=(l+r)>>1;
 	Report(ls);
 	Report(rs);
}
int main(void)
{
	freopen("633G.txt","r",stdin); 
	while(~scanf("%d%d",&n,&m)){
		SetPrimeBit();
		for(int i=1;i<=n;++i) List[i].clear();
		for(int i=1;i<=n;++i) scanf("%d",&V[i]);
		for(int i=1;i<n;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			List[a].push_back(b);
			List[b].push_back(a); 
		}
		//Ê÷Á´ÆÊ·Ö  
		F(1);
		
		//Ïß¶ÎÊ÷
		Build(1,n,1);
		scanf("%d",&q);
		for(int i=0;i<q;++i){
			int op,v,x;
			scanf("%d%d",&op,&v);
			if(op==1){
				scanf("%d",&x);
				Update(L[v],R[v],x%m,1,n,1);
			}
			else{
				printf("%d\n",(Query(L[v],R[v],1,n,1)&PrimeBit).count());
			}
		}
		Report(1,n,1);
		break;
	}
return 0;
}

