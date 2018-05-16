#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 105
using namespace std;

int p[maxn],v[maxn];
int Same[maxn],Dif[maxn];
int Find(int x){
	int tempv=0,a=x;
	while(a!=p[a]) tempv^=v[a],a=p[a];
	p[x]=a;v[x]=tempv;return a;
}
int ERR;
void Union(int x,int y,int V){
	int a=Find(x),b=Find(y);
	if(a==b){
		if(v[x]^v[y]==0) ERR=1; 
	}
	else{
		p[a]=b;v[a]=V^v[x]^v[y];
	}
}
int n,m;
int dp[105][105];//dp[i][j]表示第i个数选择
int op[105][105];//op[i][j]表示dp[i][j]是经过 op[i][j]这个选择而来的
int pre[105][105];//pre[i][j]表示dp[i][j] 的前一个的高度 
int k[105][2];//转换后的俩值 
int org[105];//原坐标 
int main(void)
{freopen("1156.txt","r",stdin); 
	while(~scanf("%d%d",&n,&m)){
		//初始化 
		ERR=0;
		for(int i=1;i<=2*n;++i) Same[i]=1,Dif[i]=0,p[i]=i,v[i]=0;
		//建图 
		for(int i=0;i<m;++i){
			int x,y;scanf("%d%d",&x,&y);
			Union(x,y,1);
		}
		//更新集合数据 
		int index=0; 
		for(int i=1;i<=2*n;++i){
			int f=Find(i);
			if(f!=i){
				if(v[i]) ++Dif[f];
				else ++Same[f];
				Same[i]=Dif[i]=0;
			}
			else{
				org[++index]=i;
			}
		}
		
		//DP 
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=index;++i){
			k[i][0]=Same[org[i]];
			k[i][1]=Dif[org[i]];
		}
		dp[0][0]=1;
		for(int i=0;i<index;++i){
			for(int j=0;j<=n;++j){
				if(!dp[i][j]) continue;
				for(int t=0;t<2;++t){
					int J=j+k[i+1][t];
					if(J <=n&&!dp[i+1][J]){
						dp[i+1][J]=1;
						pre[i+1][J]=j;
						op[i+1][J]=t;
					}
				}
			}
		}
		//判断有无解 
		if(dp[index][n]&&!ERR){//有解
			//集合特征元素分组 
			int I=index,J=n;
			while(I){
				op[I][J];//I属于的类别 
				org[I];//I的原点
				v[org[I]]=op[I][J];
				//printf("点%d:(同:%d 异:%d)===%d\n",org[I],k[I][0],k[I][1],op[I][J]);
				J=pre[I--][J];
			}
			//集合成员元素分组 
			vector<int> Team1,Team2;
			for(int i=1;i<=2*n;++i){
				if(p[i]==i) {
					if(v[i]) Team2.push_back(i);
					else Team1.push_back(i);
				} 
				else{
					if(v[p[i]]^v[i]) Team2.push_back(i);
					else Team1.push_back(i);
				}
			}
			//输出 
			for(int i=0;i<Team1.size();++i){
				printf("%d",Team1[i]);
				if(i+1==Team1.size()) printf("\n");
				else printf(" ");
			}
			for(int i=0;i<Team2.size();++i){
				printf("%d",Team2[i]);
				if(i+1==Team2.size()) printf("\n");
				else printf(" ");
			}
		}
		else{
			printf("IMPOSSIBLE\n");
		}
	}
return 0;
}








