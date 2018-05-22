#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
using namespace std;

int N,a,b;
list<int> L[300002];
int ANS[300002],MaxT;

int main(){
    freopen("P1072.txt","r",stdin);
    while(~scanf("%d",&N)){
        MaxT=0;
        for(int i=1;i<300002;++i) L[i].clear();
        for(int i=0;i<N;++i){
            scanf("%d%d",&a,&b);
            MaxT=max(MaxT,b+1);
            L[b+1].push_back(a);
        }
        ANS[0]=ANS[1]=0;
        for(int i=1;i<=MaxT;++i){
            ANS[i]=ANS[i-1];
            for(list<int>::iterator it=L[i].begin();it!=L[i].end();++it){
                ANS[i]=max(ANS[i],ANS[*it]+i-*it);
            }
        }
        printf("%d\n",ANS[MaxT]);
    }
    return 0;
}


