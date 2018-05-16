#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
struct Node{
	vector<int> Up;
	vector<int> cost;
	Node(){}
}node[31][30];

int N;
int DFS(int level,int i){
	if(level==N) return 0;
	int ANS=inf;
	For(j,node[level][i].Up.size()){
		int to=node[level][i].Up[j];
		int v=node[level][i].cost[j];
		ANS=min(ANS,v+DFS(level+1,to));
	}
	return ANS;
}
int main(void)
{freopen("1210.txt","r",stdin); 
	while(cin>>N){
		//读取 
		//For(i,31) For(j,30) node[i][j].Up.clear(),node[i][j].cost.clear();
		FOR(i,N){
			int Planet;scanf("%d",&Planet);
			For(j,Planet){
				int a,b;
				while(cin>>a&&a){
					cin>>b;
					node[i-1][a-1].Up.push_back(j);
					node[i-1][a-1].cost.push_back(b);
				}
			}
			scanf(" %*c");
		}
		//显示
		/* 
		For(i,N){
			printf("等级：%d\n",i);
			For(j,node[i].size()){
				printf("\t星球%d:",j+1);
				For(k,node[i][j].Up.size()){
					printf("->%d[%d]",node[i][j].Up[k]+1,node[i][j].cost[k]);
				}
				cout<<endl;
			}
		}*/
		//计算
		int ANS=DFS(0,0);
		cout<<ANS<<endl;
	}

return 0;
}








