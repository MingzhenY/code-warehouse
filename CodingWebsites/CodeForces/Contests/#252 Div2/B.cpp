#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define  inf  0x5fffffff
using namespace std;
int min(int a,int b) {return a<b?a:b;}
int n,v;
int a[3001];

int main(void)
{
	freopen("B.txt","r",stdin); 
	while(cin>>n>>v){
		int fa,fb;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++){
			scanf("%d%d",&fa,&fb);
			a[fa]+=fb;
		}
		int ANS=0;
		for(int i=1;i<=3000;i++){
			int C=v;
			if(a[i-1]>0) {
				int d=min(a[i-1],C);
				ANS+=d;C-=d;a[i-1]-=d;
			}
			int d=min(a[i],C);
			ANS+=d;a[i]-=d;C-=d;
		}
		if(a[3000]>0) {
			int d=min(a[3000],v);
			ANS+=d;a[3000]-=d;
		}
		cout<<ANS<<endl;
	}
return 0;
}
