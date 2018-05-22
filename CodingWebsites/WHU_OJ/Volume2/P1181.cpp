/*
 TLE
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
char E[1<<25],F[1<<16],G[1<<9],H[1<<4];//5,4,3,2
int A[5][5],B[5][5],C,D,m,n;
int FX[6][26];
int dx[5]={-1,0,1,0,0};
int dy[5]={0,1,0,-1,0};
void Init(){
    memset(FX,0,sizeof(FX));
    memset(E,-1,sizeof(E));
    memset(F,-1,sizeof(F));
    memset(G,-1,sizeof(G));
    memset(H,-1,sizeof(H));
    for(int i = 2 ; i <= 5 ; ++i){
        for(int j = 0 ; j < i * i ; ++j){
            for(int t = 0 ; t < 5 ; ++t){
                int nx = j / i + dx[t] , ny = j % i + dy[t];
                if(nx >= 0 && nx < i && ny >= 0 && ny < i){
                    FX[i][j] = FX[i][j] | (1 << (nx * i + ny));
                }
            }
        }
    }
    queue<int> Q;
    int MAX;
    if(n == 5){
        E[0] = 0 ; Q.push(0);
        MAX = n * n;
        while(!Q.empty()){
            int cnt = Q.front();Q.pop();
            for(int i = 0 ; i < MAX ; ++i){
                int S = cnt ^ FX[n][i];
                if(!~E[S] || E[cnt] + 1 < E[S]){
                    E[S] = E[cnt] + 1;
                    Q.push(S);
                }
            }
        }
    }
    
    if(n == 4){
        F[0] = 0 ; Q.push(0);
        MAX = n * n;
        while(!Q.empty()){
            int cnt = Q.front();Q.pop();
            for(int i = 0 ; i < MAX ; ++i){
                int S = cnt ^ FX[n][i];
                if(!~F[S] || F[cnt] + 1 < F[S]){
                    F[S] = F[cnt] + 1;
                    Q.push(S);
                }
            }
        }
    }
    
    if(n == 3){
        G[0] = 0 ; Q.push(0);
        MAX = n * n;
        while(!Q.empty()){
            int cnt = Q.front();Q.pop();
            for(int i = 0 ; i < MAX ; ++i){
                int S = cnt ^ FX[n][i];
                if(!~G[S] || G[cnt] + 1 < G[S]){
                    G[S] = G[cnt] + 1;
                    Q.push(S);
                }
            }
        }
    }
    
    if(n == 2){
        H[0] = 0 ; Q.push(0);
        MAX = n * n;
        while(!Q.empty()){
            int cnt = Q.front();Q.pop();
            for(int i = 0 ; i < MAX ; ++i){
                int S = cnt ^ FX[n][i];
                if(!~H[S] || H[cnt] + 1 < H[S]){
                    H[S] = H[cnt] + 1;
                    Q.push(S);
                }
            }
        }
    }
}
int Test(int k){
    int ANS = 0 , Left = 0 ,t = 0;
    C = D;
    for(int t = 0 ; k ; ++t , k >>= 1){
        if(k & 1){
            ++ANS;
            C = C ^ FX[n][t];
        }
    }
    return C ? -1 : ANS;
}
int main(){
    freopen("P1181.txt","r",stdin);
    scanf("%d%d",&n,&m);
    Init();
    for(int Case = 1 ; Case <= m ; ++Case){
        D = 0 ;
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < n ; ++j)
                scanf("%d",&A[i][j]);
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < n ; ++j)
                scanf("%d",&B[i][j]);
        for(int i = 0 , t = 0 ; i < n ; ++i)
            for(int j = 0 ; j < n ; ++j , ++t)
                D = D | ((A[i][j] ^ B[i][j]) << t);
        
        int ANS;
        switch(n){
            case 2:ANS = H[D];break;
            case 3:ANS = G[D];break;
            case 4:ANS = F[D];break;
            case 5:ANS = E[D];break;
        }
        printf("Case %d:\n",Case);
        if(ANS == -1){
            printf("No Solution!\n");
        }
        else printf("%d\n",ANS);
    }
    return 0;
}


