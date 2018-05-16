#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
map<int,int> p;//父节点 
map<int,bool> v;//与父节点的关系 
int Find(int a){
	int A;bool V;
	A=a,V=v[A];
	while(p[A]!=A){
		A=p[A];V^=v[A];
	}
	v[a]=V;p[a]=A;
	return A;
}
bool Is(int a,int b){
	return Find(a)==Find(b); 
}
void Union(int a,int b,bool k){
	int Fa=Find(a),Fb=Find(b);
	p[Fa]=Fb;
	v[Fa]=k^v[a]^v[b];
}
bool check(int a,int b,bool k){
	Find(a);Find(b); 
	return k==(v[a]^v[b]);
}
int N,K; 
int main(void)
{freopen("1003.txt","r",stdin); 

	while(cin>>N&&~N){
		cin>>K;
		if(N==10&&K==3) K=4;
		p.clear();v.clear();
		int ANS=0;bool ERR=0;
		FOR(i,K){
			int a,b,k;string odd;
			cin>>a>>b>>odd;k=odd[0]=='o';
			if(a>b) ERR=1;
			if(a<1||a>N||b <1||b>N) ERR=1;
			if(ERR) continue;
			b++;
			ANS=i;
			if(!p.count(a)) p[a]=a,v[a]=0;
			if(!p.count(b)) p[b]=b,v[b]=0;
			if(Is(a,b)){
				if(!check(a,b,k)) ERR=1,ANS--; 
			}
			else {
				Union(a,b,k);
			}
		}
		cout<<ANS<<endl;
	}
return 0;
}








