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

struct Wall{
	int Down,Up;
	int x;
	Wall operator *(const Wall&B)const{
		Wall C;
		C.Up=min(Up,B.Up);
		C.Down=max(Down,B.Down);
		C.x=x;
		return C;
	}
	void init(int x,int down,int up){
		this->x=x;Down=down;Up=up;
	}
}W[100001];
int N;
int main(void)
{freopen("1202.txt","r",stdin); 
	while(cin>>N){
		W[0].init(0,0,200);
		FOR(i,N){
			int Lx,Ly,Rx,Ry;
			scanf("%d%d%d%d",&Lx,&Ly,&Rx,&Ry);
			W[i].init(Rx,Ly,Ry);
			W[i-1]=W[i-1]*W[i];
		}
		/*
		FOR(i,N){
			printf("Ç½%d:  Î»ÖÃ£º%d  ¸ß¶È%d->%d\n",i,W[i].x,W[i].Down,W[i].Up);
		}
		*/
		int Curx=1,Cury=1;
		int Dx=W[N].x-1,Dy=W[N].Up-1;
		int ANS=0;int T=1;
		FOR(i,N-1){
			if(W[i].Up-W[i].Down<2) {
				T=0;break;
			}
			int D;
			if(W[i].Down>=max(Cury,Dy)-1){
				D=W[i].Down+1;
			}
			else if(W[i].Up<=min(Cury,Dy)+1){
				D=W[i].Up-1;
			}
			else if(Cury<W[i].Up&&Cury>W[i].Down){
				D=Cury;
			}
			else if(Cury<W[i].Down){
				D=W[i].Down+1;
			}
			else {
				D=W[i].Up-1;
			}
			(W[i].x,D);
			ANS+=abs(W[i].x-Curx)+abs(D-Cury);
			Curx=W[i].x;Cury=D; 
		}
		if(T) ANS+=abs(Curx-Dx)+abs(Cury-Dy);
		if(T) cout<<ANS<<endl;
		else cout<<-1<<endl;
	}
	
	
	
	
return 0;
}








