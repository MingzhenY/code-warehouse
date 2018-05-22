#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char A[][128]={
"1",
"1",
"2",
"5",
"14",
"42",
"132",
"429",
"1430",
"4862",
"16796",
"58786",
"208012",
"742900",
"2674440",
"9694845",
"35357670",
"129644790",
"477638700",
"1767263190",
"6564120420",
"24466267020",
"91482563640",
"343059613650",
"1289904147324",
"4861946401452"};
int main(){
    freopen("P1287.txt","r",stdin);
    int n;
    while(cin>>n)
        cout<<A[n/2]<<endl;
    return 0;
}


