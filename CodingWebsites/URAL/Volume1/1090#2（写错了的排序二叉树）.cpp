#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

struct Node{
	int v;//数的大小
	int D;
	int Big;//比这个数大的数量 
	Node *ls,*rs;//左右子树。
	Node():D(0),Big(0),ls(NULL),rs(NULL){}
};
int N,K;
Node *Root;int ALL=0;int tempA=0;int ANS;
int DFS(Node **rt,Node *cnt){
	if(*rt){
		if(cnt->v>(*rt)->v){
			
			printf("新来的数据%d大:\n",cnt->v);
			printf("本节数据v:%d,big:%d,D:%d ",(*rt)->v,(*rt)->Big,(*rt)-> D);
			if((*rt)->ls) printf("ls:%d ",(*rt)->ls->v);
			if((*rt)->rs) printf("rs:%d ",(*rt)->rs->v);
			cout<<endl;
		
			
			//if(!(*rt)->ls) cnt->D+=(*rt)->Big;
			DFS(&(*rt)->ls,cnt);
			(*rt)->Big++;
			(*rt)->D++;
		}
		else{
			
			printf("新来的数据%d小:\n",cnt->v);
			printf("本节数据v:%d,big:%d,D:%d ",(*rt)->v,(*rt)->Big,(*rt)->D);
			if((*rt)->ls) printf("ls:%d ",(*rt)->ls->v);
			if((*rt)->rs) printf("rs:%d ",(*rt)->rs->v);
			cout<<endl;
			
			
			if((*rt)->rs) ;//cnt->D+=(*rt)->D;
			else cnt->D+=(*rt)->Big+1;
			DFS(&(*rt)->rs,cnt);
		}
	}
	else{
		OUT2(cnt->v,cnt->D);
		(*rt)=cnt;
		tempA+=cnt->D;
		cnt->Big=cnt->D;
		cnt->D=0;
	}
}
void Del(Node *rt){
	if(rt->ls) {
		Del(rt->ls);
		delete rt->ls;
	}
	if(rt->rs) {
		Del(rt->rs);
		delete rt->rs;
	}
}
int main(void)
{freopen("1090.txt","r",stdin); 
	while(cin>>N>>K){
		
		ALL=-1;ANS=0;
		for(int i=0;i<K;i++){
			tempA=0;Root=NULL;
			for(int j=0;j<N;j++){
				Node *temp=new Node;
				scanf("%d",&temp->v);
				DFS(&Root,temp);
				//OUT2(Root,temp);
			}
			OUT2(i,tempA);
			if(~ALL) {
				if(tempA>ALL) ALL=tempA,ANS=i+1;
			}
			else ALL=tempA,ANS=i+1;
			
		}
		
		cout<<ANS<<endl;
	}
return 0;
}








