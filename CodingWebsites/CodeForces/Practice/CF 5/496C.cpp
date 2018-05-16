#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

char s[100][101];
int n,m;

struct K{
	int x;//本状态的列数 
	int same[100];//行最大相同数
	K(){Clear();}
	void Clear(){x=0;memset(same,0,sizeof(same));} //清空状态 
	K operator +(int k){//本状态加上第k列之后生成的新状态，x=-1表示无法生成 
		K C=*this;
		for(int i=0;i<n-1;++i){
			if(same[i]==x){
				if(s[i+1][k]>=s[i][k]){
					C.same[i]=same[i]+(s[i+1][k]==s[i][k]);
				}
				else{
					C.x=-1;return C;
				}
			}
		}
		C.x++;
		return C;
	}
};

struct ArcNode{
	K state;
	ArcNode *next;
};
void ADD(ArcNode *&L,K state){
	ArcNode *temp=new ArcNode;
	temp->state=state;
	temp->next=L;
	L=temp;
}
int main(void)
{
	freopen("496C.txt","r",stdin); 
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;++i) scanf("%s",s[i]);
		if(n==1){printf("0\n");continue;}
		ArcNode *List=new ArcNode;List->next=NULL;
		int Max=0;
		for(int k=0;k<m;++k){
			ArcNode *NList=NULL;
			while(List){
				K state=List->state+k;
				if(~state.x&&state.x+m-k-1>Max) {
					ADD(NList,state);
					if(state.x>Max) Max=state.x;
				}
				ArcNode *temp=List;
				List=List->next;
				temp->next=NList;
				NList=temp;
			}
			List=NList;
		}
	
		printf("%d\n",m-Max);
	}
return 0;
}














