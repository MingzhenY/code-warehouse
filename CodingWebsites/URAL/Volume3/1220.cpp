#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;

struct ArcNode{
	int v;
	ArcNode*next;
};
struct Stack{
	ArcNode *List[1001]; 
	Stack(){
		memset(List,0,sizeof(List));
	}
	void clear(){
		memset(List,0,sizeof(List));
	}
	void push(int k,int v){
		ArcNode*temp=new ArcNode;
		temp->v=v;
		temp->next=List[k];
		List[k]=temp;
	}
	int pop(int k){
		int ANS=0;
		if(List[k]){
			ArcNode*temp=List[k];
			List[k]=List[k]->next;
			ANS=temp->v;
			delete temp;
		}
		return ANS;
	}
	~Stack(){
		For(i,1001){
			while(List[i]){
				ArcNode*temp=List[i];
				List[i]=List[i]->next;
				delete temp;
			}
		}
	}
}; 

int N;
Stack D;
int main(void)
{freopen("1220.txt","r",stdin); 
	while(~scanf("%d",&N)){
		D.clear();
		For(i,N){
			char s[10];scanf("%s",s);
			if(s[1]=='U'){
				int a,b;
				scanf("%d%d",&a,&b);
				D.push(a,b);
			}
			else{
				int a;
				scanf("%d",&a);
				int ANS=D.pop(a);
				printf("%d\n",ANS);
			}
		}
	}
return 0;
}








