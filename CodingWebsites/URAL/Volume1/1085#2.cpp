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

int N,M,K;
int main(void)
{freopen("1085.txt","r",stdin); 
	while(cin>>N>>M){
		//����
		For(i,M) node[i].route.clear();
		//��ȡ 
		For(i,M){
			int n,t;
			scanf("%d",&n);
			For(j,n) scanf("%d",&t),node[i].route.push_back(t-1);
		}
		cin>>K;
		For(i,K){
			int ticket;
			scanf("%d%d%d",&p[i].cash,&p[i].start,&p[i].ticket);
			p[i].start--;
		}
		
		//��ͼ
		For(i,N){
			For(j,N) {
				if(i==j) dis[i][j]=0;
				else dis[i][j]=inf;
			}	
		}
		For(i,M){
			for(int j=0;j<node[i].route.size();j++){
				for(int k=j+1;k<node[i].route.size();k++){
					dis[node[i].route[j]][node[i].route[k]]=4;
					dis[node[i].route[k]][node[i].route[j]]=4;
				}
			}
		}
		//Floyd�����·
		For(i,N){
			For(j,N){
				A[i][j]=dis[i][j];
			}
		}
		For(k,N){
			For(i,N){
				For(j,N){
					if(A[i][k]+A[k][j]<A[i][j]) A[i][j]=A[i][k]+A[k][j];
				}
			}
		}
		//OUT3(A[0][1],A[0][2],A[1][3]);
		//����� 
		int ANS=inf,ANSI=-1;
		For(i,N){//��ÿ���ڵ�
			 int T=1;int MinAns=0;
			 For(j,K){//��ÿ���� 
			 	if(p[j].ticket){
			 		if(A[i][p[j].start]==inf) {
			 			T=0;break;
			 		}
			 	}
			 	else{
			 		if(p[j].cash<A[i][p[j].start]) {
			 			T=0;break;
			 		}
			 		MinAns+=A[i][p[j].start];
			 	}
			 }
			if(T&&(MinAns<ANS)){
				ANS=MinAns,ANSI=i;
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








