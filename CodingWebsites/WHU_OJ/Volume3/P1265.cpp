#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
using namespace std;
set<int> S;
int A[500001],k;
int main(){
    freopen("P1265.txt","r",stdin);
    A[0]=0;
    S.insert(0);
    for(int i=1;i<=500000;++i){
        A[i]=A[i-1]-i;
        if(A[i]<0 || S.find(A[i])!=S.end()) A[i]=A[i-1]+i;
        S.insert(A[i]);
    }
    
    while(~scanf("%d",&k)&&~k)
        printf("%d\n",A[k]);
    
    return 0;
}


