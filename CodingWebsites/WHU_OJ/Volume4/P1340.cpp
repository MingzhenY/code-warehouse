#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
    freopen("P1340.txt","r",stdin);
    int N;
    cin>>N;
    while(N-- > 0){
        string A,B;
        cin>>A>>B;
        for(int i = 0 ; i < A.length() ; ++i)
            A[i] = !i ? toupper(A[i]) : tolower(A[i]);
        
        for(int i = 0 ; i < B.length() ; ++i)
            B[i] = !i ? toupper(B[i]) : tolower(B[i]);
        
        cout<<B<<" "<<A<<endl;
    }
    return 0;
}


