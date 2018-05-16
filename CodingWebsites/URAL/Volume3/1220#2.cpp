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
#define BlockN 100
struct Block{
	char end;
	short int next;
	int a[BlockN];
}B[1200];
bool vis[1200];//ÊÇ·ñÕ¼ÓÃ 
struct Stack{
	short int next;
	/*
	void show(){
		int to=next;
		if(~to){
			begin:
			for(int i=0;i<B[to].end;i++){
				printf("%d ",B[to].a[i]);
			}
			if(~B[to].next){
				to=B[to].next;
				goto begin;
			}
		}
		cout<<endl;
	}*/
}S[1000];
void push(int a,int b){
	int to=S[a].next;
	if(~to){
		while(B[to].next!=-1) to=B[to].next;
		if(B[to].end<BlockN){
			B[to].a[B[to].end++]=b;
		}
		else{
			int nto=0;
			while(vis[nto]){
				nto++;
			}
			vis[nto]=1;
			B[to].next=nto;
			B[nto].end=0;B[nto].next=-1;
			B[nto].a[B[nto].end++]=b;
		}
	}
	else{
		int nto=0;
		while(vis[nto]){
			nto++;
		}
		vis[nto]=1;
		S[a].next=nto;
		B[nto].end=0;B[nto].next=-1;
		B[nto].a[B[nto].end++]=b;
	}
}
int pop(int a){
	int ANS=0;
	//OUT2(a,S[a].next);
	if(~S[a].next){
		int to=S[a].next;
		while(~B[to].next) if(B[B[to].next].end) to=B[to].next;
		if(~B[to].next&&!B[B[to].next].end) vis[B[to].next]=0,B[to].next=-1;
		//OUT2(to,B[to].end);
		ANS=B[to].a[--B[to].end];
	}
	return ANS;
}
int N;
int main(void)
{freopen("1220.txt","r",stdin); 
	while(~scanf("%d",&N)){
		For(i,N)S[i].next=-1;
		For(i,1200) B[i].end=0,B[i].next=-1;
		For(i,N){
			char s[100];scanf("%s",s);
			if(s[1]=='U'){
				int a,b;
				scanf("%d%d",&a,&b);
				push(a-1,b);
				//printf("push(%d,%d):\n",a-1,b);
				//S[a-1].show();
			}
			else{
				int a;
				scanf("%d",&a);
				int ANS=pop(a-1);
				//printf("pop(%d):\n",a-1);
				//S[a-1].show();
				printf("%d\n",ANS);
			}
		}
	}
return 0;
}








