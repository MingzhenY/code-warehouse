#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
using namespace std;
struct Int{
    char a[1000];
    int Len;
    Int(){memset(a,0,sizeof(a));Len = 1;}
    Int(int k){
        if(0 == k) {
            Len = 1;
            a[0] = 0;
        }
        else{
            Len = 0;
            while(k){
                a[Len++] = k % 10;
                k /= 10;
            }
        }
    }
    Int operator +(Int B){
        Int ANS;
        ANS.Len = max(Len,B.Len);
        for(int i = Len ; i < ANS.Len ; ++i) a[i] = 0;
        for(int i = B.Len ; i < ANS.Len ; ++i) B.a[i] = 0;
        int d = 0;
        for(int i = 0 ; i < ANS.Len ; ++i){
            ANS.a[i] = d + a[i] + B.a[i];
            d = ANS.a[i] / 10;
            ANS.a[i] %= 10;
        }
        if(d) ANS.a[ANS.Len++] = d;
        return ANS;
    }
    Int operator *(Int B){
        Int ANS;
        ANS.Len = Len * B.Len + 2;
        for(int i = 0 ; i < Len ; ++i){
            for(int j = 0 ; j < B.Len ; ++j){
                ANS.a[i + j] += a[i] * B.a[j];
                int L = i + j;
                while(ANS.a[L]>=10){
                    ANS.a[L + 1] += ANS.a[L] / 10;
                    ANS.a[L] %= 10;
                    ++L;
                }
            }
        }
        while(ANS.Len && !ANS.a[ANS.Len]) --ANS.Len;
        ++ANS.Len;
        return ANS;
    }
    void Show(){
        for(int i = Len - 1 ; i >= 0 ; --i)
            printf("%d",a[i]);
        printf("\n");
    }
};


int N;
char str[32];

int Left;
bool Used[26];
void Init(){
    Left = 26;
    memset(Used,0,sizeof(Used));
}
int Take(int k){
    int Rank = 0;
    for(int i = 0 ; i < 26 ; ++i){
        if(k == i) {
            --Left;
            Used[i] = 1 ;
            return Rank;
        }
        if(!Used[i]) ++Rank;
    }
    return -1;
}
Int Calculate(int T,int k){
    Int ANS(1);
    while(k){
        ANS = ANS * Int(T--);
        --k;
    }
    return ANS;
}
int main(){
    freopen("P1106.txt","r",stdin);
    while(~scanf("%d",&N) && N){
        Init();
        scanf("%s",str);
        int Len = strlen(str) ;
        Int Rank(0);
        for(int i = 0 , k = Len - 1 ; i < Len ; ++i , --k){
            int A = Take(str[i] -= 'A');
            Rank = Rank + Int(A) * Calculate(Left,k);
        }
        Rank.Show();
    }
    return 0;
}


