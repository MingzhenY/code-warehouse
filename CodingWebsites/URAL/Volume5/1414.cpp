#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x1fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
struct Node{
	Node *next[36];//Êý×Ö-48,×ÖÄ¸-87
	bool isEnd;
	Node(){memset(next,0,sizeof(next));isEnd=0;}
}; 
Node *T;
void Insert(Node *A,char *a){
	if(*a){
		int I=*a>='a'?*a-87:*a-48;
		if(!A->next[I]){A->next[I]=new Node;}
		Insert(A->next[I],a+1);
	}
	else{A->isEnd=1;}
}
//Ð¡Õ» 
char st[30];int stn=0;
int Show(Node *A,int &n){
	if(n){
		if(A->isEnd){
			for(int i=0;i<stn;++i) printf("%c",st[i]);
			printf("\n");n--;
		}
		for(int i=0;i<36;++i){
			if(A->next[i]){
				st[stn++]=i<10?i+48:i+87;
				Show(A->next[i],n);
				stn--;
			}
		}
	}
	else return 0;
}
int Find(Node *A,char *a){
	if(*a){
		int I=*a>='a'?*a-87:*a-48;
		if(A->next[I]){
			st[stn++]=*a;
			Find(A->next[I],a+1);
		}
	}
	else{
		int n=20;
		Show(A,n);
	}
}
char str[30];
void Free(Node *A){
	if(A){
		for(int i=0;i<36;++i)  Free(A->next[i]);
		delete A;A=NULL;
	}
	else return;
}
int main(void)
{freopen("1414.txt","r",stdin); 
	T=new Node;
	char temp[5]="sun";
	Insert(T,temp);
	while(~scanf("%s",str)){
		if(str[0]=='+'){Insert(T,str+1);}
		else{
			printf("%s\n",str+1);
			st[0]=st[1]=' ';stn=2;
			Find(T,str+1);
		}
	}
	Free(T);
return 0;
}








