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
	int k;
	Node*ls,*rs;
	Node():ls(NULL),rs(NULL){}
}; 

Node *Create(vector<int> A){
	vector<int> L,R;
	int M=A[A.size()-1];
	Node *temp=new Node;
	temp->k=M;
	For(i,A.size()-1){
		if(A[i]<M) L.push_back(A[i]);
		else R.push_back(A[i]);
	} 
	//OUT3(M,L.size(),R.size());
	if(L.size()) temp->ls=Create(L);
	else temp->ls=NULL;
	if(R.size()) temp->rs=Create(R);
	else temp->rs=NULL;
	return temp;
}
int Flag;
void DFS(Node *rt){
	if(rt->rs) DFS(rt->rs);
	if(rt->ls) DFS(rt->ls);	
	if(Flag) printf("%d",rt->k),Flag=0;
	else printf(" %d",rt->k);
}
int main(void)
{freopen("1136.txt","r",stdin); 
	int N;
	vector<int> A;
	cin>>N;
	For(i,N){
		int a;
		cin>>a;
		A.push_back(a);
	}
	Node *root=Create(A);
	Flag=1;
	DFS(root);
return 0;
}








