#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
    freopen("P1154.txt","r",stdin);
    int TC=0;
    string str;
    while(cin>>str){
        if(str[0]=='#') break;
        for(int i=1;i<str.length();i+=2)
            str[i]=toupper(str[i]);
        printf("Case %d: %s\n",++TC,str.c_str());
    }
    return 0;
}


