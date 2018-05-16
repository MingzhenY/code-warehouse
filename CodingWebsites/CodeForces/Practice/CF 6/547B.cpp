#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
#define maxn 200007
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
using namespace std;
int n;
int a[maxn];
int vl[maxn];
int vr[maxn];
stack<int> s;
int ans[maxn<<2];
void PushDown(int rt){
	if(ans[rt]){
		ans[rt<<1]=max(ans[rt],ans[rt<<1]);
		ans[rt<<1|1]=max(ans[rt],ans[rt<<1|1]);
		ans[rt]=0;
	}
}
void build(int l,int r,int rt){
	if(l==r){
		ans[rt]=0;
		return;
	}
	int m=(l+r)>>1;
	build(ls);
	build(rs);
	ans[rt]=0;
}
void Add(int L,int R,int C,int l,int r,int rt){
	if(L <= l && r <= R){
		ans[rt]=max(ans[rt],C);
		return;
	}
	int m=(l+r)>>1;
	if(L <= m) Add(L,R,C,ls);
	if(R >  m) Add(L,R,C,rs);
}
void PushDownAll(int l,int r,int rt){
	if(l==r) {
		a[l]=ans[rt];
		return;
	}
	int m=(l+r)>>1;
	PushDown(rt);
	PushDownAll(ls);
	PushDownAll(rs);
}
int main(void)
{
	freopen("547B.txt","r",stdin); 
	while(~scanf("%d",&n)){
		
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		
		while(!s.empty()) s.pop();//初始化vl数组 
		for(int i=1;i<=n;++i){
			while(!s.empty()&&a[s.top()]>=a[i]) s.pop();
			if(s.empty()) vl[i]=0;
			else vl[i]=s.top();
			s.push(i);
		}
		
		while(!s.empty()) s.pop();//初始化vr数组 
		for(int i=n;i>=1;--i){
			while(!s.empty()&&a[s.top()]>=a[i]) s.pop();
			if(s.empty()) vr[i]=n+1;
			else vr[i]=s.top();
			s.push(i);
		}
		
		build(1,n,1);//初始化线段树 
		for(int i=1;i<=n;++i){
			Add(1,vr[i]-vl[i]-1,a[i],1,n,1);//操作 
		}
		PushDownAll(1,n,1);//下传所有标记并将结果存入a[i] 
		for(int i=1;i<=n;++i){//输出答案 
			printf("%d",a[i]);
			if(i==n) printf("\n");
			else printf(" ");
		}
	}
return 0;
}














