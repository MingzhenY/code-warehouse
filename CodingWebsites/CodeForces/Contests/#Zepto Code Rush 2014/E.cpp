#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define  inf  0x5fffffff
#define FOR(i,n) for(long long (i)=1;(i)<=(n);(i)++)
#define For(i,n) for(long long (i)=0;(i)<(n);(i)++)
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl

using namespace std;

int n,w; 

struct D{
	int v,i;
	bool operator<(const D &E)const{
		return v<E.v;
	}
}A[300000],B[300000],C[300000];
char state[300000];
//A第一颗星，B第二颗 
long long ANS=0;
int main(void)
{
	freopen("E.txt","r",stdin); 
	while(cin>>n>>w){
		for(int i=0;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);A[i].i=B[i].i=C[i].i=i;
			A[i].v=2*a;B[i].v=b;state[i]=48;
			C[i].v=b-a;
		}
		int Now=0;
		sort(A,A+n);sort(B,B+n);sort(C,C+n);
		int PA=0,PB=0;int LEFT=n;
		while(Now<w&&n){
			while(state[A[PA].i]!=48) PA++;
			while(state[B[PB].i]!=48) PB++;
			if(A[PA].v<B[PB].v){
				state[A[PA].i]++;LEFT--;
				PA++;ANS+=A[PA].v/2;
				Now+=1;
			}
			else{
				state[B[PB].i]+=2;LEFT--;
				PB++;ANS+=B[PB].v;
				Now+=2;
			}
		}
		int PC=0;
		while(Now<w){
			while(state[C[PC].i]!=49) PC++;
			state[C[PC].i]=50;ANS+=C[PC].v;
			Now++;
		}
		cout<<ANS<<endl;
		for(int i=0;i<n;i++){
			printf("%c",state[i]);
		}
		cout<<endl;
		
		
		
		
		
		
		
		
		
		
	}
return 0;
}














