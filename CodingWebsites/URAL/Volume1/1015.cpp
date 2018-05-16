#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

struct Dice{
	int num[6];//ǰ1����4����0����5����2����3 
	void e1(){//��ת1 
		int t=num[2];
		num[2]=num[4];
		num[4]=num[3];
		num[3]=num[1];
		num[1]=t;
	}
	void e2(){//��ת2 
		int t=num[2];
		num[2]=num[0];
		num[0]=num[3];
		num[3]=num[5];
		num[5]=t;
	}
	void e3(){//����1�Ѿ���ת��num[1]֮�󣬰�ʣ�����Сֵת��num[0] 
		while(num[0]<num[2]||num[0]<num[3]||num[0]<num[5]) this->e2();
	}
	void show(){
		for(int i=0;i<6;i++){
			printf("%d ",num[i]);
		} 
		cout<<endl;
	}
	bool operator==(const Dice&B)const{
		int T=0;
		for(int i=0;i<6;i++) if(num[i]==B.num[i]) T++;
		return T==6;
	}
}dice[100000];
bool vis[100000];
vector <int> V[100000];
int N;
int main(void)
{freopen("1015.txt","r",stdin); 
	cin>>N;int ALL=N;memset(vis,0,sizeof(vis));
	For(i,N){
		//���� ��ʽ��������ǰ�º� 
		scanf("%d%d%d%d%d%d",&dice[i].num[0],&dice[i].num[5],
		&dice[i].num[2],&dice[i].num[1],&dice[i].num[3],&dice[i].num[4]);
		
		//���� (��1ת��num[1](ǰ��))
		if(dice[i].num[0]==1){dice[i].e2();dice[i].e1();}
		else if(dice[i].num[2]==1){dice[i].e1();}
		else if(dice[i].num[3]==1){dice[i].e1();dice[i].e1();dice[i].e1();}
		else if(dice[i].num[4]==1){dice[i].e1();dice[i].e1();}
		else if(dice[i].num[5]==1){dice[i].e2();dice[i].e1();dice[i].e1();dice[i].e1();}
		//����2����ʣ����Сֵת��num[0] ����ߣ� 
		dice[i].e3();
		//��ʱ��ֱ���ж��Ƿ�ÿһλ��Ⱦ�����,����ȾͲ���ͨ����ת�õ��� 
		
		//�ϲ� 
		for(int j=0;j<i;j++){
			if(dice[j]==dice[i]) {//�����30�ֲ�ͬ 
				V[j].push_back(i);ALL--;break;
			}
		}
	}
	cout<<ALL<<endl;
	For(i,N){
		if(vis[i]) continue;
		printf("%d",i+1);
		For(j,V[i].size()) printf(" %d",V[i][j]+1),vis[V[i][j]]=1;
		cout<<endl;
	}
return 0;
}








