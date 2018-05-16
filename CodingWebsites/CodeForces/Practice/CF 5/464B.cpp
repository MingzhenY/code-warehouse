#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define F(x) for(i[x]=0;i[x]<6;++i[x])

using namespace std;
int dx[6][3]{{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
struct P{
	int x[3];
	int D;//距离
	int I;//下标
	void ReadIn(){scanf("%d%d%d",&x[0],&x[1],&x[2]);}
	bool operator ==(const P &B)const{return x[0]==B.x[0]&&x[1]==B.x[1]&&x[2]==B.x[2];}
}D[8],T[8];
bool cmpD(P A,P B){return A.D <B.D;}
bool cmpI(P A,P B){return A.I <B.I;}
int main(void)
{
	freopen("464B.txt","r",stdin); 
	for(int i=0;i<8;i++) D[i].ReadIn();
	int i[8];
	F(0) F(1) F(2) F(3) F(4) F(5) F(6) F(7)
	{
		for(int k=0;k<8;++k){
			for(int j=0;j<3;++j) T[k].x[j]=D[k].x[dx[i[k]][j]];
			T[k].I=k;
		}
		for(int k=0;k<8;++k){
			T[k].D=0;
			for(int t=0;t<3;++t){
				int D=T[k].x[t]-T[0].x[t];
				T[k].D+=D*D;
			}
		}
		sort(T,T+8,cmpD);
		if(T[7].D!=3*T[0].D) continue;
		if(T[1]==T[2]||T[1]==T[3]||T[2]==T[3]||T[4]==T[5]||T[5]==T[6]||T[4]==T[6]) continue;
		if(T[1].D==0) continue;
		if(T[1].D==T[2].D&&T[2].D==T[3].D){
			if(T[4].D==T[5].D&&T[5].D==T[6].D&&T[4].D==2*T[0]){
				//此处判断是否是正方体
			}
		}
	}
		
return 0;
}














