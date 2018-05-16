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

int a[10001];
int b[10001];
int c[10000];
int N;

int main(void)
{freopen("1032.txt","r",stdin); 
	while(cin>>N){		
		//����
		memset(c,0,sizeof(c));
		b[0]=0;c[0]++;
		for(int i=1;i<=N;i++){
			scanf("%d",&a[i]);
			b[i]=(b[i-1]+a[i])%N;
			c[b[i]]++;
		} 
		int T=0;
		//�ҵ���ͬ������ֵ 
		int same,l=-1,r=-1;
		for(int i=0;i<10000;i++){
			if(c[i]>=2){
				same=i;//��������������Ϊi 
				break;
			}
		}
		//�ҵ�l��r
		for(int i=0;i<=N;i++){//�������е����� 
			if(b[i]==same){//����������ˣ����¼ i 
				if(~l) {
					if(~r) break;
					else r=i;
				}
				else l=i;
			}
		}
		//��� 
		if(~l&&~r){
			printf("%d\n",r-l);
			for(int j=l+1;j<=r;j++){
				printf("%d\n",a[j]);
			}
		}
		else{
			printf("%d\n",0);
		}
	}
return 0;
}








