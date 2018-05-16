#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#define inf 0x3fffffff
using namespace std;
int N,n,k;
int stMax[1024];
int stMaxI[1024];
int stMin[1024];
int stMinI[1024];
vector<int> V;
void PushUp(int rt){
	int ls=rt<<1,rs=ls|1;
	if(stMax[ls]>stMax[rs]){
			stMax[rt]=stMax[ls];
			stMaxI[rt]=stMaxI[ls];
	}
	else{
		stMax[rt]=stMax[rs];
		stMaxI[rt]=stMaxI[rs];
	}
	
	if(stMin[ls]<stMin[rs]){
		stMin[rt]=stMin[ls];
		stMinI[rt]=stMinI[ls];
	}
	else{
		stMin[rt]=stMin[rs];
		stMinI[rt]=stMinI[rs];
	}
}
void Init(){
	for(int i=N-1;i>0;--i){
		PushUp(i);
	}
}
void ADD(int X,int C){
	stMax[N+X]+=C;
	stMin[N+X]+=C;
	for(int s=N+X;s>1;s>>=1){
		PushUp(s>>1);
	}
}
int Min,MinI,Max,MaxI;
void query(){
	Min=inf;Max=-1;
	for(int s=N,t=N+n+1;s^t^1;s>>=1,t>>=1){
		if(~s&1){
			if(stMin[s^1]<Min){
				Min=stMin[s^1];
				MinI=stMinI[s^1];
			}
			if(stMax[s^1]>Max){
				Max=stMax[s^1];
				MaxI=stMaxI[s^1];
			}
		}
		if(t&1){
			if(stMin[t^1]<Min){
				Min=stMin[t^1];
				MinI=stMinI[t^1];
			}
			if(stMax[t^1]>Max){
				Max=stMax[t^1];
				MaxI=stMaxI[t^1];
			}
		}
	}
}
int main(void)
{
	freopen("479B.txt","r",stdin); 
	while(cin>>n>>k){
		N=1;while(N <n+2 ) N <<=1;
		for(int i=1;i<=n;++i){
			scanf("%d",&stMax[N+i]);
			stMin[N+i]=stMax[N+i];
			stMinI[N+i]=stMaxI[N+i]=i;
		}
		Init();V.clear();
		int m;
		for(int i=0;i<k;++i){
			query();
			if(Min+1 >=Max) break;
			V.push_back(MaxI);
			V.push_back(MinI);
			ADD(MinI,1);
			ADD(MaxI,-1);
		}
		m=V.size()>>1;query();
		printf("%d %d\n",Max-Min,m);
		for(int i=0;i<m;++i){
			printf("%d %d\n",V[i <<1],V[i <<1|1]);
		}
	}
return 0;
}














