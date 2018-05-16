#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

using namespace std;

int n,m; long long D;//原答案 
int a[100000];
int vis[100001];
struct ArcNode{
	int value;
	ArcNode *next;
};
struct A{
	int n;//取值
	ArcNode *List;//链表
	long long D;//优化量 
	A():n(0),List(NULL),D(0){}
	void insert(int n){
		ArcNode *temp=new ArcNode;
		temp->value=n;temp->next=List;List=temp;
	}
};
A Number[100000];int nA; 

int main(void)
{
	freopen("C.txt","r",stdin); 
	
	while(cin>>m>>n){
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		memset(vis,-1,sizeof(vis));
		
		nA=0;D=0;
		for(int i=0;i<n;i++){
			if(i) D+=abs(a[i]-a[i-1]); 
			
			if(i>0) {//判断前一位 
				if(a[i-1]!=a[i]) {//如果不等 
					if(vis[a[i]]==-1) {//如果没出现过 
						vis[a[i]]=nA;
						Number[nA].insert(a[i-1]);
						Number[nA++].n=a[i];
					}
					else {//出现过 
						Number[vis[a[i]]].insert(a[i-1]);
					} 
				}
			}
			if(i<n-1){//判断后一位 
				if(a[i+1]!=a[i]) {//如果不等 
					if(vis[a[i]]==-1) {//如果没出现过 
						vis[a[i]]=nA;
						Number[nA].insert(a[i+1]);
						Number[nA++].n=a[i];
					}
					else {//出现过 
						Number[vis[a[i]]].insert(a[i+1]);
					} 
				}
			}
		}
		/* 
		for(int i=0;i<nA;i++){
			OUT2(i,Number[i].n);
			ArcNode *temp=Number[i].List;
			while(temp!=NULL){
				printf(" %d",temp->value);
				temp=temp->next;
			}
			cout<<endl;
		}
		*/ 
		
		for(int i=0;i<nA;i++){
			int count=0;
			ArcNode *temp;
			long long PreANS=0;
			while(Number[i].List!=NULL){
				temp=Number[i].List;
				Number[i].List=temp->next;
				a[count++]=temp->value;
				PreANS+=abs(temp->value-Number[i].n);
				free(temp);
			}
			//printf("a[%d]:  ",i);
			//for(int j=0;j<count;j++)  printf("%d ",a[j]);
			//printf("\n");
			sort(a,a+count);
			//printf("a[%d]:  ",i);
			//for(int j=0;j<count;j++)  printf("%d ",a[j]);
			//printf("\n");
			int L=0,R=count-1;
			long long ANS=0;
			while(R-L>=1){
				ANS+=a[R--]-a[L++];
			}
			Number[i].D=PreANS-ANS;
		//	OUT3(i,PreANS,ANS);
		}
		
		long long MAX=0;
		for(int i=0;i<nA;i++){
			MAX=MAX>Number[i].D?MAX:Number[i].D;
		}
	//	OUT1(D);
		cout<<(D-MAX)<<endl;
	}
return 0;
}














