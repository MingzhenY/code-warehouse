/*
题目：
给定n个数，q个操作(n<=500000 q<=50000)。
操作有：
1 L R x :将[L,R]的数都加上x
2 y   询问第一个y和最后一个y的横坐标差，若不存在y则返回-1

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
struct Node{
	LL A[710];//原始 
	LL B[710];//排序
	LL Add,N;
	void Sort(){sort(B,B+N);}
	void Change(int t,LL V){//[0,t)+=V
		for(int i=0;i<t;++i) A[i]+=V;
		for(int i=0;i<N;++i) B[i]=A[i];
		sort(B,B+N);
	}
	bool Search(LL y){
		int L=0,R=N;//[L,R) last <= y
		if(B[0]>y) return false;
		while((L+1)^R){
			int M=(L+R)>>1;
			if(B[M]<=y) L=M;
			else R=M;
		}
		return B[L]==y;
	}
	int SearchL(LL y){//search y --lest most
		for(int i=0;i<N;++i) if(A[i]==y) return i;
		return -1;
	}
	int SearchR(LL y){//search y --right most
		for(int i=N-1;i>=0;--i) if(A[i]==y) return i;
		return -1;
	}
	void Show(){
		for(int i=0;i<N;++i) cout<<A[i]<<" ";cout<<endl;
		for(int i=0;i<N;++i) cout<<B[i]<<" ";cout<<endl<<endl;
	}
}X[710]; 
int D;//block size
int k,r;//[0,k)+[k,r)
int n,q;
void Inc(int x,LL v){//Increase [0,x] with v
	int G=x/D,R=x%D+1;
	for(int i=0;i<G;++i) X[i].Add+=v;
	X[G].Change(R,v);
}
void Work1(int L,int R,LL v){//Increase [L,R] with X
	Inc(R,v);
	if(L) Inc(L-1,-v);
}
int Work2(LL y){//find first and last position of y 
	int Lk=-1,Rk=-1;
	for(int i=0;i<=k;++i){
		if(X[i].Search(y-X[i].Add)){
			if(!~Lk) Lk=i*D+X[i].SearchL(y-X[i].Add);
			Rk=i*D+X[i].SearchR(y-X[i].Add);
		}
	}
	if(~Lk) return Rk-Lk;
	else return -1;
}
int main(void)
{
	freopen("551E.txt","r",stdin);
	ios::sync_with_stdio(false);
	while(cin>>n>>q){--n;
		D=FloorSqrt(n);
		k=n/D;r=n%D+1;
		for(int i=0;i<=k;++i) X[i].N=i==k?r:D,X[i].Add=0;
		for(int i=0;i<=k;++i){
			for(int j=0;j<X[i].N;++j) {
				cin>>X[i].A[j];
				X[i].B[j]=X[i].A[j];
			}
			X[i].Sort();
		}
		for(int i=0;i<q;++i){
			int op,L,R,x,y;
			cin>>op;
			if(op==1){
				cin>>L>>R>>x;
				Work1(L-1,R-1,x);
			}
			else{
				cin>>y;
				cout<<Work2(y)<<endl;
			}
		}
	}
return 0;
}

