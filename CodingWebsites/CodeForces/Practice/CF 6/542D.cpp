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
int maxprime[maxn];//maxprime[i]:i����������� 
int prime[100000],N;//prime[i]����i������ 
int keyprime[maxn];//keyprime[i]:��i=1+p^k ��keyprime[i]=k ���� keyprime[i]=0 
int nextkeyprime[maxn];//��¼��һ����Ϊ���keyprime,�ӿ������� 
void Init(){//��ʼ�� 
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
int Sqrt(LL x){//��floor(sqrt(x)) 
	LL L=1,R=1000007;//[L,R)
	while(L+1 < R){
		LL M=(L+R)>>1;
		if(M*M <= x) L=M;
		else R=M;
	}
	return (int)L;
}
LL KeyPrime(LL x){//��x�Ƿ�Ϊĳ����p��ĳ�����η� ���ǵĻ�����������������򷵻�0 
	if(x+1 < maxn) return keyprime[x+1];//����С��xֱ������keyprime���� 
	int KeyP=0;int sqx=Sqrt(x);
	for(int i=0;i<N;++i){
		if(x%prime[i]==0) {
			KeyP=prime[i];
			break;
		}
		if(prime[i]>sqx) break;//��ʱ�˳� 
	}
	if(KeyP){
		while(x%KeyP==0) x/=KeyP;
		if(x==1) return KeyP;
		else return 0;
	}
	else return x;//��ʱx���Ǹ������� 
}

LL x;
int p[20],n;//��¼�Ѿ����еķֽ����õ������� 
bool exist(int k){//�ж�k�Ƿ����
	for(int i=0;i<n;++i) if(p[i]==k) return true;
	return false;
}
int ANS;
void F(LL x,LL v){//x:��ǰ���ֽ������v:��ǰ���������ֵ 
	int top=Sqrt(x);
	LL KP=KeyPrime(x-1);//�ж�x�Ƿ���Ա��ֽ��1+p^k 
	if(KP&&!exist(KP)) ++ANS;//����������û���ֹ�����+1 
	p[n++]=KP;
	//������С�����ӣ������ݹ� 
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



