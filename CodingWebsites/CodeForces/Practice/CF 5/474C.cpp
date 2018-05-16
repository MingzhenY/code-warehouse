#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
struct pole{
	int x,y,a,b;
	void ReadIn(){scanf("%d%d%d%d",&a,&b,&x,&y);}
	void rotate(){int newx=x-(b-y),newy=y+(a-x);a=newx,b=newy;}
};
struct A{
	pole P[4];
	void ReadIn(){for(int i=0;i<4;++i) P[i].ReadIn();}
	bool Is(){
		long long d[6];int nd=0;
		long long K[2];int Kn[2];
		for(int i=0;i<4;++i){
			for(int j=i+1;j<4;++j){
				long long KD=(long long)(P[i].a-P[j].a)*(P[i].a-P[j].a)+(P[i].b-P[j].b)*(P[i].b-P[j].b);
				if(nd==2){
					if(KD==K[0]) ++Kn[0];
					else if(KD==K[1]) ++Kn[1];
					else return 0;
				}
				else{
					if(nd){
						if(KD==K[0]) ++Kn[0];
						else {
							if(KD>K[0]) K[nd]=KD,Kn[nd++]=1;
							else{
								K[nd]=K[0];
								Kn[nd++]=Kn[0];
								K[0]=KD;
								Kn[0]=1;
							}
							if(K[1]==(K[0]<<1));
							else return 0;
						}
					}
					else{
						K[nd]=KD;
						Kn[nd++]=1;
					}
				}
			}
		}
		return Kn[0]==4&&Kn[1]==2;
	}
};
A D[256];
int dis[256];
queue<unsigned char> Q;
void bfs(int k){
	int Next;int T=dis[k]+1;
	if(((k&3)<3)){
		Next=k+1;
		if(~dis[Next]) ;
		else{
			D[Next]=D[k];D[Next].P[0].rotate();
			dis[Next]=T;
			Q.push(Next);		
		}
	}
	if((((k>>2)&3)<3)){
		Next=k+4;
		if(~dis[Next]) ;
		else{
		D[Next]=D[k];D[Next].P[1].rotate();
		dis[Next]=T;
		Q.push(Next);	}
	}
	if((((k>>4)&3)<3)){
		Next=k+16;
		if(~dis[Next]) ;
		else{
			D[Next]=D[k];D[Next].P[2].rotate();
			dis[Next]=T;
			Q.push(Next);	
		}
	}
	if((((k>>6)&3)<3)){
		Next=k+64;
		if(~dis[Next]) ;
		else{
			D[Next]=D[k];D[Next].P[3].rotate();
			dis[Next]=T;
			Q.push(Next);	
		}
	}
}
int main(void)
{freopen("474C.txt","r",stdin); 
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;++i){
			A X;int Found=0;
			X.ReadIn();
			while(!Q.empty()) Q.pop();
			memset(dis,-1,sizeof(dis));
			Q.push(0);D[0]=X;dis[0]=0;
			while(!Q.empty()){
				int cnt=Q.front();Q.pop();
				if(D[cnt].Is()) {
					printf("%d\n",dis[cnt]);
					Found=1;
					break;
				}
				else{
					bfs(cnt);
				}
			}
			if(!Found) printf("-1\n");
		} 
	}
return 0;
}














