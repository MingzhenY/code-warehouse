#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
using namespace std;
//滚动数组动态规划
LL DP[2][2001];
short int Up[2][2001];
int Ups[2][2001];
char ch[2002];

//单调栈
int Sum[2001];
short int Value[2001];
short int Times[2001];
int Top;


int main(){
    freopen("P1012.txt","r",stdin);
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        memset(Up,0,sizeof(Up));
        memset(DP,0,sizeof(DP));

        for(int i=1;i<=n;++i){
            int I=i&1,_I=!I;
            Top=0;//满递增栈
            scanf("%s",ch+1);
            
            for(int j=1;j<=m;++j){
                if(ch[j]=='w'){
                    Up[I][j]=1+Up[_I][j];
                    Value[++Top]=Up[I][j];
                    Times[Top]=1;
                    Sum[Top]=Sum[Top-1]+Value[Top];
                    
                    while(Top > 1 && Value[Top] <= Value[Top-1]){//合并元素
                    
                        Value[Top-1]=Value[Top];
                        Times[Top-1]+=Times[Top];
                        --Top;
                        Sum[Top]=Sum[Top-1]+Value[Top]*Times[Top];
                    }
                    
                    Ups[I][j]=Sum[Top];
                }
                else {
                    Up[I][j]=Ups[I][j]=Top=0;
                }
                
                DP[I][j]=DP[_I][j]+DP[I][j-1]-DP[_I][j-1]+Ups[I][j];
            }
        }
        cout<<DP[n&1][m]<<endl;
    }
    return 0;
}


