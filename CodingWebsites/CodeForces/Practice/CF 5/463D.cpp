#include <iostream>
#include <cstdio>
using namespace std;
int n,k;
int position[5][1000];//��¼position[i][j]��¼��i���У�����j���ֵ�λ�á� 
int a[5][1000];//��¼���� 
int dp[1000];//dp[i]��ʾ�����±�i��β������������г��ȡ� 
int main(void)
{
	freopen("463D.txt","r",stdin); 
	while(cin>>n>>k){
		for(int i=0;i<k;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&a[i][j]);
				position[i][--a[i][j]]=j;
			}
		}
		int ans=0;
		for(int j=0;j<n;++j){//���� j 
			int maxn=0;
			for(int p=0;p <j;++p){//���� �ԣ�j֮ǰ��ÿ���㣩 ��β������У��ж�j�ɲ����Լӽ�ȥ 
				int i;
				for(i=1;i<k&&position[i][a[0][p]]<position[i][a[0][j]];++i) ; 
				if(i==k&&dp[p]>maxn){//����Щ���Լӽ�ȥ�ĵ��У�dpֵ����һ�� 
						maxn=dp[p];// 
				}
			}
			dp[j]=maxn+1;//���dpֵ����1
			ans=max(ans,dp[j]);
		}
		printf("%d\n",ans);
	}
return 0;
}














