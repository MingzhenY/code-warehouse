#include <iostream>
#include <cstdio>
#include <cmath>
#define maxn 500001
using namespace std;
int vowel(char ch){
	switch(ch){
		case 'A':case 'I':case 'E':case 'O':case 'U':case 'Y': return 1;
		default:return 0;
	}
}
int n;
int S[maxn];
long long f[maxn];
int main(void)
{
	freopen("509E.txt","r",stdin); 
	string s;
	while(cin>>s){
		n=s.length();
		S[0]=0;
		for(int i=1;i<=n;++i) S[i]=S[i-1]+vowel(s[i-1]);
		f[0]=0;
		for(int i=1;i<=((n+1)>>1);++i)		f[i]=f[i-1]+S[n-i+1]-S[i-1];
		for(int i=((n+1)>>1)+1;i<=n;++i)	f[i]=f[n-i+1];
		double ANS=0;
		for(int k=1;k<=n;++k){
			ANS+=(double) f[k]/k;
		}
		printf("%.7f\n",ANS);
	}
return 0;
}














