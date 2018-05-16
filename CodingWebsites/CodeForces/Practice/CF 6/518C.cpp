#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n,m,k;
int a[100007],b[100007],q[100007];
void Swap(int &a,int &b){a=a^b;b=a^b;a=a^b;}
int main(void)
{
	freopen("518C.txt","r",stdin); 
	while(~scanf("%d%d%d",&n,&m,&k)){
		for(int i=0;i<n;++i) {
			scanf("%d",&q[i]);q[i]--;
			a[q[i]]=i;
		}
		for(int i=0;i<m;++i) scanf("%d",&b[i]),b[i]--;
		long long ANS=0;
		for(int i=0;i<m;++i){
			int ID=a[b[i]];
			ANS+=1+ID/k;
			if(ID) {
				a[q[ID]]--;
				a[q[ID-1]]++;
				Swap(q[ID],q[ID-1]);
			}
		}
		cout<<ANS<<endl;
	}

		
return 0;
}














