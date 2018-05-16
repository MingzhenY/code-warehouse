#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <cstring>
#include <algorithm>
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 500007
#define LL long long
using namespace std;
int A[maxn];
int n,q; 
int main(void)
{
	freopen("551E.txt","r",stdin);
	ios::sync_with_stdio(false);
	while(cin>>n>>q){
		for(int i=1;i<=n;++i) cin>>A[i];
		for(int i=0;i<q;++i){
			int op,L,R,x,y;
			cin>>op;
			if(op==1){
				cin>>L>>R>>x;
				for(int i=L;i<=R;++i) A[i]+=x; 
			}
			else{
				cin>>y;
				int Li=-1,Ri=-1;
				for(int i=1;i<=n;++i){
					if(A[i]==y){
						if(!~Li) Li=i;
						Ri=i; 
					}
				}
				if(~Li) cout<<(Ri-Li)<<endl;
				else cout<<-1<<endl;
			}
		}
	}
return 0;
}

