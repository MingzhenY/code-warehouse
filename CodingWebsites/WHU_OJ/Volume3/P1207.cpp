#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int X;
bool Fix(char *num,int a){
    int b = X - a;
    if(a == b) {
        if(num[a] >= 10 && a){
            ++num[a - 1];
            num[a] -= 10;
            int J = a - 1;
            while(num[J] >= 10){
                num[J] -= 10;
                ++num[--J];
            }
            return true;
        }
        else return false;
    }
    else{
        if(num[a] == num[b]) return false;
        if(num[a] < num[b]){
            ++num[b - 1];
            int J = b - 1;
            while(num[J] >= 10){
                num[J] -= 10;
                ++num[--J];
            }
            num[b] = num[a];
            return true;
        }
        else{
            num[b] = num[a];
            return false;
        }
    }
}
void Solve(char *a){
    int L = strlen(a);
    for(int i = 0 ; i < L ; ++i) a[i] -= '0';
    X = L - 1;
    for(int i = 0 ; i <= X / 2 ; ++i){
        int j = i;
        if(Fix(a,j) && j) --j;
    }
    Fix(a,X/2);
    for(int i = 0 ; i < L ; ++i) a[i] += '0';
    printf("%s\n",a);
}

bool Check(int i){
    char n[64];
    sprintf(n,"%d",i);
    int T = strlen(n) - 1;
    for(int j = 0 ; j < T/2+1 ; ++j){
        if(n[j]!=n[T-j]) return false;
    }
    return true;
}
int Solve2(int i){
    for(int j = i ; j <= 1000000 ; ++j){
        if(Check(j)) return j;
    }
    return -1;
}
char num[100001];
int main(){
    
    freopen("P1207.txt","r",stdin);
    while(~scanf("%s",num)){
        Solve(num);
    }/*
    for(int i = 1 ; i <= 1000000 ; ++i){
        char n[64];
        sprintf(n,"%d",i);
        Solve(n);
        int A = 0 , L = strlen(n) , B = Solve2(i);
        for(int i = 0 ; i < L ; ++i) {
            A *= 10;
            A += n[i] - '0';
        }
        if(A != B){
            printf("i = %d A = %d B = %d\n",i,A,B);
            break;
        }
    }*/
    return 0;
}


