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
struct ArcNode{
	int L,R;
	ArcNode*next;
};
int N,M,L;
struct Game{
	ArcNode *H[30001];
	ArcNode *V[30001];
	Game(){
		FOR(i,N) {
			ArcNode*temp=new ArcNode;
			temp->L=1;temp->R=M;
			H[i]=temp;
			temp->next=NULL;
		}
		FOR(i,M){
			ArcNode*temp=new ArcNode;
			temp->L=1;temp->R=N;
			V[i]=temp;
			temp->next=NULL;
		}
	}
	void Add_V(int k,int L,int R){
		if(k<1||k>M) return;
		if(L <1) L=1;if(R>N) R=N; 
		ArcNode *List=NULL;
		while(V[k]){
			//取出
			ArcNode *temp=V[k];
			V[k]=V[k]->next;
			//判断，操作
			if(temp->L <=L&&R <= temp->R){
				ArcNode *cnt;
				if(temp->L <L){
					cnt=new ArcNode;
					cnt->L=temp->L;
					cnt->R=L-1;
					cnt->next=List;
					List=cnt;
				}
				if(R<temp->R){
					cnt=new ArcNode;
					cnt->L=R+1;
					cnt->R=temp->R;
					cnt->next=List;
					List=cnt;
				}
				delete temp;
			}
			else if(L <=temp->L&&R>=temp->R){
				
			}else if(temp->R <L||temp->L>R){
				temp->next=List;
				List=temp;
			}
			else if(temp->L <=L&&temp->R <=R){
				ArcNode *cnt;
				if(temp->L <L){
					cnt=new ArcNode;
					cnt->L=temp->L;
					cnt->R=L-1;
					cnt->next=List;
					List=cnt;
				}
			}else if(temp->L>=L&&temp->R>=R){
				ArcNode *cnt;
				if(R <temp->R){
					cnt=new ArcNode;
					cnt->L=R+1;
					cnt->R=temp->R;
					cnt->next=List;
					List=cnt;
				}
			}
		}
		V[k]=List;
	}
	void Add_H(int k,int L,int R){
		if(k<1||k>N) return;
		//OUT3(k,L,R);
		if(L <1) L=1;if(R>M) R=M; 
		ArcNode *List=NULL;
		while(H[k]){
			//取出
			ArcNode *temp=H[k];
			H[k]=H[k]->next;
			//OUT2(temp->L,temp->R);
			//判断，操作
			if(temp->L <=L&&R <= temp->R){
				//OUT1(1);
				ArcNode *cnt;
				if(temp->L <L){
					cnt=new ArcNode;
					cnt->L=temp->L;
					cnt->R=L-1;
					cnt->next=List;
					List=cnt;
				}
				if(R <temp->R){
					//OUT2(R,temp->R);
					cnt=new ArcNode;
					cnt->L=R+1;
					cnt->R=temp->R;
					cnt->next=List;
					List=cnt;
				}
			}
			else if(L <=temp->L&&R>=temp->R){
				//OUT1(2);
			}else if(temp->R <L||temp->L>R){
				temp->next=List;
				List=temp;
			}
			else if(temp->L <=L&&temp->R <=R){
				//OUT1(3);
				ArcNode *cnt;
				if(temp->L <L){
					cnt=new ArcNode;
					cnt->L=temp->L;
					cnt->R=L-1;
					cnt->next=List;
					List=cnt;
				}
			}else if(temp->L>=L&&temp->R>=R){
				//OUT1(4);
				ArcNode *cnt;
				if(R <temp->R){
					cnt=new ArcNode;
					cnt->L=R+1;
					cnt->R=temp->R;
					cnt->next=List;
					List=cnt;
				}
			}
		}
		H[k]=List;
	}
	long long check(int Len){
		long long ANS=0;
		FOR(i,N){
			ArcNode*temp=H[i];
			while(temp){
				long long D=temp->R-temp->L+1;
				if(D>=Len) ANS+=D-Len+1;
				temp=temp->next;
			}
		}
		FOR(i,M){
			ArcNode*temp=V[i];
			while(temp){
				long long D=temp->R-temp->L+1;
				if(D>=Len) ANS+=D-Len+1;
				temp=temp->next;
			}
		}
		if(Len==1) ANS>>=1;
		return ANS;
	}
	void show(){
		printf("行开始:\n");
		FOR(i,N){
			ArcNode*temp=H[i];
			printf("\t节点%d:",i);
			while(temp){
				printf("->(%d,%d)",temp->L,temp->R);
				temp=temp->next;
			}cout<<endl;
		}
		printf("列开始:\n");
		FOR(i,M){
			ArcNode*temp=V[i];
			printf("\t节点%d:",i);
			while(temp){
				printf("->(%d,%d)",temp->L,temp->R);
				temp=temp->next;
			}cout<<endl;
		}
	}
	~Game(){
		FOR(i,N){
			while(H[i]){
				ArcNode*temp=H[i];
				H[i]=H[i]->next;
				delete temp;
			}
		}
		FOR(i,M){
			while(V[i]){
				ArcNode*temp=V[i];
				V[i]=V[i]->next;
				delete temp;
			}
		}
	}
};


int main(void)
{freopen("1212.txt","r",stdin); 
	while(cin>>N>>M>>L){
		Game G;
		//G.show();
		For(i,L){
			int a,b,c;char v;
			scanf("%d%d%d %c",&b,&a,&c,&v);
			if(v=='H'){
				G.Add_H(a-1,b-1,b+c);
				G.Add_H(a,b-1,b+c);
				G.Add_H(a+1,b-1,b+c);
				for(int j=-1;j<=c;j++){
					G.Add_V(b+j,a-1,a+1);
				}
			}
			else{
				G.Add_V(b-1,a-1,a+c);
				G.Add_V(b,a-1,a+c);
				G.Add_V(b+1,a-1,a+c);
				for(int j=-1;j<=c;j++){
					G.Add_H(a+j,b-1,b+1);
				}
			}
			//printf("操作：%c ",v);
			//OUT3(a,b,c);
			//G.show();
		}
		int S;cin>>S;
		long long ANS=G.check(S); 
		cout<<ANS<<endl;
	}
return 0;
}








