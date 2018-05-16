#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
int gcd(int a,int b){while(b){int t=a%b;a=b;b=t;} return a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
struct ArcNode{
	int to;
	ArcNode *next;
};
struct Node{
	int vis;
	ArcNode* List;
};
Node node[1000];
int D[1000];
int N;
void Arc(int i,int to){
	ArcNode *temp=new(ArcNode);
	temp->to=to;
	temp->next=node[i].List;
	//OUT1(temp);
	node[i].List=temp; 
	//printf("成功建立：");OUT2(i,to);
} 
int DFS(int i);
int main(void)
{freopen("1024.txt","r",stdin); 

	cin>>N;
	int a;
	for(int i=0;i<N;i++){
		scanf("%d",&a);
		Arc(i,a-1);
		node[i].vis=0;
	}
	int ANS=1;
	for(int i=0;i<N;i++){
		
		ANS=lcm(ANS,DFS(i));
	}
	cout<<ANS<<endl;
	
	for(int i=0;i<N;i++){
		delete node[i].List;
	}
	
return 0;
}
int DFS(int i){
	//OUT1(i);
	if(node[i].vis) return 1;
	node[i].vis=1;
	ArcNode *temp=node[i].List;
	if(temp){
		if(node[temp->to].vis) return 1;
	else return DFS(temp->to)+1;
	}
	else{
		printf("ERROR!\n");
	}
}







