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
	Color operator*(Color B){//���*this��B ���ڵ�ʱ�򣬵��ܴ𰸡� 
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
	void operator++(int){//�����Χ��һ�����ź�Ĵ𰸡� 
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
	long long all(){//����� 
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
void match(string &a,int *vis,int n){//��������� 
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
Color F(string a){//ȥ������Χ�ɶԵ����ţ�Ȼ����� f(); 
	int n=a.length();
	int level=0;//��¼����Χ�ж��ٶԳɶԵ����š� 
	int *vis=new int[n];
	match(a,vis,n);
	for(;level<n/2;) if(vis[level]==n-1-level) level++;else break;
	delete []vis;
	Color ANS;
	if(level*2==n){//���ֻ������Χ���� 
		ANS.reset();
		for(int i=1;i<level;i++) ANS++;
		
		return ANS;
	}
	//��ֻ������Χ���ţ�����f() 
	string b;
	b.assign(a,level,n-2*level);
	ANS=f(b);//�õ��ڲ��Ĵ� 
	for(int i=0;i<level;i++) ANS++;//���ڲ��Ĵ��ϣ�����Χ���š� 
	return ANS;
}
Color f(string a){//��ʱ�Ѿ�û������Χ�����ţ���a�ֽ�����ɸ����ֵĳ˻�����ÿ�����ֵ��� F(). 
	int n=a.length();
	int *vis=new int[n];
	match(a,vis,n);
	int L=0;Color ANS;
	while(L <n){//�ֽ��ÿһС�Σ�����F() 
		string b;
		b.assign(a,L,vis[L]-L+1);
		Color D=F(b);
		if(L) ANS=ANS*D;//������С�εĽ����ˡ� 
		else ANS=D;
		L=vis[L]+1;
	}
	delete []vis;
	return ANS;
}













