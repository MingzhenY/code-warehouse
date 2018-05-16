#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <list>
#include <bitset>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 100007
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
using namespace std;
int n,m,q;
//λͼ�ṹ 
typedef  bitset<1000> Bitmap;

Bitmap PrimeBit;//�������������λͼ 
void SetPrimeBit(){//ɸ�����������õ�����λͼPrimeBit (ֻ����С��m������) 
	int p[1001];
	memset(p,-1,sizeof(p));
	PrimeBit.reset();
	for(int i=2;i<m;++i){
		if(~p[i]) continue;
		PrimeBit.set(i);
		for(int j=i;j<m;j+=i) p[j]=i;
	}
}
//���߱�͵������List 
list<int> List[maxn];
//��i���ڵ�ļ�ֵΪV[i]������Ϊ�����Ӧ�������е��±�Ϊ [ L[i],R[i] ] 
//IP����һ������������������Q�Ľ��ͣ�Q[L[i]]=V[i] 
int V[maxn],L[maxn],R[maxn],IP,Q[maxn];
//�����������ڻ���Ϊ������ʵ����һ��DFS������д�ĵݹ鲻���ݹ���ƻᱬջ 
bool vis[maxn];
void F(int rt){
	for(list<int>::iterator it=List[rt].begin();it!=List[rt].end();++it){
		if(vis[*it]) continue;
		else vis[*it]=1;
		L[*it]=++IP;
		Q[IP]=V[*it];
		F(*it);
	}
	R[rt]=IP;
}



//�߶��� 
Bitmap bm[maxn<<2];
int Rotate[maxn<<2];
void PushUp(int rt){
	bm[rt]=bm[rt<<1]|bm[rt<<1|1];
}
void PushDown(int rt){
	if(Rotate[rt]){
		Rotate[rt<<1]=(Rotate[rt<<1]+Rotate[rt])%m;
		Rotate[rt<<1|1]=(Rotate[rt<<1|1]+Rotate[rt])%m;
		bm[rt<<1]=(bm[rt<<1]<<Rotate[rt])|(bm[rt<<1]>>(m-Rotate[rt]));
		bm[rt<<1|1]=(bm[rt<<1|1]<<Rotate[rt])|(bm[rt<<1|1]>>(m-Rotate[rt]));
		Rotate[rt]=0;
	}
}
void Build(int l,int r,int rt){
	if(l==r){
		bm[rt].reset();
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
		X%=m;
		bm[rt]=(bm[rt]<<X)|(bm[rt]>>(m-X));
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
		//����Ϊ�� 
		memset(vis,0,sizeof(vis));
		vis[1]=1;IP=0;
		F(1);

		//�߶���
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
	}
return 0;
}

