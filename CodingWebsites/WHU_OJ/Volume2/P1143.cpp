#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
    freopen("P1143.txt","r",stdin);
    int m,p,n;
    while((cin>>m>>p>>n)&&m&&p&&n){
        cout<<max(m,p*n)<<endl;
    }
    return 0;
}


