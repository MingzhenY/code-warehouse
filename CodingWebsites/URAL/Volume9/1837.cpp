#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
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
	int dis;
	string name;
	vector<int>List;
	bool operator <(const Node&B)const{
		return name<B.name;
	}
}node[300];int NP;
void Arc(int from,int to){
	node[from].List.push_back(to);
	node[to].List.push_back(from);
}
int N;queue<int>Q;
void BFS(int i){
	For(k,node[i].List.size()){
		int to=node[i].List[k];
		if(!~node[to].dis){
			node[to].dis=node[i].dis+1;
			Q.push(to);
		}
	}
}
int main(void)
{freopen("1837.txt","r",stdin); 
	while(cin>>N){
		NP=0;int start=-1;
		string base="Isenbaev";
		map<string,int> MP;
		For(i,300) node[i].List.clear();
		//建图 
		For(i,N){
			string a,b,c;
			cin>>a>>b>>c;
			if(!MP.count(a)) {
				if(a==base) start=NP;
				MP[a]=NP;
				node[NP++].name=a;
			}
			if(!MP.count(b)) {
				if(b==base) start=NP;
				MP[b]=NP;
				node[NP++].name=b;
			}
			if(!MP.count(c)) {
				if(c==base) start=NP;
				MP[c]=NP;
				node[NP++].name=c;
			}
			Arc(MP[a],MP[b]);
			Arc(MP[a],MP[c]);
			Arc(MP[c],MP[b]);
		}
		//BFS最短路 
		For(i,NP) node[i].dis=-1;
		
		if(~start){
			while(!Q.empty()) Q.pop();
			Q.push(start);node[start].dis=0;
			while(!Q.empty()){
				int Cnt=Q.front();Q.pop();
				BFS(Cnt); 
			}	
		} 
		// 排序
		sort(node,node+NP); 
		//输出 
		For(i,NP){
			cout<<node[i].name;
			if(~node[i].dis) printf(" %d\n",node[i].dis);
			else printf(" undefined\n");
		}
		
	}
	
	
	
	
return 0;
}








