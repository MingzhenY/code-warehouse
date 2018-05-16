/*
2014.7.25
������ ���鼯 + DFS ��
����ͼ���Բ���ͨ���Ƚ�����ͼ��ͨ��Ȼ��DFS�������·�� 
WA on test #5    �ϲ�����ͨͼ�Ĺ���û�п������ơ��� 
*/


#include <iostream>
#include <cstdio>
#include <cmath>

#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
struct ArcNode{
	int from,to;
	ArcNode *next;
};
struct Node{
	ArcNode *List;
	int pa;
	int vis;
	Node():List(NULL),pa(0),vis(0){}
};
Node node[101];
int ISS[101];
void Arc(int from,int to){
	ArcNode *temp=new(ArcNode);
	temp->from=from;temp->to=to;
	temp->next=node[from].List;
	node[from].List=temp;
}
int N;
int ALL;int ANS;
void DFS(int h,int i,int level);
void F(int i);
int z[101];
int Find(int i){
	if(z[i]==i) return i;
	else return z[i]=Find(z[i]);
}
void Union(int a,int b){
	int x=Find(a),y=Find(b);
	if(x==y) return;
	z[x]=y;ALL--;
}
int main(void)
{freopen("1022.txt","r",stdin); 
	while(cin>>N){
		FOR(i,N) ISS[i]=0,z[i]=i;ALL=N;
		//OUT1(N);
		//���� 
		FOR(i,N){
			int a;
			scanf("%d",&a),ISS[a]=1;
			while(a) {
				Arc(i,a);Union(i,a);
				scanf("%d",&a);
			}
		}
		//�ϲ�����ͨͼ
		FOR(i,N){
			if(node[i].List==NULL){//��������û�г��ߵĵ� 
				FOR(j,N){
					if(ISS[j]==0){//��������û����ߵĵ� 
						if(Find(i)!=Find(j)){//�������ͨ����������ͨ 
							Arc(i,j);Union(i,j);ISS[j]=1;break;
						}
					}
				}
			}
		}
		if(ALL>1){
			FOR(i,N){
				if(node[i].List==NULL){//��������û�г��ߵĵ� 
					FOR(j,N){
						if(Find(i)!=Find(j)){//�������ͨ����������ͨ 
							Arc(i,j);Union(i,j);ISS[j]=1;break;
						}
					}
				}
			}
		}
		if(ALL>1){
			FOR(i,N){
				FOR(j,N){
					if(ISS[j]==0){//��������û����ߵĵ� 
						if(Find(i)!=Find(j)){//�������ͨ����������ͨ 
							Arc(i,j);Union(i,j);ISS[j]=1;break;
						}
					}
				}
			}
		}
		if(ALL>1){
			FOR(i,N){
				FOR(j,N){
					if(Find(i)!=Find(j)){//�������ͨ����������ͨ 
						Arc(i,j);Union(i,j);ISS[j]=1;break;
					}
				}
			}
		}
		ANS=-1;
		//���� 
		for(int i=1;i<=N;i++){
			if(ISS[i]) continue;
			node[i].pa=i;
			DFS(-1,i,0);
		}
	    //OUT1(ANS);
		
		F(ANS);
		
		cout<<endl;
		//�ͷ� 
		FOR(i,N){
			while(node[i].List){
				ArcNode *temp=node[i].List;
				node[i].List=node[i].List->next;
				delete temp;
			}
		}
	}
	
	
return 0;
}
void F(int i){
	if(i<=0) return;
	if(node[i].pa==i) {
		printf("%d",i);return;
	}
	else{
		F(node[i].pa);
		printf(" %d",i);
	}
	
}
void DFS(int h,int i,int level){
	if(~ANS) return ;
	if(node[i].vis) return;
	if(level==N-1){
		node[i].pa=h;
		ANS=i;
		return;
	}
	ArcNode *temp=node[i].List;
	while(temp){
		node[i].vis=1;
		node[temp->to].pa=i;
		DFS(i,temp->to,level+1);
		node[i].vis=0;
		if(~ANS) return ;
		temp=temp->next;
	}
}







