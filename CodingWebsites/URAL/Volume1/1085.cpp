#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
//#define ZRT
using namespace std;
//线路 
struct Node{
	vector<int> route;//线路 
}node[100];
//人 
struct People{
	int cash;
	int start;
	int ticket;
}p[100];
//最短路 
int dis[100][100];//邻接矩阵
int A[100][100];//Floyd 
//经过每站的路线。
vector <int> stop[100];
int N,M,K;
int main(void)
{freopen("1085.txt","r",stdin); 
	while(cin>>N>>M){
		//清零
		For(i,M) node[i].route.clear();
		For(i,N) stop[i].clear(); 
		//读取 
		For(i,M){
			int n,t;
			scanf("%d",&n);
			For(j,n) scanf("%d",&t),node[i].route.push_back(t-1),stop[t-1].push_back(i);
		}
		cin>>K;
		For(i,K){
			int ticket;
			scanf("%d%d%d",&p[i].cash,&p[i].start,&p[i].ticket);
			p[i].start--;
		}
		
		//建图
		For(i,M){
			For(j,M) {
				if(i==j) dis[i][j]=0;
				else dis[i][j]=inf;
			}	
		}
		For(i,N){
			if(stop[i].size()>1){
				for(int j=0;j<stop[i].size();j++){
					for(int k=0;k<stop[i].size();k++){
						dis[stop[i][j]][stop[i][k]]=4;
						dis[stop[i][k]][stop[i][j]]=4;
					}
				}
			}
		}
		//Floyd求最短路
		For(i,M){
			For(j,M){
				A[i][j]=dis[i][j];
			}
		}
		For(k,M){
			For(i,M){
				For(j,M){
					if(A[i][k]+A[k][j]<A[i][j]) A[i][j]=A[i][k]+A[k][j];
				}
			}
		}
		//计算答案 
		int ANS=inf;int T;int ANSI=-1;
		For(i,N){
			//if(stop[i].size()>1){//每个交点,计算一次答案 
				T=1;int TT=0;
				int tempANS=0;
				For(j,K){//对每个人，计算到点i的最短花费 
					if(p[j].ticket) continue;
					TT++;
					int MinCost=inf;
					For(k,stop[p[j].start].size()){//对于经过起点的每一条线路 
						For(s,stop[i].size()){//对于经过终点i的每一条线路 
							if(i!=p[j].start) MinCost=min(MinCost,A[stop[p[j].start][k]][stop[i][s]]+(stop[p[j].start][k]!=stop[i][s])*4);
							else{
								MinCost=0; 
							}
						}
					}
					//if(i==p[j].start) MinCost=0;
					if(MinCost>p[j].cash) {
						T=0;break;
					}
					//OUT3(p[j].start+1,i+1,MinCost);
					tempANS+=MinCost;
				}
				if(T&&TT){
					if(tempANS<ANS) ANS=tempANS,ANSI=i;
				}
			//}
		}
		//OUT1(ANSI);
		//判断是否联通
		if(~ANSI){
			For(i,K){
				if(p[i].ticket){
					int T=0;//搜索从ANSI到p[i].start的线路 
					For(j,stop[ANSI].size()){
						For(k,stop[p[i].start].size()){
							if(A[stop[ANSI][j]][stop[p[i].start][k]]<inf){
								T=1;break;
							}
						}
						if(T) break;
					}
					if(!T) {
						ANSI=-1;break;
					}	
				}
				
			}	
		}
		
		//输出 
		if(~ANSI){
			printf("%d %d\n",ANSI+1,ANS);
		}
		else cout<<0<<endl;
		
	}
return 0;
}








