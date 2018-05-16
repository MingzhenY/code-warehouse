#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#define maxn 200000
#define LL long long
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
int n,m;
struct Node{
	int X,ID;
	bool operator < (const Node &B)const{return X < B.X;}
}A[maxn+7];
map<int,int> MP;
int MoveRight(int P,int Len){
	int L=P,R=n+1,M;//[L,R) last X[M]-X[P]<=Len;
	while((L+1)^R){
		M=(L+R)>>1;
		if(A[M].X-A[P].X<=Len) L=M;
		else R=M;
	}
	return L;
}
int MoveLeft(int P,int Len){
	int L=1,R=P,M;//[L,R]  first X[P]-X[M]<=Len
	while(L^R){
		M=(L+R)>>1;
		if(A[P].X-A[M].X>Len) L=M+1;
		else R=M;
	}
	return L;
}
int main(void)
{
	freopen("555D.txt","r",stdin); 
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;++i) {
			scanf("%I64d",&A[i].X);
			A[i].ID=i;
		}
		sort(A+1,A+n+1);MP.clear();
		for(int i=1;i<=n;++i) MP[A[i].ID]=i;
		//询问
		for(int i=0;i<m;++i){
			int a,l;
			scanf("%d%d",&a,&l);
			if(n==1){
				printf("1\n");
				continue;
			} 
			LL Len=l;//绳子长度
			int Now=MP[a];//当前位置
			bool Dir=Now < n;//方向：0左 1右 
			bool first=true; 
			while(1){
				if(Dir){
					int Next=MoveRight(Now,Len);
					if(Next==Now) break;
					int NLen=A[Next].X-A[Now].X;
					if(NLen*2<=Len||first) Len-=NLen,first=false;
					else{
						Len-=2*NLen;
						if(Now==1||NLen)
					}
					if(Next==PreR&&PreR!=PreL){Len%=((LL)A[PreR].X-(LL)A[PreL].X)*(2LL);}
					Now=Next;
					PreR=Now;
				}
				else{
					int Next=MoveLeft(Now,Len);
					if(Next==Now) break;
					Len-=A[Now].X-A[Next].X;
					if(Next==PreL&&PreR!=PreL){Len%=((LL)A[PreR].X-(LL)A[PreL].X)*(2LL);}
					Now=Next;
					PreL=Now; 
				}
				Dir=!Dir;
			}
			printf("%d\n",A[Now].ID);
		} 
	}
return 0;
}

