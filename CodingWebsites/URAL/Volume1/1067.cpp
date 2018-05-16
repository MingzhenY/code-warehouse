#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
struct S{
	string a;int i;
	S(){}
	S(string a,int i):a(a),i(i){} 
	bool operator <(const S&B)const{
		return a>B.a; 
	}
};
struct Node{
	string str;
	vector <int>List;
	bool operator <(const Node &B)const{
		return str<B.str;
	}
}node[100000];int NN;
int N;
int DFS(int i,int depth){
	For(j,depth) printf(" ");
	if(~depth) cout<<node[i].str<<endl;
	priority_queue <S> Q;
	For(j,node[i].List.size())
		Q.push(S(node[node[i].List[j]].str,node[i].List[j]));
	while(!Q.empty()){
		S temp=Q.top();Q.pop();
		//For(j,depth) printf(" ");
		//cout<<temp.a<<endl;
		DFS(temp.i,depth+1);
	}
}
int main(void)
{freopen("1067.txt","r",stdin); 
	while(cin>>N){
		//预处理 
		For(i,5000) node[i].List.clear(); 
		NN=1;
		for(int i=0;i<N;i++){
			string str;
			string a;int I;
			Node *Fa=&node[0];
			cin>>str;
			start:
				a.assign(str,0,str.find('\\'));
				//如果存在，找到节点I，否则，给I赋值。 
				I=-1;
				For(j,Fa->List.size()){
					if(node[Fa->List[j]].str==a) {
						I=Fa->List[j];break;
					}
				}
				if(!~I) {
					I=NN,NN++;
					Fa->List.push_back(I);
					node[I].str=a;
				}
				//建边 
				Fa=&node[I];
				//处理输入 
				if(str.find('\\')!=str.npos){
					str.erase(0,str.find('\\')+1);
					goto start;
				}
		}
		//输出 
		DFS(0,-1);
	}
return 0;
}








