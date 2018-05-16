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
//#define Debug
using namespace std;
int max(int a,int b) {return a>b?a:b;}
int min(int a,int b) {return a<b?a:b;}
int zdgys(int a,int b){while(b){int t=a;a=b;b=t%b;}return a;} 
int zxgbs(int a,int b){return a/zdgys(a,b)*b;}

int n,k,p;
int a[100000];
int b[100000];

struct ArcNode{
	int v;
	ArcNode *next;
};
ArcNode *List[100000];
int NofList[100000];
void Arc(int i,int v){
	ArcNode *temp=new ArcNode;
	temp->v=v;temp->next=List[i];
	List[i]=temp;
	NofList[i]++;
	#ifdef Debug
	OUT2(i,v);
	#endif
}

int main(void)
{
	freopen("C.txt","r",stdin); 
	while(cin>>n>>k>>p){
		if(n<0)break;
		int A=0,B=0;//奇数，偶数个数。 
		int temp;
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			List[i]=NULL;NofList[i]=0;
			
			if(temp&1) a[A++]=temp;else b[B++]=temp;
		}
		#ifdef Debug
		OUT2(A,B);
		#endif
		int NeedEven=p;
		if(B>=p) NeedEven=0;else NeedEven=p-B;
		int Q=A;
		Q-=NeedEven*2;Q-=k-p;
		
		if(Q<0||(Q&1)) printf("NO\n");
		else{
			printf("YES\n");
			int tempA=0,tempB=0;
			for(int i=0;i<k;i++){
				#ifdef Debug
				OUT3(i,tempA,tempB);
				OUT1(p);
				#endif
				if(i<p){
					if(tempB<B) {
						Arc(i,b[tempB++]);
						continue;
					}
				//	OUT2(tempA,A);
					if(tempA<(A-1)){
						Arc(i,a[tempA++]);
						Arc(i,a[tempA++]);
						continue;
					}
					printf("WRONG#1,tempA=%d,tempB=%d\n",tempA,tempB);
				}
				else{
					if(tempA<A){
						Arc(i,a[tempA++]);
						continue;
					}
					printf("WRONG#2\n");
				}
			} 
			
			int T=!(k==1);
			while(tempA<A) Arc(T,a[tempA++]);
			while(tempB<B) Arc(0,b[tempB++]);			
			
			for(int i=0;i<k;i++){
				printf("%d",NofList[i]);
				ArcNode *temp;
				while(List[i]!=NULL){
					printf(" %d",List[i]->v);
					temp=List[i];List[i]=temp->next;
					delete(temp);
				}
				printf("\n");
			}
		
		}
		
	}
return 0;
}














