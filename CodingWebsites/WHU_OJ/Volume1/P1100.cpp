#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char name[8][64]={
    "littleken",
    "knuthocean",
    "dongfangxu",
    "zap",
    "kittig",
    "robertcui",
    "forest",
    "flirly"
};
int nameLen[8]={9,10,10,3,6,9,6,6},Len;
char str[1000001];
int Calculate(int k){
    int State = 0 , Count = 0;
    for(int i = 0 ; i < Len ; ++i){
        if(str[i] == name[k][State]){
            if(++State == nameLen[k]){
                State = 0;
                Count++;
            }
        }
        else State = 0;
    }
    return Count;
}
int main(){
    freopen("P1100.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T-- > 0){
        scanf("%s",str);
        Len = strlen(str);
        int Max=-1,Maxi;
        for(int i=0;i<8;++i){
            int _Max = Calculate(i);
            if(_Max > Max){
                Max = _Max;
                Maxi = i;
            }
        }
        printf("%s\n",name[Maxi]);
    }
    return 0;
}


