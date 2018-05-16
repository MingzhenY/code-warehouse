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
//#define ZRT
using namespace std;

struct Node{
	int L,R;//������ 
	bool Flag;//����Ǻ�1����0 
	Node *next;
}; 
Node *List; //���������ͷָ�� 
int N;
Node *NewList=NULL,*NewEnd=NULL;
void Insert(int a,int b,bool v); //������ɫ 
void Add(Node *T);//��T���������� 
Node *AddIn(int a,int b,bool v);//��������������һ�� ����Ľṹ�塣 
void show();
int main(void)
{freopen("1019.txt","r",stdin); 
//freopen("CON","r",stdin); 
	while(cin>>N){
		Node *temp=new Node;List=NULL;
		temp->L=0;temp->R=1000000000;temp->Flag=0;
		temp->next=List;List=temp;
		
		For(i,N) {
			int a,b;char c;
			cin>>a>>b>>c;
			Insert(a,b,c=='b');
			#ifdef ZRT 
			show();
			#endif
			
		}
		int Max=-1;int L=-1,R=-1;
		//printf("FINAL\n");
		//show();
		temp=List;
		while(temp){
			//OUT2(temp->L,temp->R);
			if(!temp->Flag) if(temp->R-temp->L>Max) Max=temp->R-temp->L,L=temp->L,R=temp->R; 
			temp=temp->next;
		}
		printf("%d %d\n",L,R);
	}
return 0;
}
void Insert(int a,int b,bool v){
	NewList=NULL;NewEnd=NULL;
	int T=0;//�Ƿ��Ѿ���ɲ����� 
	while(List){
		//ȡ��һ��Ԫ�� 
		#ifdef ZRT
		printf("\n\tȡ������:%d->%d,��ɫ:",List->L,List->R);
		if(List->Flag) printf("��\n");
		else printf("��\n");
		printf("��ʱҪ����������ǣ�%d->%d T:%d\n",a,b,T);
		#endif
		
		Node *temp=List;
		List=List->next;
		if(T || (temp->R < a) ) {
			Add(temp); 
			#ifdef ZRT
			printf("\t�������Ż�\n");
			#endif
			continue;
		}
		//�Ƚ��Ƿ���Ҫ����,��������������� 
		
		if(b <=temp->R){
			if(temp->Flag!=v){
				Add(AddIn(temp->L,a,temp->Flag));
				Add(AddIn(a,b,v));
				Add(AddIn(b,temp->R,temp->Flag));
				#ifdef ZRT 
				printf("\t�ָ��3����\n");
				#endif
				T=1;continue;
			}
			else{
				Add(temp);
				#ifdef ZRT 
				printf("\t�������Ż�\n");
				#endif
				T=1;
				continue;
			}
			
		}
		else{
			if(temp->Flag!=v){
				Add(AddIn(temp->L,a,temp->Flag));
				Add(AddIn(a,temp->R,v));
				#ifdef ZRT 
				printf("\t�ָ��2���䣬�ı�����%d->%d Ϊ %d->%d\n",a,b,temp->R,b);
				#endif
				a=temp->R;
			}
			else{
				#ifdef ZRT 
				printf("\t�������Żأ��ı�����%d->%d Ϊ %d->%d\n",a,b,temp->R,b);
				#endif
				a=temp->R;
				Add(temp);
					
			}
			
		}
	}
	List=NewList;
}
void Add(Node *T){
	if(T==NULL) return;
	T->next=NULL;
	if(NewEnd){
		if(NewEnd->R==T->L){
			if(NewEnd->Flag==T->Flag){
				NewEnd->R=T->R;
				delete T;
				return;
			}
		}
		NewEnd->next=T;
		NewEnd=T;
		NewEnd->next=NULL;
	}
	else{
		NewList=T;
		NewEnd=T;
		NewEnd->next=NULL;
	}
}
Node *AddIn(int a,int b,bool v){
	if(a>=b) return NULL;
	Node *temp=new Node;
	temp->L=a,temp->R=b,temp->Flag=v;temp->next=NULL;
	return temp;
}
void show(){
	printf("\n������ʾ��ʼ\n");
	Node *temp=List;
	while(temp){
		printf("\n\t����%d->%d   ����:%d ��ɫ:",temp->L,temp->R,temp->R-temp->L);
		if(temp->Flag) printf("��\n");
		else printf("��\n");
		temp=temp->next;
	}
}



