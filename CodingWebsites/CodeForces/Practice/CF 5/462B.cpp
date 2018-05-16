#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int n,k;
char a;
int cnt[26];
int main(void)
{
	freopen("462B.txt","r",stdin); 
	while(~scanf("%d%d",&n,&k)){
		for(int i=0;i<26;i++) cnt[i]=0;
		scanf("%*c");
		for(int i=0;i<n;i++) {
			scanf("%c",&a);
			cnt[a-'A']++;
		}
		long long ANS=0LL;
		sort(cnt,cnt+26);
		for(int i=25;i>=0&&k>0;i--){
			int d=k>cnt[i]?cnt[i]:k;
			k-=d;ANS+=(long long)d*d;	
		}
		printf("%I64d\n",ANS);
	}
return 0;
}














