#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#define maxn 200007
using namespace std;
//
int n,q;

//²¢²é¼¯   
int team[maxn];
int Find(int x){return x==team[x]?x:team[x]=Find(team[x]);}
int Union(int x,int y){team[Find(y)]=Find(x);}
queue<int> IN;
//SBT
int L[maxn],R[maxn],S[maxn],K[maxn],IP;
void PushUp(int &rt){
	S[rt]=S[L[rt]]+S[R[rt]]+1;
}
int zig(int &rt){
	int t=R[rt];R[rt]=L[t];L[t]=rt;
	S[t]=S[rt];S[rt]=S[L[rt]]+S[R[rt]]+1;
	rt=t;
}
int zag(int &rt){
	int t=L[rt];L[rt]=R[t];R[t]=rt;
	S[t]=S[rt];S[rt]=S[L[rt]]+S[R[rt]]+1;
	rt=t;
}
void level(int &rt){
	if(S[L[L[rt]]]>S[R[rt]]) {zag(rt);level(L[rt]);level(rt);return;}
	if(S[R[R[rt]]]>S[L[rt]]) {zig(rt);level(R[rt]);level(rt);return;}
	if(S[R[L[rt]]]>S[R[rt]]) {zig(L[rt]);zag(rt);level(L[rt]);level(R[rt]);return;}
	if(S[R[L[rt]]]>S[L[rt]]) {zag(R[rt]);zig(rt);level(R[rt]);level(L[rt]);return;}
}
void show(int rt,bool end){
	if(S[L[rt]]) show(L[rt],false);
	printf("%d ",K[rt]);
	if(S[R[rt]]) show(R[rt],false);
	if(end) printf("\n");
} 
void Show(int rt){show(rt,true);}
void Choose(int &rt,int Lx,int Rx){//Choose All the values in [L,R] 
	if(!rt) return; 
	if(K[rt]<Lx) Choose(R[rt],Lx,Rx);
	else if(K[rt]>Rx) Choose(L[rt],Lx,Rx);
	else{
		IN.push(K[rt]);
		Choose(L[rt],Lx,Rx);
		Choose(R[rt],Lx,Rx);
	}
}
void Del(int &rt,int X){
	if(!rt) return;
	if(K[rt]<X) Del(R[rt],X);
	else if(K[rt]>X) Del(L[rt],X);
	else{
		if(S[L[rt]]){
			zag(rt);Del(R[rt],X);
		}
		else{
			rt=R[rt];
		}
	}
	PushUp(rt);
}
void Insert(int &rt,int X){
	if(!rt){rt=++IP;L[IP]=R[IP]=0;S[IP]=1;K[IP]=X;return;}
	if(X<=K[rt]) Insert(L[rt],X);else Insert(R[rt],X);
}
void Init(int &rt){
	for(int i=1;i<=n;++i) team[i]=i;
	
	L[0]=R[0]=S[0]=K[0]=IP=0;
	for(int i=1;i<=n;++i) Insert(rt,i);
}
void OP1(int &rt,int x,int y){
	Union(x,y);
	Del(rt,y);
}
void OP2(int &rt,int x,int y){
	while(!IN.empty()) IN.pop();
	Choose(rt,x,y);
	if(IN.empty()) return;
	
	int T=IN.front();IN.pop();
	while(!IN.empty()){
		Union(T,IN.front());Del(rt,IN.front());IN.pop();
		//printf("OP2-Union(%d,%d)\n",T,next);
	}
}
bool OP3(int &rt,int x,int y){
	return Find(x)==Find(y);
}
int main(void)
{
	//Test();
	freopen("566D.txt","r",stdin); 
	while(~scanf("%d%d",&n,&q)){
		int SBT=0;Init(SBT);
		for(int i=0;i<q;++i){
			int type,x,y;scanf("%d%d%d",&type,&x,&y);
			if(x>y){x=x^y;y=x^y;x=x^y;}
			switch(type){
				case 1:
					printf("--merge %d and %d\n",x,y);OP1(SBT,x,y);break;
				case 2:
					printf("--merge %d to %d\n",x,y);OP2(SBT,x,y);break;
				case 3:
					printf("--query %d and %d\n",x,y);
					printf("%s\n",OP3(SBT,x,y)?"YES":"NO");break;
			}
			printf("i=%d : ",i);
			Show(SBT);
			for(int i=1;i<=n;++i) printf("team[%d]=%d\n",i,team[i]);
		}
	}
	
	
return 0;
}

