#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int A[21][21][21];
int F(int a,int b,int c){
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a > 20 || b > 20 || c > 20) a = 20 , b = 20 , c = 20 ;
    if(-1 != A[a][b][c]) return A[a][b][c];
    if(a < b && b < c) return A[a][b][c] = F(a,b,c-1) + F(a,b-1,c-1)-F(a,b-1,c);
    else return A[a][b][c] = F(a-1,b,c) + F(a-1,b-1,c) + F(a-1,b,c-1) - F(a-1,b-1,c-1);
}
void Init(){
    memset(A,-1,sizeof(A));
}
int main(){
    freopen("P1171.txt","r",stdin);
    Init();
    int N,a,b,c;
    scanf("%d",&N);
    while(N-- > 0){
        scanf("%d%d%d",&a,&b,&c);
        printf("W(%d, %d, %d) = %d\n",a,b,c,F(a,b,c));
    }
    return 0;
}


