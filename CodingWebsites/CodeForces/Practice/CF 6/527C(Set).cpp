#include <iostream>
#include <cstdio>
#include <cstring>
#include <set> 
#define maxn 200001
using namespace std;
set<int>::iterator i,j;
set<int> H,V;
int Hn[maxn],Vn[maxn];
void Cut(set<int> &A,int *N,int v){
	A.insert(v);i=j=A.find(v);
	--i,++j,--N[*j-*i];
	++N[v-*i],++N[*j-v];
}
int main(void)
{
	freopen("527C.txt","r",stdin); 
	int w,h,n;
	while(cin>>w>>h>>n){
		memset(Hn,0,sizeof(Hn));H.clear();H.insert(h);H.insert(0);Hn[h]=1;
		memset(Vn,0,sizeof(Vn));V.clear();V.insert(w);V.insert(0);Vn[w]=1;
		int MaxH=h,MaxW=w; 
		for(int i=0;i<n;++i){
			//读取数据 
			char x;int v;
			scanf(" %c%d",&x,&v);
			//切割 
			x=='H'?Cut(H,Hn,v):Cut(V,Vn,v);
			//输出 
			while(!Hn[MaxH]) --MaxH;
			while(!Vn[MaxW]) --MaxW;
			printf("%I64d\n",(long long)MaxH*MaxW);
		}
	}
return 0;
}














