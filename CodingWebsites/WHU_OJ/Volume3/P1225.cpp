#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define maxn 200000
using namespace std;
int N,K;
int D[maxn+1];

int St[maxn+1],Fst,End;
void Init(){//[Fst,End)
    Fst = 1;
    End = 1;
    memset(D,-1,sizeof(D));
}
void Push(int v){St[End++] = v;}
int Pop(){return Fst == End ? -1 : St[Fst++];}

int main(){
    freopen("P1225.txt","r",stdin);
    while(~scanf("%d%d",&N,&K)){
        if(K <= N){
            printf("%d\n",N - K);
            continue;
        }
        Init();
        D[N] = 0;
        Push(N);
        int cnt,Ans = -1;
        while(-1 != (cnt = Pop())){
            if(cnt == K){
                Ans = D[cnt];
                break;
            }
            if(cnt > 0 && -1 == D[cnt - 1]){
                D[cnt - 1] = D[cnt] + 1;
                Push(cnt - 1);
            }
            
            if(cnt < maxn && -1 == D[cnt + 1]){
                D[cnt + 1] = D[cnt] + 1;
                Push(cnt + 1);
            }
            
            if((cnt << 1) <= maxn && -1 == D[cnt << 1]){
                D[cnt << 1] = D[cnt] + 1;
                Push(cnt << 1);
            }
        }
        printf("%d\n",Ans);
    }
    return 0;
}


