#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#define INF 2000000000
#define LL long long
using namespace std;
struct Node{
    int cost,quality;
    Node(){}
    Node(int c,int q):cost(c),quality(q){}
    bool operator < (const Node &B)const{return cost < B.cost;}
};
int ID = 0;
int GetStrID(char *str){
    LL ANS = *str;
    while(*++str) ANS = (ANS * 137 + *str) % 10000000007;
    return int(ANS);
}
map<int,int> PID;
Node A[1010][1010];
int Length[1010],B;
int Test(int Q){//得到Q的最小费用
    int Cost = 0;
    for(int i = 0 ; i < ID ; ++i){
        bool Find = false;
        for(int j = 0 ; j < Length[i] ; ++j){
            if(A[i][j].quality >= Q){
                Cost += A[i][j].cost;
                Find = true;
                break;
            }
        }
        if(!Find) return INF;
        if(Cost > B) return INF;
    }
    return Cost;
}
int BS(){
    int L = 0 , R = 1000000001 , M ; //[L,R)  last <= B
    while((L + 1) ^ R){
        M = (L + R) >> 1;
        if(Test(M) <= B) L = M;
        else R = M;
    }
    return L;
}
int main(){
    freopen("P1303.txt","r",stdin);
    int T,n;
    char type[32];
    int cost,quality;
    scanf("%d",&T);
    for(int Case = 1 ; Case <= T ; ++Case){
        scanf("%d%d",&n,&B);
        memset(Length,0,sizeof(Length));
        ID = 0;PID.clear();
        for(int i = 0 ; i < n ; ++i){
            scanf("%s%*s%d%d",type,&cost,&quality);
            int CurID,StrID = GetStrID(type);
            if(PID.count(StrID)) CurID = PID[StrID];
            else PID[StrID] = CurID = ID++;
            A[CurID][Length[CurID]++] = Node(cost,quality);
        }
        for(int i = 0 ; i < ID ; ++i) {
            sort(A[i],A[i]+Length[i]);
        }
        int ANS = BS();
        printf("%d\n",ANS);
    }
    return 0;
}


