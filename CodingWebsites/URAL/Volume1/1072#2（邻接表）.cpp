#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

struct Node{
	int K;//子网数
	int sub[5];//子网
}node[90];
int N;
//最短路算法
int A[90][90];
int path[90][90];
int dis[90][90]; 
int start,end;
void F(int i){
	if(i!=path[start][i]) F(path[start][i]);
	printf("%d",i+1);
	if(i==end) printf("\n");
	else printf(" ");
}
int main(void)
{freopen("1072.txt","r",stdin); 
	while(cin>>N){
		//OUT1(N);
		For(i,N){
			For(j,N) {
				if(i==j) A[i][j]=0;
				else A[i][j]=inf;
			}
		}
//输入+预处理 
		For(i,N){//每个电脑 
			//OUT1(i+1);
			
			cin>>node[i].K;
			//OUT1(node[i].K);
			For(j,node[i].K){//每组IP 
				string s1,s2;
				cin>>s1>>s2;
				//printf("s1:");cout<<s1<<endl;
				//printf("s2:");cout<<s2<<endl;	
				//OUT2(s1.find('.'),s2.find('.')); 
				node[i].sub[j]=0;
				For(k,4){//计算子网 
					unsigned char a;
					string sub1,sub2;
					sub1.assign(s1,0,s1.find('.'));
					sub2.assign(s2,0,s2.find('.'));
					//OUT2(atoi(sub1.c_str()),atoi(sub2.c_str());
					a=atoi(sub1.c_str())&atoi(sub2.c_str());
					node[i].sub[j]|=a<<(8*(3-k));
					if(k<3){
						s1.erase(0,s1.find('.')+1);
						s2.erase(0,s2.find('.')+1);
					}
				}
				//OUT1(node[i].sub[j]);
			}
		}
		
		cin>>start>>end;start--;end--;
//建图 
		For(i,N){
			for(int j=i+1;j<N;j++){
				int T=0;
				For(k,node[i].K){
					For(s,node[j].K){
						if(node[i].sub[k]==node[j].sub[s]){
							A[i][j]=A[j][i]=1;
							//OUT2(i+1,j+1);
							T=1;break;
						}
					}
					if(T) break;
				}
			}
		}
//计算 
		For(i,N){
			For(j,N) dis[i][j]=A[i][j];
		}
		For(i,N){
			For(j,N){
				path[i][j]=i;
			}
		}
		For(k,N){
			For(i,N){
				For(j,N){
					if(dis[i][k]+dis[k][j]<dis[i][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
						path[i][j]=path[k][j];
					}
				}
			}
		}
//输出 
		if(dis[start][end]<inf) {
			cout<<"Yes"<<endl;
			F(end);
		}
		else cout<<"No"<<endl; 
	}
return 0;
}








