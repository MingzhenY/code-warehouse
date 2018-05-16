/*
n q  (n<=500000,q<=50000)
n 个 a  
q个询问
1 L R x
2 y 询问 

2

0
-1
*/ 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <cstring>
#include <algorithm>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 500007
#define LL long long
using namespace std;
LL FloorSqrt(LL x){
	LL L=1,R=708,M;//[L,R) last M*M <=x;
	while((L+1)^R){
		M=(L+R)>>1;
		if(M*M <= x) L=M;
		else R=M;
	}
	return L;
}
LL A[maxn];//原始序列 
LL B[maxn];//分块排序 
LL Add[710];//块增加标记 
int D;//block size
int k,r;//[0,k)+[k,r)
int n,q;
void Update(int X,int V){//[0..X]+=V
	int G=X/D,R=X%D;
	int Lx=G*D,Nx=G==k?r+1:D;
	for(int i=0;i<G;++i) Add[i]+=V;
	for(int i=Lx;i<=X;++i) A[i]+=V;
	for(int i=Lx;i<Lx+Nx;++i) B[i]=A[i];
	sort(B+Lx,B+Lx+Nx);
}
void Change(int L,int R,int V){
	Update(R,V);
	if(L>1) Update(L-1,-V);
}
int Search(int l,int r,int y){
	int L=l,R=r;//[L,R) last <= y
	if(B[L]>y) return -1;
	while((L+1)^R){
		int M=(L+R)>>1;
		if(B[M]<=y) L=M;
		else R=M;
	}
	if(B[L]==y) return 1;
	else return -1;
}
int Query(int y){
	bool Found=false;
	int Li=-1,Ri=-1;
	for(int i=0;i<k;++i){
		int T=Search(i*D,i*D+D,y);
		if(~T){
			if(!~Li) Li=i;
			Ri=i;
		}
	}
	int T=Search(k*D,r+1,y);
	if(~T){
		if(!~Li) Li=k;
		Ri=k;
	}
	if(!Found) return -1;
	int Lx=Li*D,Rx=Li==k?r+1:D;
	for(int i=Lx;i<Rx;++i) if(A[i]==y) Li=i;
	Lx=Ri*D,Rx=Ri==k?r+1:D;
	for(int i=Lx;i<Rx;++i) if(A[i]==y) Ri=i;
	return Ri-Li;
}
int main(void)
{
	freopen("551E.txt","r",stdin);
	ios::sync_with_stdio(false);
	while(cin>>n>>q){
		D=FloorSqrt(n);
		k=n/D;r=n%D;
		memset(Add,0,sizeof(Add));
		for(int i=0;i<n;++i){
			cin>>A[i];
			B[i]=A[i];
		} 
		OUT1(1);
		for(int i=0;i<q;++i){
			OUT1(2);
			int op,l,r,x,y;
			cin>>op;
			if(op==1){OUT1(3);
				cin>>l>>r>>x;
				Change(l,r,x);OUT1(4);
			}
			else{
				cin>>y;OUT1(5);
				cout<<Query(y)<<endl;OUT1(6);
			}
		}
	}
	
	
return 0;
}

