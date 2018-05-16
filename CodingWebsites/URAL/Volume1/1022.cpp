#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
using namespace std;
struct ArcNode{
	int from,to;
	ArcNode *nextOut;//出边表 
	ArcNode *nextIn;//入边表 
};
struct Node{
	ArcNode *In;
	ArcNode *Out;
	int K;//入度
	int vis;
	Node():In(NULL),Out(NULL),K(0),vis(0){}
	bool operator <(const Node &B)const{
		return K<B.K; 
	} 
}node[101];
void Arc(int from,int to){
	ArcNode *temp=new(ArcNode);
	temp->from=from;temp->to=to;
	//接进入边表 
	temp->nextIn=node[to].In;node[to].In=temp;node[to].K++;
	//接进出边表
	temp->nextOut=node[from].Out;node[from].Out=temp;
}
void DeleNode(int i){
	//删除出边 
	while(node[i].Out){
		ArcNode *temp=node[i].Out;
		node[i].Out=node[i].Out->nextOut;
		node[temp->to].K--;
			//删除to节点的入边;
			if(node[temp->to].In==temp){
				node[temp->to].In=temp->nextIn;
			}
			else{
				ArcNode *temp2=node[temp->to].In;
				while(temp2){
					if(temp2->nextIn==temp){
						temp2->nextIn=temp->nextIn;
						break;
					}
					temp2=temp2->nextIn;
				}
			}
		delete temp;
	}
	//删除入边
	while(node[i].In){
		ArcNode *temp=node[i].In;
		node[i].In=node[i].In->nextIn;
		node[i].K--;
			//删除from节点的出边;
			if(node[temp->from].Out==temp){
				node[temp->from].Out=temp->nextOut;
			}
			else{
				ArcNode *temp2=node[temp->from].Out;
				while(temp2){
					if(temp2->nextOut==temp){
						temp2->nextOut=temp->nextOut;
						break;
					}
					temp2=temp2->nextOut;
				}
			}
		delete temp;
	}
}
struct A{
	int i;
	int K;
	bool operator<(const A&B)const{
		return K <B.K; 
	}
}AA[101];
int N;
int main(void)
{freopen("1022.txt","r",stdin); 
	while(cin>>N){
		FOR(i,N) node[i].K=0,node[i].vis=1;
		//建边 
		FOR(i,N){
			int a;
			scanf("%d",&a);
			while(a) {
				Arc(i,a);
				scanf("%d",&a);
			}
		}
		 //计算
		int ALL=N;
		while(ALL>0){
			for(int i=1;i<=N;i++){
				AA[i].i=i;AA[i].K=node[i].K;
			}
			sort(AA+1,AA+N+1);//排序找到入度最小的边 
			int Cur=1;
			while(!node[AA[Cur].i].vis) Cur++; 
			DeleNode(AA[Cur].i);node[AA[Cur].i].vis=0;
			ALL--;
			if(ALL) printf("%d ",AA[Cur].i);
			else printf("%d\n",AA[Cur].i);
		}
	}
return 0;
}








