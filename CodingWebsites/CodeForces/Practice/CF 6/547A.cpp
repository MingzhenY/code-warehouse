#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define OUT(x) cout<<#x<<"="<<x<<endl;
#define LL long long
using namespace std;

int M;
int vis[1000001];
bool F(LL x,LL y,LL h,LL a,LL &A,LL &C){//求出目标出现的函数 A + Cx 
	int count=0;
	memset(vis,-1,sizeof(vis));
	vis[h]=0;int First=-1,H1=-1,H2=-1; 
	while(1){
		h=(h*x+y)%M;count++;
		if(h==a) {
			if(!~First) First=count;
		}
		if(~vis[h]) {
			if(~First){
				A=First;
				C=count-vis[h]; 
				if(First<vis[h]) C=0;
				return true;
			}
			else return false;
		}
		vis[h]=count;
	}
	return false;
}
LL gcd(LL a,LL b){while(b){int t=a%b;a=b;b=t;}return a;}
LL expgcd(LL a,LL b,LL &x,LL &y){//x*a+y*b=gcd(a,b)  |x+y|minmal
	if(b) {
		LL gcd,nx,ny;
		gcd=expgcd(b,a%b,nx,ny);
		x=ny;y=nx-a/b*ny;
		return gcd;
	}
	else{
		x=1;y=0;
		return a;
	}
} 
int main(void)
{
	freopen("547A.txt","r",stdin); 
	LL x1,y1,h1,a1,x2,y2,h2,a2,A1,C1,A2,C2;
	while(cin>>M>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2){
		bool D1=F(x1,y1,h1,a1,A1,C1),D2=F(x2,y2,h2,a2,A2,C2);
		if(A1>A2){
			int t=A1;A1=A2;A2=t;
			t=C1;C1=C2;C2=t; 
		}
		//printf("%d + %d x --- %d + %d x\n",A1,C1,A2,C2);
		LL ANS;
		if(!D1||!D2) ANS=-1;
		else{
			LL X,Y;
			if(A1==A2)  ANS=A1;//酌情保留 
			else if(!C1&&!C2) ANS=-1;
			else if(!(C1&&C2)){
				if(!C1){
					if(A1-A2>0&&(A1-A2)%C2==0) ANS=A1;
					else ANS=-1;
				}
				if(!C2){
					if(A2-A1>0&&(A2-A1)%C1==0) ANS=A2;
					else ANS=-1;
				}
			}
			else if((A2-A1)%gcd(C1,C2)==0){//有可能有解 
				LL D=expgcd(C1,C2,X,Y);
				//printf("X*C1+Y*C2=%d  D=%d\n",C1*X+C2*Y,D);
				X*=(A2-A1)/D;Y*=(A2-A1)/D;
				int T1=C1/D,T2=C2/D;
				if(X>=T2){
					int k=X/T2;
					X-=k*T2;
					Y+=k*T1;
				}
				if(Y>0){
					int k=(Y-1)/T1 +1;
					X+=k*T2;
					Y-=k*T1; 
				}
				//X=37;Y=-36;
				//printf("X=%d Y=%d C1=%d C2=%d  C1*X+C2*Y=%d \n",X,Y,C1,C2,C1*X+C2*Y);
				//printf("X*C1+Y*C2=%d\n",C1*X+C2*Y);
				//printf("%d + %d x --- %d + %d x\n",A1,C1,A2,C2);
				//printf("X=%d Y=%d  %d=%d=%d\n",X,Y,C1*X+C2*Y,A2-A1,gcd(C1,C2));
				ANS=A1+C1*X;
			}
			else ANS=-1;
		}
		cout<<ANS<<endl;
	}
return 0;
}
