#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define M 1000000007
using namespace std;
struct Color{
	long long a[3][3];
	Color(){
		memset(a,0,sizeof(a));
	}
	void reset(){
		a[0][1]=a[0][2]=a[1][0]=a[2][0]=1;
	}
	Color operator*(Color B){//求得*this和B 相邻的时候，的总答案。 
		Color C;
		for(int i1=0;i1<3;i1++){
			for(int i2=0;i2<3;i2++){
				for(int k1=0;k1<3;k1++){
					if(i2&&i2==k1) continue;
					for(int k2=0;k2<3;k2++){
						C.a[i1][k2]+=(a[i1][i2]*B.a[k1][k2])%M;
						C.a[i1][k2]%=M;
					}
				}
			}
		}
		return C;
	}
	void operator++(int){//求得外围加一层括号后的答案。 
		Color C;
		for(int i1=0;i1<3;i1++){
			for(int i2=0;i2<3;i2++){
				if(i2!=1) C.a[0][1]+=a[i1][i2];
				if(i2!=2) C.a[0][2]+=a[i1][i2];
				if(i1!=1) C.a[1][0]+=a[i1][i2];
				if(i1!=2) C.a[2][0]+=a[i1][i2];
			}
		}
		for(int i1=0;i1<3;i1++){
			for(int i2=0;i2<3;i2++){
				C.a[i1][i2]%=M;
			}
		}
		*this=C;
	}
	long long all(){//输出答案 
		long long ANS=0;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				ANS+=a[i][j];
			}
		}
		ANS%=M;
		return ANS;
	}
};
void match(string &a,int *vis,int n){//给括号配对 
	for(int i=0;i<n;i++) vis[i]=-1;
	for(int i=0;i<n;i++){
		if(a[i]==')'){
			for(int j=i-1;j>=0;j--){
				if(a[j]=='('&&!~vis[j]) {
					vis[j]=i;vis[i]=j;
					break;
				}
			}
		}
	}
}
Color F(string a);
Color f(string a);
int main(void)
{
	freopen("149D.txt","r",stdin); 
	string a;
	while(cin>>a){
		Color ANS=F(a);
		long long AANS=ANS.all();
		cout<<AANS<<endl;	
	}
return 0;
}
Color F(string a){//去掉最外围成对的括号，然后调用 f(); 
	int n=a.length();
	int level=0;//记录最外围有多少对成对的括号。 
	int *vis=new int[n];
	match(a,vis,n);
	for(;level<n/2;) if(vis[level]==n-1-level) level++;else break;
	delete []vis;
	Color ANS;
	if(level*2==n){//如果只有最外围括号 
		ANS.reset();
		for(int i=1;i<level;i++) ANS++;
		
		return ANS;
	}
	//不只有最外围括号，调用f() 
	string b;
	b.assign(a,level,n-2*level);
	ANS=f(b);//得到内部的答案 
	for(int i=0;i<level;i++) ANS++;//往内部的答案上，加外围括号。 
	return ANS;
}
Color f(string a){//此时已经没有最外围的括号，讲a分解成若干个部分的乘积，对每个部分调用 F(). 
	int n=a.length();
	int *vis=new int[n];
	match(a,vis,n);
	int L=0;Color ANS;
	while(L <n){//分解成每一小段，调用F() 
		string b;
		b.assign(a,L,vis[L]-L+1);
		Color D=F(b);
		if(L) ANS=ANS*D;//将各个小段的结果相乘。 
		else ANS=D;
		L=vis[L]+1;
	}
	delete []vis;
	return ANS;
}













