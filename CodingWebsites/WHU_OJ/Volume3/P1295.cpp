#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define Num 100 //数字
#define Sign 101 //符号
#define L1 1// (
#define L2 2// [
#define L3 3// {
#define R3 4// )
#define R2 5// ]
#define R1 6// }
using namespace std;

char str[128];
char S[128];
int Sn,Top;
char Stack[128];
void Transfer(){
    Sn = 0;
    int L = strlen(str);
    for(int i = 0 ; i < L ; ++i){
        switch(str[i]){
            case '(': S[Sn++]=L1;break;
            case '[': S[Sn++]=L2;break;
            case '{': S[Sn++]=L3;break;
            case ')': S[Sn++]=R1;break;
            case ']': S[Sn++]=R2;break;
            case '}': S[Sn++]=R3;break;
        }
    }
    S[Sn] = 0;
}
bool Evaluate(){
    bool Error = false;
    Top = 0;
    Stack[Top] = 0;
    for(int i = 0 ; i < Sn ; ++i){
        if(S[i] <= L3){
            Stack[++Top] = S[i];
        }
        else{
            if(S[i] + Stack[Top] == 7 && Top >= 1) --Top;
            else {
                Error = true;
                break;
            }
        }
    }
    return !Error && !Top;
}
int main(){
    freopen("P1295.txt","r",stdin);
    int N;
    scanf("%d",&N);
    for(int Case = 1 ; Case <= N ; ++Case){
        scanf("%s",str);
        Transfer();
        printf("Case %d: %s\n",Case,Evaluate()?"Legal":"Illegal");
    }
    return 0;
}


