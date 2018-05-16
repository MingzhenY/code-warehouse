#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
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
	bool vis;
	bool Is;
	string name;
	int a,b,c;
	vector<int>List;
	bool operator<(const Node&B)const{
		return ((a<B.a)+(b <B.b)+(c<B.c))>1;
	}
}node[200];
void Arc(int  from,int to){
	node[from].List.push_back(to);
}
int N;int ALL;
queue<int>Q;
bool Inq[200];
void Bfs(int cnt){
	node[cnt].vis=1;ALL--;
	//OUT1(cnt);
	int n=node[cnt].List.size();
	For(i,n){
		if(!node[node[cnt].List[i]].vis){
			if(!Inq[node[cnt].List[i]]) Q.push(node[cnt].List[i]),Inq[node[cnt].List[i]]=1;
		}
	}
}
int main(void)
{
	freopen("1218.txt","r",stdin); 
	while(cin>>N){
		For(i,N){
			cin>>node[i].name;
			scanf("%d%d%d",&node[i].a,&node[i].b,&node[i].c);
			node[i].List.clear();node[i].Is=0;
		}
		For(i,N){
			for(int j=i+1;j<N;j++){
				if(node[i]<node[j]){
					Arc(j,i);
				}
				else Arc(i,j);
			}
		}/*
		For(i,N){
			printf("½Úµã%d:",i+1);
			For(j,node[i].List.size()){
				printf("->%d",node[i].List[j]+1);
			}cout<<endl;
		}*/
		For(i,N){
			ALL=N;
			For(j,N) node[j].vis=0,Inq[j]=0;
			Q.push(i);Inq[i]=1;
			while(!Q.empty()){
				int cnt=Q.front();Q.pop();
				Inq[cnt]=0;
				Bfs(cnt);
			}
			if(!ALL) node[i].Is=1;
		}
		
		For(i,N){
			if(node[i].Is){
				cout<<node[i].name<<endl;
			}
		}
	}
return 0;
}








