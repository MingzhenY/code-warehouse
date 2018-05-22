#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char str[288][2052];
char file[2052];
int L[288],Lfile,Lans;
bool Done[288];
void Combine(int a,int b){
    Lfile = L[a] + L[b];
    for(int i = 0 ; i < L[a] ; ++i){
        file[i] = str[a][i];
    }
    for(int i = 0 ; i < L[b] ; ++i){
        file[L[a] + i] = str[b][i];
    }
    file[Lfile] = 0;
}
bool Check(int N){
    memset(Done,0,sizeof(Done));
    for(int i = 0 ; i < N ; ++i){
        for(int j = i + 1 ; j < N ; ++j){
            if(Done[j] || L[i] + L[j] != Lans) continue;
            int Fit = 0 ;
            for(int k = 0 ; k < L[i] ; ++k) Fit += str[i][k] == file[k];
            for(int k = 0 ; k < L[j] ; ++k) Fit += str[j][k] == file[L[i]+k];
            if(Fit == Lans){
                Done[i] = true;
                Done[j] = true;
            }
            else continue;
            Fit = 0;
            for(int k = 0 ; k < L[j] ; ++k) Fit += str[j][k] == file[k];
            for(int k = 0 ; k < L[i] ; ++k) Fit += str[i][k] == file[L[j]+k];
            if(Fit == Lans){
                Done[i] = true;
                Done[j] = true;
            }
            else continue;
        }
        if(!Done[i]) return false;
    }
    return true;
}
void Solve(int N){
    if(0 == N) return;
    Lans = 2 * Lans / N;
    for(int i = 1 ; i < N ; ++i){
        if(L[0] + L[i] != Lans) continue;
        //Try str[0] + str[i]
        Combine(0,i);
        if(Check(N)) break;
        //Try str[i] + str[0]
        Combine(i,0);
        if(Check(N)) break;
    }
    printf("%s\n",file);
}
int main(){
    freopen("P1333.txt","r",stdin);
    int N = 0 , Case ;
    scanf("%d",&Case);
    while(fgets(str[N],2052,stdin)){
        L[N] = strlen(str[N]);
        if(str[N][L[N]-1]=='\n') str[N][--L[N]] = 0;
        Lans += L[N];
        if(0 == L[N]) Solve(N) , N = Lans = 0;
        else ++N;
    }
    Solve(N);
    return 0;
}


