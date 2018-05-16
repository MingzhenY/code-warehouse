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
//��· 
struct Node{
	vector<int> route;//��· 
}node[100];
//�� 
struct People{
	int cash;
	int start;
	int ticket;
}p[100];
//���· 
int dis[100][100];//�ڽӾ���
int A[100][100];//Floyd 
//����ÿվ��·�ߡ�
vector <int> stop[100];
int N,M,K;
int main(void)
{freopen("1085.txt","r",stdin); 
	while(cin>>N>>M){
		//����
		For(i,M) node[i].route.clear();
		For(i,N) stop[i].clear(); 
		//��ȡ 
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
		
		//��ͼ
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
		//Floyd�����·
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
		//����� 
		int ANS=inf;int T;int ANSI=-1;
		For(i,N){
			//if(stop[i].size()>1){//ÿ������,����һ�δ� 
				T=1;int TT=0;
				int tempANS=0;
				For(j,K){//��ÿ���ˣ����㵽��i����̻��� 
					if(p[j].ticket) continue;
					TT++;
					int MinCost=inf;
					For(k,stop[p[j].start].size()){//���ھ�������ÿһ����· 
						For(s,stop[i].size()){//���ھ����յ�i��ÿһ����· 
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
		//�ж��Ƿ���ͨ
		if(~ANSI){
			For(i,K){
				if(p[i].ticket){
					int T=0;//������ANSI��p[i].start����· 
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
		
		//��� 
		if(~ANSI){
			printf("%d %d\n",ANSI+1,ANS);
		}
		else cout<<0<<endl;
		
	}
return 0;
}








