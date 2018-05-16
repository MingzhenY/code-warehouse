/*
	There always exists a number that has the same digits as the input and is a palindrome because
	the biggest number of any length --all 9-- is a palindrome
*/ 

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

string str;
void Add(int k){
	str[k]++;
	while(k>0&&str[k]>9) str[k]=0,str[k-1]++,k--;
}
void F(){
	int n=str.length();
	for(int i=0;i<n;++i) str[i]-='0';
	for(int i=0;i<=(n-1)/2;++i){
		int L=i,R=n-1-i;
		if(str[L]<str[R]) Add(R-1);
		str[R]=str[L];
	}
	for(int i=0;i<n;++i) str[i]+='0';
}

int main(void)
{freopen("1123.txt","r",stdin); 
	ios::sync_with_stdio(false);
	while(cin>>str){
		F();
		cout<<str<<endl;
	}
return 0;
}








