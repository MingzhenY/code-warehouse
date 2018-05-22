#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main(){
    freopen("P1045.txt","r",stdin);
    int T;
    cin>>T;
    string str;
    getline(cin,str);
    for(int Case = 1 ; Case <= T ; ++Case){
        getline(cin,str);
        str[0] = toupper(str[0]);
        for(int i = 1 ; i < str.length() ; ++i) str[i] = str[i - 1] == ' ' ? str[i] : tolower(str[i]);
        cout<<str<<endl;
    }
    return 0;
}


