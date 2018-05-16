#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define PN 10010  //点数 
#define PM 5010   //线段数量 
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
using namespace std;
struct P{
	int x;
	vector<int> V;//属于的区间 
	bool operator <(const P&B)const{return x<B.x;}
}p[PN];int Pn;
struct Seg{
	int l,r;
	bool v;
	void set(int l,int r){
		this->l=l;this->r=r;
	}
}s[PN];
struct Node{//点
	int v;//黑1 白0  混色-1 
}node[PN <<2];
int N;
void PushDown(int rt){
	if(~node[rt].v){//如果是纯色 
		node[rt<<1].v=node[rt].v;
		node[rt<<1|1].v=node[rt].v;
		node[rt].v=-1;
	}
}
void build(int l,int r,int rt){
	if(l==Pn) return;
	if(l==r){
		node[rt].v=0;
		return;
	}
	int m=(l+r)>>1;
	build(ls);
	build(rs);
	node[rt].v=0;
}
void insert(int L,int R,bool v,int l,int r,int rt){
	if(l==Pn) return;
	//if(L==2) OUT2(l,r);
	if(L <=l && r <=R){
		//if(L==2) printf("set:"),OUT2(l,r);
		node[rt].v=v;
		return;
	}
	PushDown(rt);
	int m=(l+r)>>1;
	if(L <=m) insert(L,R,v,ls);
	if(R > m) insert(L,R,v,rs); 
}
int Sn;
void FullSearch(int l,int r,int rt){
	if(l==Pn) return;
	if(l==r){
		//OUT3(p[l].x,p[l+1].x,node[rt].v);
		if(!node[rt].v){
			s[Sn++].set(p[l].x,p[l+1].x);
		}
		return;
	}
	PushDown(rt);
	int m=(l+r)>>1;
	FullSearch(ls);
	FullSearch(rs);
}
int main(void)
{freopen("1019.txt","r",stdin); 
	while(cin>>N){
		Pn=3;
		map<int,int> MP;
		p[1].x=0;
		p[2].x=1000000000;
		FOR(i,N) {
			int a,b;char c;
			scanf("%d%d %c",&s[i].l,&s[i].r,&c);
			s[i].v=c=='b';
			int I;
			if(MP.count(s[i].l)) I=MP[s[i].l];
			else MP[s[i].l]=Pn++,I=MP[s[i].l],p[I].x=s[i].l;
			p[I].V.push_back(i);
			if(MP.count(s[i].r)) I=MP[s[i].r];
			else MP[s[i].r]=Pn++,I=MP[s[i].r],p[I].x=s[i].r;
			p[I].V.push_back(-i);
			
		}
		MP.clear();Pn--;
		sort(p+1,p+Pn+1);
		FOR(i,Pn) {
			//OUT2(i,p[i].x);
			For(j,p[i].V.size()){
				//printf("\t");OUT2(j,p[i].V[j]);
				if(p[i].V[j]>0) s[p[i].V[j]].l=i;
				else s[-p[i].V[j]].r=i;
			}
			p[i].V.clear();
		}
		build(1,Pn,1);
		//FOR(i,N){
		//	OUT3(s[i].l,s[i].r,s[i].v);
		//}
		FOR(i,N) insert(s[i].l,s[i].r-1,s[i].v,1,Pn,1);//,OUT1(i),FullSearch(1,Pn,1);//OUT3(s[i].l,s[i].r,s[i].v);
		Sn=1;
		FullSearch(1,Pn,1);
		int Cur=1;
		for(int i=2;i<Sn;i++){
			if(s[Cur].r==s[i].l){
				s[Cur].r=s[i].r;
			}
			else{
				Cur++;
				s[Cur]=s[i];
			}
		}
		Seg ANS=s[1];
		for(int i=2;i<=Cur;i++){
			if(s[i].r-s[i].l>ANS.r-ANS.l){
				ANS=s[i];
			}
		}
		printf("%d %d\n",ANS.l,ANS.r);
	}
return 0;
}



