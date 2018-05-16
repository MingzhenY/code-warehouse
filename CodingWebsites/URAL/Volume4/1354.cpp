#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x5fffffff
using namespace std;


int main(void)
{freopen("1354.txt","r",stdin); 
	string str;
	while(cin>>str){
		int n=str.length();
		if(n==1) {
			printf("%c%c\n",str[0],str[0]);
			continue;
		}
		int N=(n-1) <<1;
		for(int i=n;i<=N;i++){
			int l=i/2,r=(i+1)/2;
			while(str[l]==str[r]&&r<n) l--,r++;
			if(r==n){//Æ¥Åä³É¹¦ 
				for(int I=0;I<=i/2;I++){
					printf("%c",str[I]);
				}
				for(int I=(i-1)/2;I>=0;I--){
					printf("%c",str[I]);
				}
				cout<<endl;
				break;
			}
		}
	}
return 0;
}








