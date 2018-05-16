#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
using namespace std;
string name[100];int n;
int N;
int main(void)
{freopen("1496.txt","r",stdin); 
	while(cin>>N){
		map <string,int> MP;n=0;
		for(int i=0;i<N;++i){
			string a;cin>>a;
			if(MP.count(a)) MP[a]++;
			else MP[a]=1,name[n++]=a;
		}
		//sort(name,name+n);
		for(int i=0;i<n;i++){
			if(MP[name[i]]>1) cout<<name[i]<<endl;
		}
	}
	
	
	
	
return 0;
}








