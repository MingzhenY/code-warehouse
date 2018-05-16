#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define maxn 200007
#define maxv 500007 
using namespace std;
int maxprime[maxv];/* maxprime[i]是i的质因数中最大的一个 */
int u[maxv];/* 莫比乌斯函数 */
bool On[maxn];/* 记录a[i]是否在集合内 */
int d[maxv];/* 记录d[k]表示集合内有多少个值是k的倍数 */
int a[maxn];
int n,q;
long long K;
void Init(){/* 初始化maxprime和u数组 */
	memset(maxprime,-1,sizeof(maxprime));
	for(int i=1;i<maxv;++i) u[i]=1;
	for(int i=2;i<maxv;++i){
		if(~maxprime[i]) continue;
		for(int j=1,v=i;v<maxv;++j,v+=i){
			maxprime[v]=i;
			u[v]=j%i==0?0:-u[v];
		}
	}
}
bool Add(int x){/* 加入x */ 
	int fac[6],facn=0;
	while(x>1){/* 质因数分解 */
		int p=maxprime[x];
		fac[facn++]=p;
		do x/=p;
		while(x%p==0);
	}
	int MAX=1<<facn;
	for(int i=0;i<MAX;++i){/* 调整所有的d值以及K值 */
		int t=i,v=1;
		for(int j=0;j<facn;++j,t>>=1){
			if(t&1) v*=fac[j]; 
		}
		K+=d[v]*u[v];
		++d[v];
	}
	return true;
}
bool Remove(int x){/* 删除x */ 
	int fac[6],facn=0;
	while(x>1){/* 质因数分解 */
		int p=maxprime[x];
		fac[facn++]=p;
		do x/=p;
		while(x%p==0);
	}
	int MAX=1<<facn;
	for(int i=0;i<MAX;++i){/* 调整所有的d值以及K值 */
		int t=i,v=1;
		for(int j=0;j<facn;++j,t>>=1){
			if(t&1) v*=fac[j]; 
		}
		--d[v];
		K-=d[v]*u[v];
	}
	return true;
}
int main(void)
{
	Init();
	freopen("547C.txt","r",stdin); 
	while(~scanf("%d%d",&n,&q)){
		memset(On,0,sizeof(On));//On数组，表示a[i]是否在集合中 
		memset(d,0,sizeof(d));//d[k]表示集合中有多少个是k的倍数 
		K=0;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=0;i<q;++i){
			int x;scanf("%d",&x);
			On[x]=On[x]?Remove(a[x]),false:Add(a[x]),true;
			printf("%I64d\n",K); 
		}
	}
return 0;
}














