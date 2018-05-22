#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
    freopen("P1035.txt","r",stdin);
    int n;
    while((cin>>n) && n)
        cout<<(++n/2)<<endl;
    return 0;
}


