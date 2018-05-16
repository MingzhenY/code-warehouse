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
struct ArcNode{
	int to;
	ArcNode *next;
}; 
struct Node{
	int K;//子网数
	int sub[5];//子网
	ArcNode *List;
}node[90];
void DArc(int from,int to){
	ArcNode *temp=new ArcNode;
	temp->to=to;
	temp->next=node[from]=List;
	node[from].List=temp;
	temp=new ArcNode;
	temp->to=from;
	temp->next=node[to].List;
	node[to].List=temp;
}
int N;
//最短路算法
int A[90][90];
int path[90];
int dis[90]; 
int main(void)
{freopen("1072.txt","r",stdin); 
	while(cin>>N){
		//OUT1(N);
		
//输入+预处理 
		For(i,N){//每个电脑 
			//OUT1(i+1);
			node[i].List=NULL;
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
		int start,end;
		cin>>start>>end;start--;end--;
//建图 
		For(i,N){
			for(int j=i+1;j<N;j++){
				int T=0;
				For(k,node[i].K){
					For(s,node[j].K){
						if(node[i].sub[k]==node[j].sub[s]){
							DArc(i,j);T=1;break;
						}
					}
					if(T) break;
				}
			}
		}
//计算 
		memset(dis,-1,sizeof(dis));
		dis[start]=0;path[start]=start;
		For(i,N){
			if(!~dis[i]){//找到没有定距离的点 
				For(j,N){
					if(~dis[j]){//对每个定了距离的点更新 
						
					}
				}
			}
		}
		
//输出 
		
		
		
		
//释放
		For(i,N){			
			while(node[i].List){
				ArcNode *temp=node[i].List;
				node[i].List=node[i].List->next;
				delete temp;
			}
		} 
	}
return 0;
}








