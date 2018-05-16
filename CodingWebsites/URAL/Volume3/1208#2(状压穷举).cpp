#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
struct Node{
	string name[3];
	int mask; 
	bool is(int i){
		return (mask<<i)&1;
	}
	void set(int i){
		mask|=(1<<i);
	}
	void reset(int i){
		mask&=~(1<<i);
	}
	void show(){
		for(int i=0;i<18;i++){
			printf("%d ",(mask>>i)&1);
		}
		cout<<endl;
	}
	void init(){
		mask=0;
	}
}node[18];
int N; 
int main(void)
{freopen("1208.txt","r",stdin); 
	while(cin>>N){
		//¶ÁÈ¡ 
		For(i,N){
			node[i].init();
			For(j,3) cin>>node[i].name[j];
		}
		//½¨Í¼ 
		For(i,N){
			for(int j=i+1;j<N;j++){
				int T=0;
				For(k,3){
					For(s,3){
						if(node[i].name[k]==node[j].name[s]){
							node[i].set(j);
							node[j].set(i);
							T=1;break;
						}
					}
					if(T) break;
				}
			}
		}
		//¼ÆËã
		int ANS=0;
		for(int i=1;i<(1<<N);i++){
			int tempANS=0;int T=0;
			For(j,N){
				if((i>>j)&1){tempANS++;
					if(node[j].mask&i) {
						T=1;break; 
					}
				}
			}
			if(T) continue;
			if(tempANS>ANS) ANS=tempANS;
		}
		cout<<ANS<<endl;
	}
return 0;
}








