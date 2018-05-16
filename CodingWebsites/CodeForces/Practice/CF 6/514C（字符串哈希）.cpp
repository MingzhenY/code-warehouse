#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define K1 397
#define K2 1867
#define M1 1000000007
#define M2  800000983
using namespace std;
int n,m;
long long k1[600007];
long long k2[600007];
char s[600007];
struct A{
	long long Key1,Key2;
	int len;
	A(){len=Key1=Key2=0;}
	A modify(int k,int j){
		A X=*this;
		X.Key1=(X.Key1+(k+M1)*k1[j])%M1;
		X.Key2=(X.Key2+(k+M2)*k2[j])%M2;
		return X;
	}
	bool operator ==(const A &B)const{
		return len==B.len&&Key1==B.Key1&&Key2==B.Key2; 
	}
	bool operator <(const A &B)const{
		if(len!=B.len) return len<B.len;
		if(Key1!=B.Key1) return Key1<B.Key1;
		if(Key2!=B.Key2) return Key2<B.Key2;
		return false; 
	}
	bool operator <=(const A &B)const{
		if(len!=B.len) return len<B.len;
		if(Key1!=B.Key1) return Key1<B.Key1;
		if(Key2!=B.Key2) return Key2<B.Key2;
		return true; 
	}
};
A a[300007];
bool Search(A x){
	int L=0,R=n,M;
	while(L+1<R){
		M=(L+R)>>1;
		if(a[M]<=x) L=M;
		else R=M;
	}
	return a[L]==x;
}
int main(void)
{
	freopen("514C.txt","r",stdin);
	k2[0]=k1[0]=1; 
	for(int i=1;i<600007;i++) k1[i]=(K1*k1[i-1])%M1,k2[i]=(K2*k2[i-1])%M2;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;++i){
			scanf("%s",s);
			int j=0;A x;
			while(s[j]){x.Key1=(x.Key1+s[j]*k1[j])%M1;x.Key2=(x.Key2+s[j]*k2[j])%M2;++j;}
			x.len=j;
			a[i]=x;
		}
		sort(a,a+n);
		for(int i=0;i<m;++i){
			scanf("%s",s);
			int j=0;A x;
			while(s[j]){x.Key1=(x.Key1+s[j]*k1[j])%M1;x.Key2=(x.Key2+s[j]*k2[j])%M2;++j;}
			x.len=j;
			bool T=0;
			for(int t=0;t<j;++t){
				switch(s[t]){
					case 'a':T=T||Search(x.modify(1,t))||Search(x.modify(2,t));break;
					case 'b':T=T||Search(x.modify(1,t))||Search(x.modify(-1,t));break;
					case 'c':T=T||Search(x.modify(-1,t))||Search(x.modify(-2,t));break;
				}
				if(T) break;
			}
			if(T)printf("YES\n");
			else printf("NO\n");
		}
	}

		
return 0;
}














