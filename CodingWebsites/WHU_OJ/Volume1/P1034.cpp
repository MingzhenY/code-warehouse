#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
    freopen("P1034.txt","r",stdin);
    long long n;
    while(cin>>n){
        long long a=(n*n*n+5*n+6)/6;
        cout<<a<<endl;
    }
    return 0;
}


