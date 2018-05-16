#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring> 
using namespace std;

int n,m,k;
struct A{
	int a[5];
	A(){memset(a,0,sizeof(a));}
	void Input(){
		for(int i=0;i<m;++i) scanf("%d",&a[i]);
	}
	A max(A t1,A t2){
		for(int i=0;i<m;++i) a[i]=t1.a[i]>t2.a[i]?t1.a[i]:t2.a[i];
		return *this;
	}
	int Sum(){
		int sum=0;
		for(int i=0;i<m;++i) sum+=a[i];
		return sum;
	}
	void Show(){
		for(int i=0;i<m;++i){
			if(i) printf(" ");
			printf("%d",a[i]);
		}
		printf("\n");
	}
};
A st[100007 <<2];
void PushUp(int rt){
	st[rt].max(st[rt<<1],st[rt<<1|1]);
}
void Build(int l,int r,int rt){
	if(l==r){
		st[rt].Input();
		return;
	}
	int m=(l+r)>>1;
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
	PushUp(rt);
}
A Query(int L,int R,int l,int r,int rt){
	if(L <= l && r <= R){return st[rt];}
	int m=(l+r)>>1;
	A X;
	if(L <= m) X.max(X,Query(L,R,l,m,rt<<1));
	if(R >  m) X.max(X,Query(L,R,m+1,r,rt<<1|1));
	return X;
}
int main(void)
{
	freopen("514D.txt","r",stdin); 
	while(~scanf("%d%d%d",&n,&m,&k)){
		Build(1,n,1);
		int L=1,R=1;//Çø¼ä [L..R)
		A ANS;int Length=0; 
		A Cur;
		while(L <=n){
			if(L==R){
				if(R==n+1) break;
				else {++R;continue;}
			}
			Cur=Query(L,R-1,1,n,1);
			int S=Cur.Sum();
			if(S <=k&&R-L>Length){
				Length=R-L;
				ANS=Cur;
			}
			if(S <=k&&R <=n) ++R;
			else ++L;
		}
		ANS.Show();
	}
	
return 0;
}














