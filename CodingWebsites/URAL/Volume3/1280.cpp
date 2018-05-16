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
using namespace std;
struct Node{
	vector<int>to;
	vector<int>from;
}node[1000]; 
void Arc(int from,int to){
	node[from].to.push_back(to);
	node[to].from.push_back(from);
}
int N,M;
int main(void)
{freopen("1280.txt","r",stdin); 
	while(cin>>N>>M){
		For(i,M){
			int a,b;
			scanf("%d%d",&a,&b);--a,--b;
			Arc(a,b);
		}
		int ERR=0;//没有矛盾 
		int n;
		For(i,N){
			scanf("%d",&n);n--;
			if(ERR) continue;
			if(node[n].from.size()>0) {
				ERR=1;continue;
			}
			//OUT1(n); 
			For(j,node[n].to.size()){
				int to=node[n].to[j]; 
				vector<int>::iterator it=find(node[to].from.begin(),node[to].from.end(),n);
				if(it!=node[to].from.end()) {
					node[to].from.erase(it);
					//printf("\t删掉了%d里的%d\n",to+1,n+1);
				}
				//else{
					//printf("\t找不到%d里的%d\n",to+1,n+1);
				//}
			}
			node[n].to.clear();
			/*
			For(j,N){
				printf("节点%d:",j+1);
				For(k,node[j].from.size()){
					printf("->%d",node[j].from[k]+1);
				}
				cout<<endl;
			}
			
			cout<<endl<<endl;*/
		}
		if(ERR) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
return 0;
}








