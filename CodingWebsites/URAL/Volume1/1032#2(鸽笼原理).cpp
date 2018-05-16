#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

int a[10001];
int b[10001];
int c[10000];
int N;

int main(void)
{freopen("1032.txt","r",stdin); 
	while(cin>>N){		
		//输入
		memset(c,0,sizeof(c));
		b[0]=0;c[0]++;
		for(int i=1;i<=N;i++){
			scanf("%d",&a[i]);
			b[i]=(b[i-1]+a[i])%N;
			c[b[i]]++;
		} 
		int T=0;
		//找到相同的余数值 
		int same,l=-1,r=-1;
		for(int i=0;i<10000;i++){
			if(c[i]>=2){
				same=i;//存在两个余数都为i 
				break;
			}
		}
		//找到l和r
		for(int i=0;i<=N;i++){//搜索所有的余数 
			if(b[i]==same){//如果余数对了，则记录 i 
				if(~l) {
					if(~r) break;
					else r=i;
				}
				else l=i;
			}
		}
		//输出 
		if(~l&&~r){
			printf("%d\n",r-l);
			for(int j=l+1;j<=r;j++){
				printf("%d\n",a[j]);
			}
		}
		else{
			printf("%d\n",0);
		}
	}
return 0;
}








