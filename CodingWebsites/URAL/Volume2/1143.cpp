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
#define eps 1e-9
int dcmp(double a){
	return  (a>-eps)-(a<eps);
}
struct ArcNode{
	int from,to;double dis;
	ArcNode*next;
	bool operator <(const ArcNode&B)const{
		return dis<B.dis;
	}
}Arcy[20000];int ArcN;
struct P{
	double x,y;
	ArcNode*List;
	P(){}
	P(double x,double y):x(x),y(y){}
	P operator-(const P &B)const{
		return P(x-B.x,y-B.y);
	}
	double length(){
		return sqrt(x*x+y*y);
	}
}Camp[200];
void Arc(int from,int to){
	ArcNode*temp=&Arcy[ArcN++];
	temp->from=from;
	temp->to=to;temp->dis=(Camp[from]-Camp[to]).length();
	temp->next=Camp[from].List;
	Camp[from].List=temp;
}
int N;
int p[200];
double dis[200][200];
int Find(int i){
	return i==p[i]?i:p[i]=Find(p[i]);
}
bool Is(int i,int j){
	return Find(i)==Find(j);
}
void Union(int i,int j){
	p[Find(i)]=Find(j);
}
int main(void)
{freopen("1143.txt","r",stdin); 
	while(cin>>N){
		For(i,N){
			scanf("%lf%lf",&Camp[i].x,&Camp[i].y);
			p[i]=i;
		}
		ArcN=0;
		For(i,N){
			for(int j=i+1;j<N;j++){
				Arc(i,j);
			}
		}
		For(i,N)For(j,N) dis[i][j]=-(i!=j);
		sort(Arcy,Arcy+ArcN);
		For(i,ArcN){
			if(Is(Arcy[i].from,Arcy[i].to)) continue;
			Union(Arcy[i].from,Arcy[i].to);
			dis[Arcy[i].from][Arcy[i].to]=Arcy[i].dis;
			dis[Arcy[i].to][Arcy[i].from]=Arcy[i].dis;
		}
		For(k,N){
			For(i,N){
				For(j,N){
					if(~dcmp(dis[i][k])&&~dcmp(dis[k][j])){
						if(!~dcmp(dis[i][j])||dis[i][k]+dis[k][j]<dis[i][j]){
							dis[i][j]=dis[i][k]+dis[k][j];
						}
					}
				}
			}
		}
		double ANS=-1;
		For(i,N){
			double Tans=0;
			For(j,N) Tans+=dis[i][j];
			if(!~dcmp(ANS)||Tans<ANS){
				ANS=Tans;
			}
		}
		printf("%.3f\n",ANS);
	}
return 0;
}








