#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#define maxn 200007
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
int team[maxn];
int Find(int x){
	int t=team[x];
	while(t!=team[t]) t=team[t];
	return x=t;
}
void Union(int x,int y){
	x=Find(x),y=Find(y);
	if(x>y){x=x^y;y=x^y;x=x^y;}
	team[y]=x;
}
int n,q;
queue<int> IN; 
//SBT
int L[maxn],R[maxn],S[maxn],RealS[maxn],Value[maxn],Times[maxn],IP;
void PushUp(int &rt){
	S[rt]=S[L[rt]]+S[R[rt]]+1;
	RealS[rt]=RealS[L[rt]]+RealS[R[rt]]+Times[rt];
}
int zig(int &rt){
	int t=R[rt];R[rt]=L[t];L[t]=rt;
	PushUp(rt);PushUp(t);rt=t;
}
int zag(int &rt){
	int t=L[rt];L[rt]=R[t];R[t]=rt;
	PushUp(rt);PushUp(t);rt=t;
}
void level(int &rt){
	if(S[L[L[rt]]]>S[R[rt]]) {zag(rt);level(L[rt]);level(rt);return;}
	if(S[R[R[rt]]]>S[L[rt]]) {zig(rt);level(R[rt]);level(rt);return;}
	if(S[R[L[rt]]]>S[R[rt]]) {zig(L[rt]);zag(rt);level(L[rt]);level(R[rt]);return;}
	if(S[R[L[rt]]]>S[L[rt]]) {zag(R[rt]);zig(rt);level(R[rt]);level(L[rt]);return;}
}
void show(int rt,bool end){
	if(S[L[rt]]) show(L[rt],false);
	//printf("%d(%d)[%d,%d] S=%d RealS=%d\n ",Value[rt],Times[rt],Value[L[rt]],Value[R[rt]],
	//S[rt],RealS[rt]);
	printf("%d(%d) ",Value[rt],Times[rt]);
	if(S[R[rt]]) show(R[rt],false);
	if(end) printf("\n");
} 
void Show(int rt){show(rt,true);}
int Rank(int rt,int X){
	if(!rt) return 1;
	if(RealS[L[rt]]+Times[rt]>=X) return Rank(L[rt],X);
	else return S[L[rt]]+1+Rank(R[rt],X-RealS[L[rt]]-Times[rt]);
}

void Choose(int &rt,int Lx,int Rx){//Choose All the values in [Lx,Rx] 
	if(!rt) return;//( RealS[L[rt]],RealS[L[rt]]+Times[rt] ]
	//OUT2(Lx,Rx);	OUT3(RealS[L[rt]],RealS[L[rt]]+Times[rt],Value[rt]);
	if(Lx>RealS[L[rt]]+Times[rt]) Choose(R[rt],Lx-RealS[L[rt]]-Times[rt],Rx-RealS[L[rt]]-Times[rt]);
	else if(Rx <=RealS[L[rt]]) Choose(L[rt],Lx,Rx);
	else{
		IN.push(rt);//printf("IN Choose:          ");OUT2(Value[rt],Times[rt]);
		Choose(R[rt],Lx-RealS[L[rt]]-Times[rt],Rx-RealS[L[rt]]-Times[rt]);
		Choose(L[rt],Lx,Rx);
	}
}

void Del(int &rt,int X){
	//OUT2(Value[rt],X);
	if(!rt) return;
	if(X==Value[rt]){
		if(S[L[rt]]) {zag(rt);Del(R[rt],X);}
		else {rt=R[rt];return;}
	}
	else{
		if(X < Value[rt]) Del(L[rt],X);
		else Del(R[rt],X);
	}
	PushUp(rt);
	level(rt);
}
int DValue,DTimes;
void DelMax(int &rt){
	if(R[rt]) {
		DelMax(R[rt]);
		PushUp(rt);
		level(rt); 
	}
	else{
		DValue=Value[rt];
		DTimes=Times[rt];
		rt=0;
	}
}
void FastDel(int &rt,int X){
	if(!rt) return;
	if(X==Value[rt]){
		if(S[L[rt]]&&S[R[rt]]){DelMax(L[rt]);Value[rt]=DValue;Times[rt]=DTimes;}
		else {
			if(S[L[rt]]) rt=L[rt];
			else rt=R[rt];
			return;
		}
	}
	else{
		if(X < Value[rt]) Del(L[rt],X);
		else Del(R[rt],X);
	}
	PushUp(rt);
	level(rt);
}
void Insert(int &rt,int V){
	if(!rt){rt=++IP;L[IP]=R[IP]=0;S[IP]=1;RealS[IP]=1;Value[IP]=V;Times[IP]=1;return;}
	if(V <=Value[rt]) Insert(L[rt],V);
	else Insert(R[rt],V);
	PushUp(rt);
	level(rt);
}
void Add(int &rt,int V,int C){
	if(!rt) return;
	if(V==Value[rt]){
		Times[rt]+=C;return;
	}
	if(V < Value[rt]) Add(L[rt],V,C);
	else Add(R[rt],V,C);
}
void Init(int &rt){
	for(int i=1;i<=n;++i) team[i]=i;
	L[0]=R[0]=S[0]=RealS[0]=Times[0]=IP=0;
	for(int i=1;i<=n;++i) Insert(rt,i);
}
void OP1(int &rt,int x,int y){
	Union(x,y);
}
void OP2(int &rt,int x,int y){
	while(!IN.empty()) IN.pop();
	Choose(rt,x,y);
	//OUT1(IN.size());
	if(IN.empty()) return;
	int T=Value[IN.front()];IN.pop();
	while(!IN.empty()){
		Union(T,team[IN.front()]);
		Add(rt,T,Times[IN.front()]);
		FastDel(rt,Value[IN.front()]);
		IN.pop();
		//printf("OP2-Union(%d,%d)\n",T,next);
	}
}
bool OP3(int &rt,int x,int y){
	return Find(x)==Find(y);
}
void Test(){
	printf("Test Begin!\n");
		int RT=0;
		for(int i=1;i<=11;++i) Insert(RT,i);
		Show(RT);
		for(int i=1;i<=11;++i) printf("Rank[%d]=%d\n",i,Rank(RT,i));
	printf("Test End!\n");
}
int main(void)
{
	freopen("566D.txt","r",stdin); 
	while(~scanf("%d%d",&n,&q)){
		int SBT=0;Init(SBT);
		for(int i=0;i<q;++i){
			int type,x,y;scanf("%d%d%d",&type,&x,&y);
			if(x>y){x=x^y;y=x^y;x=x^y;}
			switch(type){
				case 1:
					//printf("--merge %d and %d\n",x,y);
					OP1(SBT,x,y);break;
				case 2:
					//printf("--merge %d to %d\n",x,y);
					OP2(SBT,x,y);break;
				case 3:
					//printf("--query %d and %d\n",x,y);
					printf("%s\n",OP3(SBT,x,y)?"YES":"NO");break;
			}
		}
	}
return 0;
}

