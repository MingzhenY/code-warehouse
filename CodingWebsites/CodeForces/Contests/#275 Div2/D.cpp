#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 100001
using namespace std;
//�߶��� 
int  N,n,m;
int set[maxn<<2];
void ST_Init(){
	N=1;while(N <n+2) N <<=1;
	memset(set,0,sizeof(set));
}
void TurnOn(int L,int R,int C){
	for(int s=N+L-1,t=N+R+1;s^t^1;s>>=1,t>>=1){
		if(~s&1) set[s^1]|=C;
		if(t&1)  set[t^1]|=C;
	}
}
void ShutDown(){
	//�����ñ�Ǵ�����ȥ 
	for(int i=1;i<N;++i){
		if(set[i]){
			set[i<<1]|=set[i];
			set[i<<1|1]|=set[i];
			set[i]=0;
		}
	}
	//�ؽ��µ��߶��� 
	for(int i=N-1;i>0;--i){
		set[i]=set[i<<1]&set[i<<1|1];
	}
}
int Query(int L,int R){
	int ANS=-1;
	for(int s=N+L-1,t=N+R+1;s^t^1;s>>=1,t>>=1){
		if(~s&1) ANS&=set[s^1];
		if(t&1)  ANS&=set[t^1];
	}
	return ANS;
}
//��¼����
int l[maxn],r[maxn],q[maxn];
int main(void)
{
	freopen("D.txt","r",stdin); 
	while(~scanf("%d%d",&n,&m)){
		ST_Init();
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&l[i],&r[i],&q[i]);
			//������ ��q[i]���а�λ��
			TurnOn(l[i],r[i],q[i]); 
		}
		//�ؽ��߶�����������İ�λ�� 
		ShutDown();
		//�����ж��Ƿ����m������ 
		int T=0;
		for(int i=0;i<m;++i){ 
			if(Query(l[i],r[i])==q[i]) ++T;
			else break;
		}
		
		if(T==m){//�������m�������������� 
			printf("YES\n");
			printf("%d",set[N+1]);
			for(int i=2;i<=n;++i){
				printf(" %d",set[N+i]);
			}
			printf("\n");
		}
		else{//���������m���������򲻴��ڷ���������n������ 
			printf("NO\n");
		}
	}
return 0;
}














