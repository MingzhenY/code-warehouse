#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 1000007 
#define LL long long
using namespace std;
int maxprime[maxn];//maxprime[i]:i的最大质因数 
int prime[100000],N;//prime[i]：第i个质数 
int keyprime[maxn];//keyprime[i]:若i=1+p^k 则keyprime[i]=k 否则 keyprime[i]=0 
int nextkeyprime[maxn];//记录下一个不为零的keyprime,加快计算过程 
void Init(){//初始化 
	memset(maxprime,0,sizeof(maxprime));
	memset(keyprime,0,sizeof(keyprime));
	keyprime[1]=1;
	N=0;
	for(int i=2;i<maxn;++i){
		if(maxprime[i]) continue;
		prime[N++]=i;
		for(int j=i;j<maxn;j+=i) maxprime[j]=i;
		for(LL j=1;j<=(maxn-2)/i;){
			j*=i;
			keyprime[j+1]=i;
		}
	}
	nextkeyprime[maxn-1]=maxn-1;
	for(int i=maxn-1;i>0;--i){
		if(keyprime[i]) nextkeyprime[i-1]=i;
		else nextkeyprime[i-1]=nextkeyprime[i];
	}
}
int Sqrt(LL x){//求floor(sqrt(x)) 
	LL L=1,R=1000007;//[L,R)
	while(L+1 < R){
		LL M=(L+R)>>1;
		if(M*M <= x) L=M;
		else R=M;
	}
	return (int)L;
}
LL KeyPrime(LL x){//求x是否为某质数p的某个正次方 ，是的话返回这个质数，否则返回0 
	if(x+1 < maxn) return keyprime[x+1];//对于小的x直接利用keyprime数组 
	int KeyP=0;int sqx=Sqrt(x);
	for(int i=0;i<N;++i){
		if(x%prime[i]==0) {
			KeyP=prime[i];
			break;
		}
		if(prime[i]>sqx) break;//及时退出 
	}
	if(KeyP){
		while(x%KeyP==0) x/=KeyP;
		if(x==1) return KeyP;
		else return 0;
	}
	else return x;//此时x就是个大质数 
}

LL x;
int p[20],n;//记录已经进行的分解中用到的质数 
bool exist(int k){//判断k是否存在
	for(int i=0;i<n;++i) if(p[i]==k) return true;
	return false;
}
int ANS;
void F(LL x,LL v){//x:当前待分解的数，v:当前因数的最大值 
	int top=Sqrt(x);
	LL KP=KeyPrime(x-1);//判断x是否可以被分解成1+p^k 
	if(KP&&!exist(KP)) ++ANS;//如果这个因子没出现过，答案+1 
	p[n++]=KP;
	//除掉最小的因子，继续递归 
	for(int i=nextkeyprime[v];i<=top;i=nextkeyprime[i]){
		//OUT2(i,top);
		if(x%i==0&&!exist(keyprime[i])){
			p[n++]=keyprime[i];
			F(x/i,i);
			--n;
		}
	}
	--n;
}
int main(void)
{
	Init();
	freopen("542D.txt","r",stdin); 
	while(cin>>x){
		int sqx=Sqrt(x);
		n=0;ANS=0;
		F(x,2);
		cout<<ANS <<endl;
	}
return 0;
}



