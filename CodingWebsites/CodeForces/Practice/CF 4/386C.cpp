#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define maxn 300007
using namespace std;
struct Mark{
	int cnt[26];
	int m;
	Mark(){memset(cnt,0,sizeof(cnt));m=0;}
};
string str;
int n;
long long d[27];
int getK(Mark m){
	int ANS=0;
	for(int i=0;i<26;++i) ANS+=(m.cnt[i]>0);
	return ANS;
}
void T(int k){//求 T(k) 
	int R1=1,R2=1;//[L,[R1..R2)]为以L开始的区间 
	Mark M1,M2;//区间[L,R1]和 [L,R2] 的状态 
	M1.cnt[str[0]-'a']++;M1.m=1;M2=M1;
	for(int L=1;L <=n;++L){//枚举左端点 
		//更新 M1,M2 使之对于新的 L 成立 
		if(L>1){ 
			M1.cnt[str[L-2]-'a']--;if(!M1.cnt[str[L-2]-'a']) M1.m--;
			M2.cnt[str[L-2]-'a']--;if(!M2.cnt[str[L-2]-'a']) M2.m--;
		}
		//计算新的R1,R2 
		while(M1.m < k&&R1 < n){if(!M1.cnt[str[R1]-'a']) M1.m++;M1.cnt[str[R1++]-'a']++;}
		while(M2.m <=k&&R2 <=n){if(!M2.cnt[str[R2]-'a']) M2.m++;M2.cnt[str[R2++]-'a']++;}
		//累加计算结果 
		d[k]+=R2-R1-(M1.m <k);//printf("d[%d]+=%d (L=%d  R1=%d R2=%d)\n",k,R2-R1,L,R1,R2);
	}
}
int main(void)
{
	freopen("386C.txt","r",stdin);
	while(cin>>str){
		Mark M; 
		n=str.length();
		for(int i=0;i<n;++i) M.cnt[str[i]-'a']++;
		memset(d,0,sizeof(d));
		int D=getK(M);
		for(int i=1;i<=D;++i){T(i);}
		printf("%d\n",D);
		for(int i=1;i<=D;++i){
			cout<<d[i]<<endl;
		}
	}
return 0;
}

