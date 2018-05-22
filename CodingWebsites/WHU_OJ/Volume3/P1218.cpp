#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
bool Vis[21][21][21];
int A,B,C;
void Init(){
    memset(Vis,0,sizeof(Vis));
}
void Pour(int a,int b,int c,int &na,int &nb,int &nc,int k){
    switch(k){
        case 0://A -> B
            if(a + b >= B){
                na = a + b - B;
                nb = B;
                nc = c;
            }
            else{
                na = 0;
                nb = a + b;
                nc = c;
            }
            break;
        case 1://A -> C
            if(a + c >= C){
                na = a + c - C;
                nb = b;
                nc = C;
            }
            else{
                na = 0;
                nb = b;
                nc = a + c;
            }
            break;
        case 2://B -> A
            if(b + a >= A){
                na = A;
                nb = b + a - A;
                nc = c;
            }
            else{
                na = b + a;
                nb = 0;
                nc = c;
            }
            break;
        case 3://B -> C
            if(b + c >= C){
                na = a;
                nb = b + c - C;
                nc = C;
            }
            else{
                na = a;
                nb = 0;
                nc = b + c;
            }
            break;
        case 4://C -> A
            if(c + a >= A){
                na = A;
                nb = b;
                nc = c + a - A;
            }
            else{
                na = c + a;
                nb = b;
                nc = 0;
            }
            break;
        case 5://C -> B
            if(c + b >= B){
                na = a;
                nb = B;
                nc = c + b - B;
            }
            else{
                na = a;
                nb = c + b;
                nc = 0;
            }
            break;
    }
}
void Calculate(){
    Vis[0][0][C] = true;
    queue<int> Q;
    Q.push(C);
    while(!Q.empty()){
        int Cnt = Q.front();Q.pop();
        int a,b,c,ta,tb,tc;
        a = Cnt >> 10;
        b = (Cnt >> 5) & 31;
        c = Cnt & 31;
        for(int i = 0 ; i < 6 ; ++i){
            Pour(a,b,c,ta,tb,tc,i);
            if(!Vis[ta][tb][tc]){
                Vis[ta][tb][tc] = true;
                Q.push((ta<<10)|(tb<<5)|tc);
            }
        }
    }
}
void Show(){
    //C when A is empty
    bool ANS[21];
    memset(ANS,0,sizeof(ANS));
    for(int i = 0 ; i <= B ; ++i){
        for(int j = 0 ; j <= C ; ++j){
            if(Vis[0][i][j]) ANS[j] = 1;
        }
    }
    bool First = true;
    for(int i = 1 ; i <= C ; ++i){
        if(ANS[i]){
            if(First) printf("%d",i);
            else printf(" %d",i);
            First = false;
        }
    }
    printf("\n");
}
int main(){
    freopen("P1218.txt","r",stdin);
    while(~scanf("%d%d%d",&A,&B,&C)){
        Init();
        Calculate();
        Show();
    }
    return 0;
}


