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
	int num[6];//前1，后4，左0，右5，上2，下3 
	void e1(){//旋转1 
		int t=num[2];
		num[2]=num[4];
		num[4]=num[3];
		num[3]=num[1];
		num[1]=t;
	}
	void e2(){//旋转2 
		int t=num[2];
		num[2]=num[0];
		num[0]=num[3];
		num[3]=num[5];
		num[5]=t;
	}
	void e3(){//（在1已经被转到num[1]之后，把剩余的最小值转到num[0] 
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
		//输入 格式：左右上前下后 
		scanf("%d%d%d%d%d%d",&dice[i].num[0],&dice[i].num[5],
		&dice[i].num[2],&dice[i].num[1],&dice[i].num[3],&dice[i].num[4]);
		
		//处理 (把1转到num[1](前面))
		if(dice[i].num[0]==1){dice[i].e2();dice[i].e1();}
		else if(dice[i].num[2]==1){dice[i].e1();}
		else if(dice[i].num[3]==1){dice[i].e1();dice[i].e1();dice[i].e1();}
		else if(dice[i].num[4]==1){dice[i].e1();dice[i].e1();}
		else if(dice[i].num[5]==1){dice[i].e2();dice[i].e1();dice[i].e1();dice[i].e1();}
		//处理2，把剩余最小值转到num[0] （左边） 
		dice[i].e3();
		//这时，直接判断是否每一位相等就行了,不相等就不能通过旋转得到。 
		
		//合并 
		for(int j=0;j<i;j++){
			if(dice[j]==dice[i]) {//最多有30种不同 
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








