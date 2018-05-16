#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map> 
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
#define maxn 100005
struct ArcNode{
	int x;
	ArcNode *next;
};
ArcNode *List[maxn];
int nL;
int gcd(int a,int b){
if(!a) return b;if(!b) return a;
while(b){int t=b;b=a%b;a=t;}return a;
}
int f[maxn<<2];
void PushUp(int rt){
	if(!rt) return;
	f[rt]=gcd(f[rt<<1],f[rt<<1|1]);
}
int N;
void update(int x,int c){
	x+=N-1;
	f[x]=c;
	while(x>1){
		PushUp(x>>=1);
	}
}
int Q;
int main(void)
{freopen("1846.txt","r",stdin); 
	while(cin>>Q){
		map<int,int> MP;nL=0;
		memset(List,0,sizeof(List));
		memset(f,0,sizeof(f));
		N=1;int t=Q;
		while(N<Q) N++;
		For(i,Q){
			char a;int b;
			scanf(" %c%d",&a,&b);
			if(a=='+'){
				int I=-1;
				if(MP.count(b)) I=MP[b];
				else MP[b]=nL++,I=MP[b];
				ArcNode *temp=new ArcNode;
				temp->x=i;
				temp->next=List[I];
				List[I]=temp;
				update(i,b);
			}
			else{
				int I=-1;
				if(MP.count(b)) I=MP[b];
				if(~I){
					ArcNode*temp=List[I];
					List[I]=List[I]->next;
					if(temp){
						update(temp->x,0);
						delete temp;
					}	
				}
			}
			int ANS=f[1];
			if(!ANS) ANS=1;
			printf("%d\n",ANS);
		}
	}
return 0;
}








