/*
 WA ，P1078#2中去掉了map的使用，就AC了
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
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
int N,M,w;
map<string,int> MAP;
string str1,str2;
int Dist[2007];
bool InQ[2007];
void Calculate(int start){
    memset(InQ,0,sizeof(InQ));
    queue<int> Q;
    Q.push(start);
    InQ[start] = true;
    while(!Q.empty()){
        int Cnt = Q.front();Q.pop();
        InQ[Cnt] = false;
        for(ArcNode *temp = List[Cnt] ; temp ; temp = temp->next){
            int W = min(Dist[Cnt],temp->width);
            if(10000007 == Dist[temp->to] || W > Dist[temp->to]){
                Dist[temp->to] = W;
                if(!InQ[temp->to]){
                    Q.push(temp->to);
                    InQ[temp->to] = true;
                }
            }
        }
    }
}
int main(){
    freopen("P1078.txt","r",stdin);
    while(cin >> N >> M){
        int PID = 0 , ID1 , ID2;
        MAP.clear();
        for(int i = 0 ; i < M ; ++i){
            cin >> str1 >> str2 >> w;
            if(MAP.count(str1)) ID1 = MAP[str1];
            else ID1 = MAP[str1] = ++PID;
            if(MAP.count(str2)) ID2 = MAP[str2];
            else ID2 = MAP[str2] = ++PID;
            DArc(ID1,ID2,w);
        }
        cin >> str1 >> str2;
        if(MAP.count(str1)) ID1 = MAP[str1];
        else ID1 = MAP[str1] = ++PID;
        if(MAP.count(str2)) ID2 = MAP[str2];
        else ID2 = MAP[str2] = ++PID;
        
        for(int i = 1 ; i <= PID ; ++i) Dist[i] = 10000007;
        Calculate(ID1);
        cout<< (Dist[ID2] == 10000007 ? -1 : Dist[ID2]) << endl;
        for(int i = 1 ; i <= N ; ++i){
            ArcNode *temp;
            while(List[i]){
                temp = List[i];
                List[i] = List[i]->next;
                delete temp;
            }
        }
    }
    return 0;
}


