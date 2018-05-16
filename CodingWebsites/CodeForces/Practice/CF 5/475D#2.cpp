#include <cstdio>
#include <map>
using namespace std;
int n,q,x;
int a[100000];
int gcd(int a,int b){while(b){int t=a%b;a=b;b=t;} return a;}
int main(void)
{
	freopen("475D.txt","r",stdin); 
	while(~scanf("%d",&n)){
		for(int i=0;i<n;++i) scanf("%d",&a[i]);
		map<int,long long> result;
		map <int,int>D;
		map <int,int>nextD;
		for(int i=0;i<n;++i){
			nextD.clear();
			map<int,int>::iterator it;
			for(it=D.begin();it!=D.end();++it){
				nextD[gcd(it->first,a[i])]+=it->second;
			}
			nextD[a[i]]++;
			swap(D,nextD);
			for(it=D.begin();it!=D.end();++it){
				result[it->first]+=it->second;
			}
		}
		scanf("%d",&q);
		for(int j=0;j<q;++j){
			scanf("%d",&x);
			printf("%I64d\n",result[x]);
		}
	}
return 0;
}














