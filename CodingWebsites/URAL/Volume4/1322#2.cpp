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

int N,n;
char str[100010];
struct A{
	char ch;
	int next;
	bool operator<(const A &B)const{
		return  ch <B.ch||ch==B.ch&&next<B.next;
	}
}node[100010];
int Cur;

int main(void)
{freopen("1322.txt","r",stdin); 
	while(cin>>N){
		scanf("%s",str);
		n=0;while(str[n]) n++;
		For(i,n) node[i].ch=str[i],node[i].next=i;
		sort(node,node+n);
		int x=N-1;
		for(int i=0;i<n;i++){
			x=node[x].next;
			printf("%c",str[x]);
		}
		cout<<endl;
	}
return 0;
}








