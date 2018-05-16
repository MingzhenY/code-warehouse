#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
#include <cstring>
#define maxn 200007
using namespace std;
int n;
int a[maxn];
int vl[maxn];
int vr[maxn];
stack<int> s;
int ans[maxn];
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
		
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;++i){
			int maxLen=vr[i]-vl[i]-1;
			ans[maxLen]=max(ans[maxLen],a[i]);
		}
		
		for(int i=n-1;i>0;--i) ans[i]=max(ans[i],ans[i+1]);
		for(int i=1;i<=n;++i){//输出答案 
			printf("%d",ans[i]);
			if(i==n) printf("\n");
			else printf(" ");
		}
	}
return 0;
}














