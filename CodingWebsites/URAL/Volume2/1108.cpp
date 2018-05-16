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
#define LL long long
using namespace std;
LL gcd(LL a,LL b){while(b){LL t=a%b;a=b;b=t;}return a;}
struct F{
	LL up,down;
	F():up(1ll),down(1ll){}
	F(LL Up,LL Down){LL D=gcd(Up,Down);up=Up/D;down=Down/D;}
	F rev()const{return F(down,up);}
	LL div()const{return up/down;}
	F operator +(const F &B)const{return F(up*B.down+down*B.up,down*B.down);}
	F operator - (const F &B) const {return F(up*B.down-down*B.up,down*B.down);}
	F operator * (const F &B) const {return F(up*B.up,down*B.down);}
	F operator / (const F &B) const {return *this*(B.rev());}
	bool operator < (const F &B) const {return up * B.down < down * B.up;}
	bool operator == (const F &B) const {return up * B.down == down * B.up;}
	bool operator <= (const F &B) const {return up * B.down <= down * B.up;}
	void show(){printf("%d/%d ",up,down);}
	void showLn(){printf("%d/%d\n",up,down);}
};
int List[30],Ln;
bool H(F L,F R,int k){//存不存在k个分子为1的分数，使得它们的和在（L,R)(R<=1)这个范围(L要比较大)
	int l=max(List[Ln],(int)R.rev().div()),r=L.up>0?(int)(k*L.down/L.up):inf;
	if(l>=r) return false;
	if(k==1){
		if(l+1<r){
			List[++Ln]=l+1;
			//此处为输出答案的地方 
			for(int i=1;i<=Ln;++i) printf("%d\n",List[i]);
			
			--Ln;
			return true;
		}
		return false;
	}
	for(int i=l+1;i<=r;++i){
		List[++Ln]=i;
		//printf("Add %d\n",i);
		if(H(L-F(1,i),R-F(1,i),k-1)) return true;
		--Ln;
		//printf("Remove %d\n",i);
	}
	return false;
}
int N=0;
int main(void)
{freopen("1108.txt","r",stdin); 
	Ln=0;List[0]=1;
	while(cin>>N){
		
	}
return 0;
}








