#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <list>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

#define K2(a,b,t) case a:case b:temp=t;break;
#define K3(a,b,c,num) case a:case b:case c:temp=num;break;

using namespace std;

char a[101];
struct W{
	char w[50];//�浥�� 
	char num[50];//�浥��ת�������ֺ�İ汾 
	int n;//�ַ����� 
	bool operator <(const W &B)const{
		return n>B.n;
	} 
}word[50000];
int N;//���ʸ��� 
int ALL;//�绰�ĺ������ 
void trans();//������ת�������� 
void show(char *a);//��ʾ�ַ��� 

int dp[101];//��ʾ��ǰi����ĸ������ɵ����ٵ���������
int path[101];//path[i]��ʾ��ǰi����ĸ�У����һ�����ʵĿ�ͷ��
int wo[101];//word[i]��ʾ��ǰi����ĸ�У����һ�����ʵı�� 
void F(int i);
int main(void)
{freopen("1002.txt","r",stdin); 
	while(scanf("%s",a)==1){
		a[101]='\0';if(a[0]=='-') break;
		ALL=0;
		while(a[ALL]) ALL++;
		cin>>N;
		//���뵥�� 
		for(int i=0;i<N;i++){
			scanf("%s",word[i].w);
		}
		//���� 
		trans();
		sort(word,word+N);
		/*
		printf("�绰�� "); 
		show(a);
		printf("\n���ʣ�\n") ;
		for(int i=0;i<N;i++){
			printf("%d ",word[i].n);show(word[i].num);
			printf(":");show(word[i].w);cout<<endl;
		}
		*/
		
		//����
		memset(dp,-1,sizeof(dp));
		dp[0]=0;
		for(int i=0;i<ALL;i++){//��ÿ��λ�� 
			if(~dp[i]) //������Դﵽ��һ�� 
			for(int j=0;j<N;j++){//����ÿ������ 
				if(i+word[j].n<=ALL){//������Ⱥ��� 
					//�ж��Ƿ���Է��������
					char temp[50];
					strncpy(temp,&a[i],word[j].n);
					temp[word[j].n]='\0';
					if(!strcmp(temp,word[j].num)) {//������� 
						if(~dp[i+word[j].n]) {//���Ѿ��н�βλ��һ�����ִ� 
							if(dp[i]+1<dp[i+word[j].n]){//����������������� 
								dp[i+word[j].n]=dp[i]+1,path[i+word[j].n]=i,wo[i+word[j].n]=j;
							}
						}
						else{//��û�У�ֱ�Ӹ��� 
							dp[i+word[j].n]=dp[i]+1,path[i+word[j].n]=i,wo[i+word[j].n]=j;
						}
					} 
				}
			} 
		} 
		//���
		//OUT1(dp[ALL]);
		if(~dp[ALL]) F(ALL);
		else printf("No solution.\n"); 
	}
return 0;
}
void F(int i){
	if(path[i]) F(path[i]);
	show(word[wo[i]].w);
	if(i==ALL) printf("\n");
	else printf(" ");
}
void show(char *a){
	while(*a){
		printf("%c",*a++);
	}
}
void trans(){
	for(int i=0;i<N;i++){
		int t=0;
		while(word[i].w[t]){
			char &temp=word[i].num[t];
			switch(word[i].w[t]){
				K2('i','j','1');
				K3('a','b','c','2');
				K3('d','e','f','3');
				K2('g','h','4');
				K2('k','l','5');
				K2('m','n','6');
				K3('p','r','s','7');
				K3('t','u','v','8');
				K3('w','x','y','9');
				K3('o','q','z','0');
			}
			t++;
		}
		word[i].n=t;
		word[i].num[word[i].n]='\0';
	} 
} 







