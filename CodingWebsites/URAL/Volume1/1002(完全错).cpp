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
	char w[50];
	char num[50];
	int n;//×Ö·û¸öÊý 
	bool operator <(const W &B)const{
		return n>B.n;
	} 
}word[50000];
int N;int Cur;int ALL;
void trans();
void show(char *a);
bool solve();
struct A{
	char a[50];
	A(){}
	A(int i){
		strcpy(a,word[i].w);
	}
}; 
list <A> List;
int main(void)
{freopen("1002.txt","r",stdin); 
	while(scanf("%s",a)==1){
		a[101]='\0';if(a[0]=='-') break;
		ALL=0;
		while(a[ALL]) ALL++;
		//OUT1(ALL);
		cin>>N;
		//OUT1(N);
		for(int i=0;i<N;i++){
			scanf("%s",word[i].w);
		}
		//·­Òë 
		trans();
		for(int i=0;i<N;i++){
			printf("%d ",word[i].n);show(word[i].num);cout<<endl;
		}
		sort(word,word+N);
		
		
		Cur=0;
		while(solve());
		int T=0;
		if(Cur==ALL) {
			while(!List.empty()){
			A temp;
			temp=List.front();List.pop_front();
			if(T) printf(" ");
			else T=1;
			show(temp.a);
			}
			printf("\n");
		}
		else{
			printf("No solution.\n");
		}
		
	}
return 0;
}
bool solve(){
	if(Cur==ALL) return 0;
	for(int i=0;i<N;i++){
		if(Cur+word[i].n<=ALL){
			char temp[50];
			strncpy(temp,&a[Cur],word[i].n);
			temp[word[i].n]='\0';
			printf("temp=");show(temp);printf("  ");show(word[i].num); printf("\n");
			if(!strcmp(temp,word[i].num)) {
				List.push_back(A(i)); 
				Cur+=word[i].n;
				return 1;
			}
		}
	}
	return 0;
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







