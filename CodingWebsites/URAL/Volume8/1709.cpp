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
//并查集 
int fa[100];
int Find(int i){
	int t=i;
	while(t!=fa[t]) t=fa[t];
	return fa[i]=t;
}
bool Is(int i,int j){
	int a=Find(i),b=Find(j);
	return a==b;
}
void Union(int i,int j){
	int a=Find(i),b=Find(j);
	if(a!=b) fa[a]=b;
}
//邻接矩阵 
char old[100][100];
char plan[100][100];
int A,D,N;
int main(void)
{freopen("1709.txt","r",stdin); 
	while(cin>>N>>D>>A){
		//读取 		
		For(i,N){
			scanf("%*c");
			For(j,N){
				scanf("%c",&old[i][j]);
				old[i][j]-=48;
			}
		}
		//建边 
		For(i,N) fa[i]=i;
		memset(plan,0,sizeof(plan));
		For(i,N){
			for(int j=i+1;j<N;j++){
				if(old[i][j]&&!Is(i,j)){//如果原来有连接并且新的两点没连接 
					 plan[j][i]=plan[i][j]=1;
					 Union(i,j);
				}
			}
		}
		For(i,N){
			for(int j=i+1;j<N;j++){
				if(!old[i][j]&&!Is(i,j)){//如果原来无连接并且新的两点没连接 
					 plan[j][i]=plan[i][j]=1;
					 Union(i,j);
				}
			}
		}
		long long ANS=0;
		For(i,N){
			For(j,N){
				switch(plan[i][j]-old[i][j]){
					case 1:plan[i][j]='a';ANS+=A;break;
					case 0:plan[i][j]='0';break;
					case -1:plan[i][j]='d';ANS+=D;break;
				}
			}
		}
		ANS/=2;
		cout<<ANS<<endl;
		For(i,N){
			For(j,N) printf("%c",plan[i][j]);
			cout<<endl;
		}
	}
return 0;
}








