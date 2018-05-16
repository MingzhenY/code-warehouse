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
	int M=P;
	while(M < n&&X[M+1]-X[P]<=Len) M++;
	return M;
}
int MoveLeft(int P,int Len){
	int M=P;
	while(M > 1&&X[P]-X[M-1]<=Len) M--;
	return M;
}
int main(void)
{
	freopen("555D.txt","r",stdin); 
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;++i) scanf("%d",&X[i]);
		//询问
		for(int i=0;i<m;++i){
			int a,l;
			scanf("%d%d",&a,&l);
			if(n==1){
				cout<<1<<endl;
				continue;
			} 
			int Len=l;//绳子长度
			bool Dir=a<n;//方向：0左 1右 
			int Now=a;//当前位置
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

