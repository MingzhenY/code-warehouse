#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int A[64],Len,Neg;
void Calculate(long long V){
    if(V < 0) Neg = 1 , V = - V;
    else Neg = 0;
    Len = 0;
    memset(A,0,sizeof(A));
    while(V){
        A[Len++] = V % 3 ;
        V /= 3;
    }
    for(int i = 0 ; i < Len ; ++i){
        while(A[i] >= 2){
            ++A[i + 1];
            A[i] -= 3;
        }
    }
    while(A[Len]){
        while(A[Len] >= 2){
            ++A[Len + 1];
            A[Len] -= 3;
        }
        ++Len;
    }
    if(Neg)
        for(int i = 0 ; i < Len ; ++i)
            A[i] = - A[i];
    for(int i = Len - 1 ; i >= 0 ; --i){
        char ch = A[i] ? A[i] > 0 ? '1' : '-' : '0';
        printf("%c",ch);
    }
    printf("\n");
}
int main(){
    freopen("P1319.txt","r",stdin);
    long long T,n;
    cin >> T;
    while(T-- > 0){
        cin >> n;
        if(n) Calculate(n);
        else cout<<0<<endl;
    }
    return 0;
}


