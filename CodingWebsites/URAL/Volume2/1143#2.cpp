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
struct P{
	double x,y;
	P(){}
	P(double x,double y):x(x),y(y){}
	P operator-(const P &B)const{
		return P(x-B.x,y-B.y);
	}
	double length(){
		return sqrt(x*x+y*y);
	}
}Camp[200];
struct ArcNode{
	int i;
	ArcNode *next,*last;
	ArcNode():next(NULL),last(NULL){}
};
double dist[200][200]; 
double A[200][200];
ArcNode *path[200][200];
void ADD(int i,int j,int k){
	ArcNode*temp=new ArcNode;
	temp->i=k;
	path[i][j]=temp;
}
void Ad(int i,int j,ArcNode **Cur,int k){
	ArcNode*temp=new ArcNode;
	temp->i=k;
	if(path[i][j]==*Cur){//如果是第一个 
		temp->next=path[i][j];
		path[i][j]=temp;
		(*Cur)->last=temp; 
	}
	else{//如果不是第一个 
		(*Cur)->last->next=temp;
		temp->last=(*Cur)->last;
		(*Cur)->last=temp;
		temp->next=*Cur;
	}
}
int N;
int main(void)
{freopen("1143.txt","r",stdin); 
	while(cin>>N){
		For(i,N){
			scanf("%lf%lf",&Camp[i].x,&Camp[i].y);
		}
		For(i,N){
			For(j,N){
				dist[i][j]=(Camp[i]-Camp[j]).length();
				path[i][j]=NULL;
				ADD(i,j,i);
				A[i][j]=dist[i][j];
			}
		}
		
		//printf("\t读取完毕\n");
		
		For(k,N){
			//OUT1(k); 
			For(i,N){
				//printf("\t");OUT1(i);
				if(i==k) continue;
				for(int j=i+1;j<N;j++){
					//printf("\t\t");OUT1(j);
					if(j==k) continue;
					
					
					//用k点进行松弛~
					int I=j;double ANS=-1;ArcNode *ANSI=NULL;
					ArcNode *temp=path[i][I];
					while(temp->i!=i){
						double D=dist[temp->i][k]+dist[k][I]-dist[temp->i][I];
						if(ANS<0||D<ANS) ANS=D,ANSI=temp;
						I=temp->i;
						temp=temp->next;
					}
					double D=dist[temp->i][k]+dist[k][I]-dist[temp->i][I];
					if(ANS<0||D <ANS) ANS=D,ANSI=temp;
					//printf("路径%d->%d:在%d-%d之间加入了节点%d\n",i,j,temp->i,I,k);
					//OUT2(path[i][k],path[k][I]);
					Ad(i,j,&temp,k);
					A[i][j]+=ANS;
					
				}
			}
		}
		//printf("\t计算完毕\n");
		double ANS=-1;
		For(i,N){
			for(int j=i+1;j<N;j++){
				if(ANS<0||A[i][j]<ANS) ANS=A[i][j];
			}
		}
		printf("%.3f\n",ANS);
		For(i,N){
			For(j,N){
				while(path[i][j]){
					ArcNode *temp=path[i][j];
					path[i][j]=path[i][j]->next;
					delete temp;
				}
			}
		}
	}
return 0;
}








