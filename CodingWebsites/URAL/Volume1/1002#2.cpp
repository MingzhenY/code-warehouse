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
	char w[50];//存单词 
	char num[50];//存单词转化成数字后的版本 
	int n;//字符个数 
	bool operator <(const W &B)const{
		return n>B.n;
	} 
}word[50000];
int N;//单词个数 
int ALL;//电话的号码个数 
void trans();//将单词转换成数字 
void show(char *a);//显示字符串 

int dp[101];//表示以前i个字母可以组成的最少单词数量。
int path[101];//path[i]表示，前i个字母中，最后一个单词的开头。
int wo[101];//word[i]表示，前i个字母中，最后一个单词的编号 
void F(int i);
int main(void)
{freopen("1002.txt","r",stdin); 
	while(scanf("%s",a)==1){
		a[101]='\0';if(a[0]=='-') break;
		ALL=0;
		while(a[ALL]) ALL++;
		cin>>N;
		//输入单词 
		for(int i=0;i<N;i++){
			scanf("%s",word[i].w);
		}
		//翻译 
		trans();
		sort(word,word+N);
		/*
		printf("电话： "); 
		show(a);
		printf("\n单词：\n") ;
		for(int i=0;i<N;i++){
			printf("%d ",word[i].n);show(word[i].num);
			printf(":");show(word[i].w);cout<<endl;
		}
		*/
		
		//计算
		memset(dp,-1,sizeof(dp));
		dp[0]=0;
		for(int i=0;i<ALL;i++){//对每个位置 
			if(~dp[i]) //如果可以达到这一点 
			for(int j=0;j<N;j++){//则搜每个单词 
				if(i+word[j].n<=ALL){//如果长度合适 
					//判断是否可以放置这个词
					char temp[50];
					strncpy(temp,&a[i],word[j].n);
					temp[word[j].n]='\0';
					if(!strcmp(temp,word[j].num)) {//如果可以 
						if(~dp[i+word[j].n]) {//若已经有结尾位置一样的字串 
							if(dp[i]+1<dp[i+word[j].n]){//若字数少于它则更新 
								dp[i+word[j].n]=dp[i]+1,path[i+word[j].n]=i,wo[i+word[j].n]=j;
							}
						}
						else{//若没有，直接更新 
							dp[i+word[j].n]=dp[i]+1,path[i+word[j].n]=i,wo[i+word[j].n]=j;
						}
					} 
				}
			} 
		} 
		//输出
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







