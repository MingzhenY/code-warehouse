/*
	1231 ms	207000 KB
	
	��D[i]=0^A[1]^A[2]^...^A[i]
	����ת��Ϊ���ٸ�0<=i < j <=n �� D[i]^D[j] >= k 
	ö��j,��D[0..j-1]��֯��trie����������Ѱ�����D[j]�Ժ�>=k��Ԫ�ظ�����
	
	������ģ�����νṹ��д�˸�01��trie����
	һ�����������һ����ѯ������
*/ 
#include <iostream>
#include <cstdio>
#include <cmath>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 1000007
#define LL long long
using namespace std;
int n,k;
int A[maxn],D[maxn],H[31];
int L[1<<24],R[1<<24],S[1<<24],P,T;
void Init(){
	L[0]=R[0]=S[0]=P=T=0;
}
void Insert(int &rt,int depth,int value){
	if(!rt){
		rt=++P;
		L[rt]=R[rt]=S[rt]=0;
	}
	++S[rt]; 
	if(depth==30) return;
	if(value&H[depth]) Insert(R[rt],depth+1,value);
	else Insert(L[rt],depth+1,value);
}
LL Query(int &rt,int depth,int value){
	if(!rt) return 0;
	if(depth==30) return S[rt];
	if(value&H[depth]){//��1��0 
		if(k&H[depth]) return Query(L[rt],depth+1,value);
		else return S[L[rt]]+Query(R[rt],depth+1,value);
	}
	else{//��0��1 
		if(k&H[depth]) return Query(R[rt],depth+1,value);
		else return S[R[rt]]+Query(L[rt],depth+1,value);
	}
}
int main(void)
{
	H[29]=1;
	for(int i=28;i>=0;--i) H[i]=H[i+1]<<1;
	freopen("665E.txt","r",stdin); 
	while(~scanf("%d%d",&n,&k)){
		for(int i=1;i<=n;++i) scanf("%d",&A[i]);
		for(int i=1;i<=n;++i) D[i]=D[i-1]^A[i];
		Init();
		LL ANS=0;
		for(int i=1;i<=n;++i){
			Insert(T,0,D[i-1]);
			ANS+=Query(T,0,D[i]);
		}
		printf("%I64d\n",ANS);
	}
return 0;
}

