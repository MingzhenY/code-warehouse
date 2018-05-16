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

struct Game{
	short int state;
	Game():state(0){}
	void move(short int k){state^=k;}
	void init0(){state=0;}
	void init1(){state=-1;}
	void reset(short int i){state&=~(1<<i);}
	void set(short int i){state|=(1<<i);}
	bool check(short int i){return (state>>i)&1;}
	bool win(){
		return !state||!~state;
	}
	void show(){
		for(int i=0;i<16;i++){
			printf("%d",(state>>i)&1);
			if(i%4==3) cout<<endl;
		}
		//cout<<endl;
	}
	Game operator ^(Game B){
		Game C;
		C.state=state^B.state;
		return C;
	}
	Game operator^=(Game B){
		*this=*this^B;
		return *this;
	}
};
Game turn[16];

int main(void)
{freopen("1122.txt","r",stdin); 
	Game A,plan;
	string a;
	//读取棋盘 A 
	for(int i=0;i<4;i++){
		cin>>a;
		for(int j=0;j<4;j++){
			if(a[j]=='B')  A.set(4*i+j);
			else A.reset(4*i+j);
		}
	}
	//读取规则 plan
	for(int i=0;i<3;i++){
		cin>>a;
		for(int j=0;j<3;j++){
			if(a[j]=='1') plan.set(3*i+j);
			else plan.reset(3*i+j);
		}
	}
	//创建 turn[16]
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			Game &cnt=turn[4*i+j];
			for(int k1=-1;k1<=1;k1++){
				for(int k2=-1;k2<=1;k2++){
					if(i+k1>=0&&i+k1<4&&j+k2>=0&&j+k2<4){
						if(plan.check(k1*3+k2+4)){
							cnt.set(4*(i+k1)+(j+k2));
						}
					}
				}
			}
		}
	} 
	//穷举计算 
	int ANS=17;
	for(int i=0;i<(1<<16);i++){
		Game game=A;int Count=0;
		for(int j=0;j<16;j++){
			if((i>>j)&1) game^=turn[j],Count++;
		}
		if(game.win()) {
			if(ANS>Count) ANS=Count; 
		}
	}
	if(ANS<17) cout<<ANS<<endl;
	else cout<<"Impossible"<<endl;
	
return 0;
}








