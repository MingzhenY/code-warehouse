#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
using namespace std;
struct Matrix{
    char S;//0~25:A-Z  26:Answer  27:Empty -1:Error
    int r,c;
    LL ANS;
    Matrix():S(-1){}
    Matrix(char S,int r = 0,int c = 0,LL ANS = 0):S(S),r(r),c(c),ANS(ANS){}
    void Input(){
        scanf(" %c%d%d",&S,&r,&c);
        ANS = 0;
        //Show();
    }
    Matrix operator *(Matrix B){
        if(S == 27) return B;
        if(B.S == 27) return *this;
        if(-1 == S || -1 == B.S || c != B.r) return Matrix(-1);
        else return Matrix(26,r,B.c,ANS+B.ANS+(LL)r*B.c*B.r);
    }
    void Show(){
        printf("%d %d %d %lld\n",int(S),r,c,ANS);
    }
}M[26];
char str[1024];


Matrix Stack[1024];
int Top;
int main(){
    freopen("P1283.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; ++i) M[i].Input();
    while(~scanf("%s",str)){
        //printf("%s:\n",str);
        int L = strlen(str);
        Stack[Top = 0] = Matrix(27);
        for(int i = 0 ; i < L ; ++i){
            if(str[i] == '(' || str[i] == ')'){
                if(str[i] == '('){
                    Stack[++Top] = Matrix(27);
                    //printf("Advance %d\n",Top);
                }
                else{
                    Stack[Top - 1] = Stack[Top - 1] * Stack[Top];
                    --Top;
                    //printf("Reduce %d :",Top+1);Stack[Top].Show();
                }
            }
            else{
                Matrix Cur = M[str[i] - 'A'];
                Cur.S = 26;
                //printf("Hit :");Cur.Show();
                Stack[Top] = Stack[Top] * Cur;
            }
        }
        //Stack[0].Show();
        if(Stack[0].S == -1) printf("error\n");
        else printf("%lld\n",Stack[0].ANS);
    }
    return 0;
}


