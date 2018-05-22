#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int ANS[1000001][3];

int main(){
    freopen("P1195.txt","r",stdin);
    ANS[0][0]=1;
    for(int i=1;i<=1000000;++i){
        ANS[i][0]=(ANS[i-1][0]+ANS[i-1][2])%10000;
        ANS[i][1]=(ANS[i-1][0]+ANS[i-1][1])%10000;
        ANS[i][2]=(ANS[i-1][0]+(ANS[i-1][1]<<1))%10000;
    }
    int n;
    while(cin>>n) cout<<ANS[n][0]<<endl;
    return 0;
}


