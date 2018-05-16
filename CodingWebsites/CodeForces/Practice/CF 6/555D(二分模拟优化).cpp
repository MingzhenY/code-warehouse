#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
#define maxn 200000
#define LL long long
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
int n,m;
struct Node{
	int ID;
	LL X;
	bool operator < (const Node &B)const{return X < B.X;}
}X[maxn+7];
map<int,int> MP;
int MoveRight(int P,int Len){
	int L=P,R=n+1,M;//[L,R) last X[M]-X[P]<=Len;
	while((L+1)^R){
		M=(L+R)>>1;
		if(X[M].X-X[P].X<=Len) L=M;
		else R=M;
	}
	return L;
}
int MoveLeft(int P,int Len){
	int L=1,R=P,M;//[L,R]  first X[P]-X[M]<=Len
	while(L^R){
		M=(L+R)>>1;
		if(X[P].X-X[M].X>Len) L=M+1;
		else R=M;
	}
	return L;
}
int main(void)
{
	freopen("555D.txt","r",stdin); 
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;++i) {
			scanf("%I64d",&X[i].X);
			X[i].ID=i;
		}
		sort(X+1,X+n+1);MP.clear();
		for(int i=1;i<=n;++i) MP[X[i].ID]=i;
		//询问
		for(int i=0;i<m;++i){
			int a,l;
			scanf("%d%d",&a,&l);
			if(n==1){
				cout<<1<<endl;
				continue;
			} 
			LL Len=l;//绳子长度
			int Now=MP[a];//当前位置
			bool Dir=Now < n;//方向：0左 1右 
			int PreL=Now,PreR=Now;//左右历史 
			while(1){
				if(Dir){
					int Next=MoveRight(Now,Len);
					if(Next==Now) break;
					Len-=X[Next].X-X[Now].X;
					if(Next==PreR&&PreR!=PreL){Len%=(X[PreR].X-X[PreL].X)<<1;}
					Now=Next;
					Dir=!Dir;
					PreR=Now;
				}
				else{
					int Next=MoveLeft(Now,Len);
					if(Next==Now) break;
					Len-=X[Now].X-X[Next].X;
					if(Next==PreL&&PreR!=PreL){Len%=(X[PreR].X-X[PreL].X)<<1;}
					Now=Next;
					Dir=!Dir;
					PreL=Now; 
				}	
			}
			printf("%d\n",X[Now].ID);
		} 
		
	}
return 0;
}

