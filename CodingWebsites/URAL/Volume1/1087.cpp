#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

int n,m;
int k[50];
int win[10001];//1ʤ,0��,-1δ��
int DFS(int t);
int main(void)
{freopen("1087.txt","r",stdin); 
	while(cin>>n>>m){
		memset(win,-1,sizeof(win));
		For(i,m) cin>>k[i];
		win[0]=1;
		printf("%d\n",2-DFS(n));
	}
return 0;
}
int DFS(int t){
	if(~win[t]) return win[t];
	for(int i=0;i<m;i++){//����ÿ�ֿ����� 
		if(t-k[i]>=0){//��������� 
			if(!DFS(t-k[i])){//�������ĳ�����������ǰܾ� 
				return win[t]=1; //�򱾾���ʤ�� 
			}
		}
	}
	return win[t]=0;//���򱾾��ưܾ� 
}







