#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,xs,ys;
int x[1000],y[1000];
int gcd(int x,int y){if(x==0) return y;return gcd(y%x,x);}
int main(void)
{
	freopen("514B.txt","r",stdin); 
	while(~scanf("%d%d%d",&n,&xs,&ys)){
		int ANS=0;
		for(int i=0;i<n;++i){
			scanf("%d%d",&x[i],&y[i]);
			x[i]-=xs;y[i]-=ys;
			if(x[i]<0){
				x[i]=-x[i];y[i]=-y[i];
			}
			if(x[i]==0&&y[i]<0) y[i]=-y[i];
			int d=gcd(x[i],y[i]);
			x[i]/=d;y[i]/=d;
			int t=0;
			for(int j=0;j<i;++j){
				if(x[i]==x[j]&&y[i]==y[j]) ++t;
			}
			if(!t) ANS++;
		}
		cout<<ANS<<endl;
	}

		
return 0;
}














