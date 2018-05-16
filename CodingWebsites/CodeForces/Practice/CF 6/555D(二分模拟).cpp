#include <iostream>
#include <cstdio>
#include <cmath>
#define maxn 200000
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
int n,m;
int X[maxn+7];
int MoveRight(int P,int Len){
	int L=P,R=n+1,M;//[L,R) last X[M]-X[P]<=Len;
	while((L+1)^R){
		M=(L+R)>>1;
		if(X[M]-X[P]<=Len) L=M;
		else R=M;
	}
	return L;
}
int MoveLeft(int P,int Len){
	int L=1,R=P,M;//[L,R]  first X[P]-X[M]<=Len
	while(L^R){
		M=(L+R)>>1;
		if(X[P]-X[M]>Len) L=M+1;
		else R=M;
	}
	return L;
}
int main(void)
{
	freopen("555D.txt","r",stdin); 
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;++i) scanf("%d",&X[i]);
		//ѯ��
		for(int i=0;i<m;++i){
			int a,l;
			scanf("%d%d",&a,&l);
			if(n==1){
				cout<<1<<endl;
				continue;
			} 
			int Len=l;//���ӳ���
			bool Dir=a<n;//����0�� 1�� 
			int Now=a;//��ǰλ��
			bool Finish=false;
			while(!Finish){
				if(Dir){
					int Next=MoveRight(Now,Len);
					if(Next==Now) break;
					Len-=X[Next]-X[Now];
					Now=Next;
					Dir=!Dir;
				}
				else{
					int Next=MoveLeft(Now,Len); 
					if(Next==Now) break;
					Len-=X[Now]-X[Next];
					Now=Next;
					Dir=!Dir;
				}
			}
			printf("%d\n",Now);
		} 
	}
return 0;
}

