#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
    freopen("P1192.txt","r",stdin);
    int N,a;
    while(cin>>N){
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                cin>>a;
                cout<<(__builtin_popcount(a)&1);
                if(j+1==N) cout<<"\n";
                else cout<<" ";
            }
        }
    }
    return 0;
}


