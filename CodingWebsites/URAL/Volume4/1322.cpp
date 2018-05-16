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
char a[200010];
struct A{
	char ch;
	int next;
	bool operator<(const A &B)const{
		return  ch <B.ch||ch==B.ch&&next<B.next;
	}
}node[100010];
int Cur;
struct B{
	int sta;
	bool operator<(const B &B)const{
		//printf("\t");OUT3(Cur,(int)a[sta+Cur],(int)a[B.sta+Cur]);
		if(a[sta+Cur]<a[B.sta+Cur]) return 1;
		return 0;
	}
	void show(){
		for(int i=0;i<n;i++){
			printf("%c",a[sta+i]);
		}
		cout<<endl;
	}
}k[100010]; 
int main(void)
{freopen("1322.txt","r",stdin); 
	while(cin>>N){
		scanf("%s",str);
		n=0;while(str[n]) n++;
		For(i,n) node[i].ch=str[i],node[i].next=i;
		sort(node,node+n);
		int x=node[0].next;
		for(int i=0;i<n;i++){
			x=node[x].next;
			a[i+n]=a[i]=str[x];
		}
		For(i,n){
			k[i].sta=i;
		}
		k[0].show();
		int L=0,R=n-1;
		for(Cur=0;Cur<n;Cur++){
			sort(k+L,k+R+1);
			//For(i,n) k[i].show(); 
			//OUT1(Cur);
			int NL=N-1,NR=N-1;
			while(NL >L &&a[k[NL-1].sta+Cur]==a[k[NL].sta+Cur]) NL--;
			while(NR <R &&a[k[NR+1].sta+Cur]==a[k[NR].sta+Cur]) NR++;
			L=NL;R=NR;
			if(L==R) break;
			//OUT2(L,R+1);
		}
		//k[N-1].show();
		//For(i,n) k[i].show(); 
	}
return 0;
}








