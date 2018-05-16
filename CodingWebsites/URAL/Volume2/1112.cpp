#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define X 1000
using namespace std;
struct Mark{
	int M[4];
	Mark(){memset(M,0,sizeof(M));}
	void init(){memset(M,0,sizeof(M));}
	void set(int i){M[i/32]|=(1<<(i&31));}
	void reset(int i){M[i/32]&=~(1<<(i&31));}
	bool is(int i){return (M[i/32]>>(i%32))&1;} 
};
struct ArcNode{
	int from,to;
	bool operator <(const ArcNode &B)const{
		return from<B.from; 
	}
}Arc[100];
struct Node{
	int num;
	Mark M;
	vector<int> V;
}node[2000];
int N;
int main(void)
{freopen("1112.txt","r",stdin); 
	while(cin>>N){
		For(i,2000) node[i].num=0,node[i].V.clear(),node[i].M.init();
		For(i,N){
			scanf("%d%d",&Arc[i].from,&Arc[i].to);
			if(Arc[i].from>Arc[i].to){
				int t=Arc[i].from;
				Arc[i].from=Arc[i].to;
				Arc[i].to=t;
			}
		}
		sort(Arc,Arc+N);
		For(i,N){
			node[X+Arc[i].from].V.push_back(i);
		}
		for(int i=-999;i<=999;i++){
			int n=node[X+i].V.size();
			for(int j=0;j<n;j++){
				int I=node[X+i].V[j];
				node[X+Arc[I].to];
				if(node[X+Arc[I].to].num <node[X+i].num+1){
					Node &temp=node[X+Arc[I].to];
					temp.num=node[X+i].num+1;
					temp.M=node[X+i].M;
					temp.M.set(I);
				}
			}
			if(i<999&&node[X+i+1].num<node[X+i].num){
				node[X+i+1].num=node[X+i].num;
				node[X+i+1].M=node[X+i].M;
			}
		}
		int ANS=0;Mark ANSM;
		for(int i=-999;i<=999;i++){
			if(node[X+i].num>ANS){
				ANS=node[X+i].num;
				ANSM=node[X+i].M;
			}
		}
		cout<<ANS<<endl;
		For(i,N){
			if(ANSM.is(i)){
				printf("%d %d\n",Arc[i].from,Arc[i].to);
			}
		}
	}
	
return 0;
}








