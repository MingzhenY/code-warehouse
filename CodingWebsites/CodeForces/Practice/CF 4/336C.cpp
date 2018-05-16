#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int n;
vector <int> V[31];
int F(vector<int> &X){
	if(X.size()==0) return 0;
	 int ANS=X[0];
	 for(int i=1;i<X.size();++i){
	 	ANS&=X[i];
	 }
	return ANS;	 
}
int p[31];
int main(void)
{
	freopen("336C.txt","r",stdin); 
	p[0]=1;
	for(int i=1;i<31;++i) p[i]=p[i-1]<<1;
	while(cin>>n){
		for(int i=0;i<31;++i) V[i].clear();
		for(int i=0;i<n;++i){
			int a;scanf("%d",&a);
			int t=a;
			for(int i=0;i<31;++i,t>>=1) {
				if(t&1) V[i].push_back(a); 
			}
		}
		int R=-1;
		for(int i=0;i<31;++i){
			//printf("%d,%d\n",i,F(V[i]));
			if(F(V[i])%p[i]==0 && V[i].size()>0) R=i;
		}
		if(R>=0){
			printf("%d\n",V[R].size());
			for(int i=0;i<V[R].size();++i){
				printf("%d",V[R][i]);
				if(i+1==V[R].size()) printf("\n");
				else printf(" ");
			}	
		}
		else{
			printf("-1\n");
		}
	}
return 0;
}














