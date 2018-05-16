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

int dp[2][1048576];
int N,M;
int price[20];//20������ 
int Want[20];//��Ҫ����Ʒ��š� 
int Wn;//��Ҫ����Ʒ���� 
int Mark[100];//100�����ϵ���� 
int Mprice[100];//100�����ϵ�״̬ 
int main(void)
{freopen("1326.txt","r",stdin); 
	while(cin>>N){
		For(i,N) scanf("%d",&price[i]),Want[i]=0;
		cin>>M;Wn=0;
		int n,a;
		For(i,M){
			Mark[i]=0;
			scanf("%d%d",&Mprice[i],&n);
			For(j,n){
				scanf("%d",&a);
				Mark[i]|=1<<(a-1);
			}
			
		}
		scanf("%d",&n);
		For(j,n){
			scanf("%d",&a);
			Want[Wn++]=a-1;
		}
		memset(dp,-1,sizeof(dp));
		int ANS=inf;
		if(M>0){
			//DP 
			dp[0][0]=0;
			For(i,M){
				int I=i&1,IN=~i&1;//��ǰ����������ֱ��д�ڱ��ʽ�����0.1�����ҡ� 
				For(j,1<<N) dp[IN][j]=-1;
				For(j,1<<N){
					if(~dp[I][j]){
						int J=j|Mark[i],D=dp[I][j]+Mprice[i];
						if(!~dp[IN][j]||dp[IN][j]>dp[I][j]) dp[IN][j]=dp[I][j];
						if(!~dp[IN][J]||dp[IN][J]>D) dp[IN][J]=D;
					}
				}
			}
			//�������п��Դﵽ��״̬������Сֵ�� 
			For(j,1<<N){
				if(~dp[M&1][j]){
					int tANS=dp[M&1][j];
					For(k,Wn) {
						if((j>>Want[k])&1) ;
						else tANS+=price[Want[k]];
					}
					if(tANS <ANS) ANS=tANS;
				}
			}
		}
		else{
			ANS=0;
			For(k,Wn) ANS+=price[Want[k]]; 
		}
		printf("%d\n",ANS);
	}
return 0;
}








