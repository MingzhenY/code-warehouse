#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int A[10],Ten[10];
void Init(){
    Ten[0] = 1;
    for(int i = 1 ; i < 10 ; ++i) Ten[i] = Ten[i - 1] * 10;
}
int GetDigit(int v){
    int ANS = 0 ;
    while(v) ++ANS , v /= 10 ;
    return ANS;
}
void Calculate(int v,int k){//V has k digits
    int Cur = v / Ten[k - 1], Remain = v - Cur * Ten[k - 1];
    //计算最高位
    for(int i = 0 ; i < Cur ; ++i) A[i] += Ten[k - 1];
    A[Cur] += Remain;
    //计算剩余位
    if(k > 1) {
        for(int i = 0 ; i < 10 ; ++i) A[i] +=  Cur * Ten[k - 2] * (k - 1);
        Calculate(Remain,k - 1);
    }
}
void Count(int V){//Count number of digits from numbers less than V
    memset(A,0,sizeof(A));
    Calculate(V,GetDigit(V));
    for(int i = GetDigit(V) ; --i >= 0 ;) A[0] -= Ten[i];
}
int main(){
    freopen("P1254.txt","r",stdin);
    Init();
    int L,R;
    while(~scanf("%d%d",&L,&R) && L && R){
        if(L > R) {
            L = L ^ R;
            R = L ^ R;
            L = L ^ R;
        }
        int ANS[10];
        Count(R+1);
        for(int i = 0 ; i < 10 ; ++i) ANS[i] = A[i];
        Count(L);
        for(int i = 0 ; i < 10 ; ++i) ANS[i] -= A[i];
        for(int i = 0 ; i < 10 ; ++i)
            printf("%d%c",ANS[i],9^i?' ':'\n');
    }
    return 0;
}


