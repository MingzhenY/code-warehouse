#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#define LL long long
using namespace std;
struct ArcNode{
    int to,width;
    ArcNode *next;
};
ArcNode *List[2007];
void Arc(int from,int to,int width){
    ArcNode *temp = new ArcNode;
    temp->to = to;
    temp->width = width;
    temp->next = List[from];
    List[from] = temp;
}
void DArc(int from,int to,int width){
    Arc(from,to,width);
    Arc(to,from,width);
}
int Sn;
char names[2000][32];
int Len[2000],Key[2000];
int getStr(){
    char str[32];
    scanf("%s",str);
    int len = strlen(str);
    LL key = 0;
    for(int i = 0 ; i < len ; ++i) key = key * 137 % 1000000007;
    
    for(int i = 0 ; i < Sn ; ++i){
        if(Key[i] == key && Len[i] == len){
            int Same = 0;
            for(int j = 0 ; j < len ; ++j) Same += str[j] == names[i][j];
            if(Same == len) return i;
        }
    }
    for(int i = 0 ; i <= len ; ++i) names[Sn][i] = str[i];
    Len[Sn] = len;
    Key[Sn] = key;
    return Sn++;
}
int Width[2000];
void Calculate(int start){
    memset(Width,-1,sizeof(Width));
    queue<int> Q;
    Q.push(start);
    Width[start] = 1000000;
    while(!Q.empty()){
        int Cnt = Q.front();Q.pop();
        ArcNode *temp = List[Cnt];
        while(temp){
            int W = min(Width[Cnt],temp->width);
            if(!~Width[temp->to] || W > Width[temp->to]){
                Width[temp->to] = W;
                Q.push(temp->to);
            }
            temp = temp->next;
        }
    }
}
int main(){
    freopen("P1078.txt","r",stdin);
    int N,M;
    while(~scanf("%d%d",&N,&M)){
        Sn = 0;
        int A,B,W;
        for(int i = 0 ; i < M ; ++i){
            A = getStr();
            B = getStr();
            scanf("%d",&W);
            DArc(A,B,W);
        }
        A = getStr();
        B = getStr();
        Calculate(A);
        printf("%d\n", Width[B]);
        for(int i = 0 ; i < Sn ; ++i){
            while(List[i]){
                ArcNode *temp = List[i];
                List[i] = List[i]->next;
                delete temp;
            }
        }
    }
    return 0;
}


