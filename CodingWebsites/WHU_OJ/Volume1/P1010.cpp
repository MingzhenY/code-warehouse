#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
    freopen("P1010.txt","r",stdin);
    //除了最大项其余全部抵消（组合数的结论：从n中选奇数个和选偶数个的方法数相同）
    //公式：Max * 2^(N-1) % 2006
    int N,Max,a;
    while((cin>>N)&&N){
        Max=-(1<<16);
        for(int i=0;i<N;++i) {
            scanf("%d",&a);
            Max=max(Max,a);
        }
        Max%=2006;
        Max=(Max+2006)%2006;
        for(int i=1;i<N;++i) Max=(Max<<1)%2006;
        printf("%d\n",Max);
    }
    return 0;
}


