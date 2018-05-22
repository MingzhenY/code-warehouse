#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
using namespace std;
set<int> S;
int main(){
    freopen("P1170.txt","r",stdin);
    int v;
    while(~scanf("%d",&v)&&v) S.insert(v);
    for(set<int>::iterator it=S.begin();it!=S.end();++it){
        printf("%d ",*it);
    }
    printf("\n");
    return 0;
}




