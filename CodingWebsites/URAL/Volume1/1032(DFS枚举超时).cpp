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

struct Number{
	int a;//数
	int rest;//余数
	bool In;//是否选用
	bool operator <(const Number &B)const{
		return rest<B.rest;
	} 
}a[10000];

int N;
int Flag; int ALL=0;
void DFS(int i,int sum);
int main(void)
{freopen("1032.txt","r",stdin); 
	while(cin>>N){		
		//输入 + 初始化
		for(int i=0;i<N;i++){
			scanf("%d",&a[i].a);
			a[i].rest=a[i].a%N;
			a[i].In=0;
		} 
		//OUT1(N);
		Flag=0;ALL=0;
		if(N==1){
			Flag=1;a[0].In=1;ALL=1; 
		}
		else DFS(0,0);
		if(!Flag) ALL=0;
		printf("%d\n",ALL);
		if(Flag)
		for(int i=0;i<N;i++){
			if(a[i].In) printf("%d\n",a[i].a);
		}
	}
return 0;
}
void DFS(int i,int sum){
	if(ALL>0&&(sum%N==0)) {//如果条件适合，结束程序
		Flag=1;return;
	}
	if(i==N) return;
	
	if(a[i].rest){//如果余数不为零，使用这个数
		a[i].In=1;ALL++;
		DFS(i+1,sum+a[i].a);
		if(Flag) return;
		a[i].In=0;ALL--;
	} 
	//不使用这个数。
	DFS(i+1,sum); 
	if(Flag) return;
}







