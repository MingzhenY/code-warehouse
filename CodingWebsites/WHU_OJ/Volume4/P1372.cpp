#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int A[100001],n,m;
int main(){
    freopen("P1372.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)&&(n||m)){
        for(int i=0;i<n;++i) scanf("%d",&A[i]);
        sort(A,A+n);
        vector<int> V;
        for(int i=0;i<n;i+=m) V.push_back(A[i]);
        for(int i=0;i<V.size();++i){
            printf("%d",V[i]);
            if(i+1==V.size()) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}


