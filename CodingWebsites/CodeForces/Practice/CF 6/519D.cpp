#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
int v[26],n;
char str[100007];
long long S[100007];
map<long long,long long> MAP[26];
int main(void)
{
	freopen("519D.txt","r",stdin); 
	while(~scanf("%d",&v[0])){
		for(int i=1;i<26;++i) scanf("%d",&v[i]);
		scanf("%s",str);n=strlen(str);
		for(int i=0;i<n;++i) str[i]-='a';
		S[0]=v[str[0]];
		for(int i=1;i<n;++i) S[i]=S[i-1]+v[str[i]];
		for(int i=0;i<26;++i) MAP[i].clear();
		long long ANS=0;
		for(int i=0;i<n;++i){
			ANS+=MAP[str[i]][S[i]-v[str[i]]];
			MAP[str[i]][S[i]]++;
		}
		cout<<ANS<<endl;
	}
return 0;
}














