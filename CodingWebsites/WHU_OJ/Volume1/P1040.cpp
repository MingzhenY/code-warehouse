#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;


int main(){
    freopen("P1040.txt","r",stdin);
    int t,n,a;
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        scanf("%d",&n);
        map<int,int> M;
        for(int i=0;i<n;++i){
            scanf("%d",&a);
            M[a]++;
        }
        int Max=0;
        for(map<int,int>::iterator it=M.begin();it!=M.end();++it){
            Max=max(Max,it->second);
        }
        printf("%d\n",Max);
    }
    return 0;
}


