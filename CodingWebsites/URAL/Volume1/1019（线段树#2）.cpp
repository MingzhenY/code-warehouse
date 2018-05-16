#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define PN 10010  //���� 
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
using namespace std;
struct P{
	int x;
	bool operator <(const P&B)const{return x<B.x;}
}p[PN];int Pn;
struct Seg{
	int l,r;
	bool v;
	void set(int l,int r){
		this->l=l;this->r=r;
	}
}s[PN];
struct Node{//��
	int v;//��1 ��0  ��ɫ-1 
}node[PN <<2];
int N;
void PushDown(int rt){
	if(~node[rt].v){//����Ǵ�ɫ 
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
	if(L <=p[l].x && p[r].x <R){
		node[rt].v=v;
		return;
	}
	if(l==r&&p[r].x==R) return;
	PushDown(rt);
	int m=(l+r)>>1;
	if(L <=p[m].x) insert(L,R,v,ls);
	if(R > p[m].x) insert(L,R,v,rs); 
}
int Sn;
void FullSearch(int l,int r,int rt){ 
	if(l==Pn) return;
	if(l==r){
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
		//�������еĶ˵� 
		Pn=3;
		map<int,int> MP;
		p[1].x=0;
		p[2].x=1000000000;
		FOR(i,N) {
			int a,b;char c;
			scanf("%d%d %c",&s[i].l,&s[i].r,&c);
			s[i].v=c=='b';
			int I;
			//��map�����أ�ȥ���ظ��Ķ˵㡣 
			if(MP.count(s[i].l)) I=MP[s[i].l];
			else MP[s[i].l]=Pn++,I=MP[s[i].l],p[I].x=s[i].l;
			if(MP.count(s[i].r)) I=MP[s[i].r];
			else MP[s[i].r]=Pn++,I=MP[s[i].r],p[I].x=s[i].r;
		}
		MP.clear();Pn--;
		//���� 
		sort(p+1,p+Pn+1);
		//�����߶�������ʼ��Ϊ��ɫ 
		build(1,Pn,1);
		//����������ɫ 
		FOR(i,N) insert(s[i].l,s[i].r,s[i].v,1,Pn,1);//,OUT1(i),FullSearch(1,Pn,1);//OUT3(s[i].l,s[i].r,s[i].v);
		Sn=1;
		//�����������䣬����ɫ�Ĵ��� s���� 
		FullSearch(1,Pn,1);
		int Cur=1;
		//�ϲ����ڵİ�ɫ���� 
		for(int i=2;i<Sn;i++){
			if(s[Cur].r==s[i].l){
				s[Cur].r=s[i].r;
			}
			else{
				Cur++;
				s[Cur]=s[i];
			}
		}
		//������İ�ɫ���䡣 
		Seg ANS=s[1];
		for(int i=2;i<=Cur;i++){
			if(s[i].r-s[i].l>ANS.r-ANS.l){
				ANS=s[i];
			}
		}
		//����� 
		printf("%d %d\n",ANS.l,ANS.r);
	}
return 0;
}



