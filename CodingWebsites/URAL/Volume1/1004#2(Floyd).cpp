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
#define maxn 100

int MinCir;//��С��ֵ 
vector<int> Path;//��С��·�� 
int dist[maxn][maxn];//�ڽӾ��� 
int A[maxn][maxn]; 
int path[maxn][maxn];//���·�� 
int N,M;
int main(void)
{freopen("1004.txt","r",stdin); 
	while(cin>>N&&(~N)){
		//Ԥ���� 
		For(i,N){
			For(j,N){
				if(i==j) dist[i][j]=0;
				else dist[i][j]=inf;
				path[i][j]=-1;
			}
		}
		Path.clear();
		cin>>M;
		For(i,M) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(c<dist[a-1][b-1]){//ȥ���رߣ������رߣ�ȡȨֵ��С�� 
				dist[a-1][b-1]=c;
				dist[b-1][a-1]=c;
				path[a-1][b-1]=a-1;
				path[b-1][a-1]=b-1;				
			}			
		}
		//Floyd������С�� 
		MinCir=inf;
		For(i,N){
			For(j,N){
				A[i][j]=dist[i][j];
			}
		} 
		For(k,N){
			//�󾭹�k����С��
			for(int i=0;i<k;i++){
				for(int j=i+1;j<k;j++){
					int D=A[i][j]+dist[i][k]+dist[j][k];
					if(D <MinCir){
						MinCir=D;
						Path.clear();
						int t=j;
						Path.push_back(j);
						while(path[i][t]!=i){
							Path.push_back(path[i][t]);
							t=path[i][t];
						}
						Path.push_back(i);
						Path.push_back(k);
					}
				}
			}
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					if(A[i][k]+A[k][j]<A[i][j]){
						A[i][j]=A[i][k]+A[k][j];
						path[i][j]=path[k][j];
					}
				}
			}
		}
		//���
		//OUT1(MinCir);
		if(MinCir>=inf)  printf("No solution.\n");
		else{
			For(i,Path.size()){
				printf("%d",Path[i]+1);
				if(i==Path.size()-1) printf("\n");
				else printf(" ");
			} 	
		}
	}
return 0;
}








