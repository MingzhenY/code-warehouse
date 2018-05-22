#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
struct ArcNode{
    int to,power,speed,cost;
    char letter;
    ArcNode *next;
    ArcNode():next(NULL){}
    ArcNode(int to,int power,int speed,int cost,char letter):to(to),power(power),speed(speed),cost(cost),letter(letter),next(NULL){}
};

struct Node{
    ArcNode *List;
    int Dist,Pre;
    char letter;
    Node():Dist(-1),Pre(-1),List(NULL){}
}node[100];

void Arc(int from,int to,int power,int speed,int cost,char letter){
    ArcNode *temp = new ArcNode(to,power,speed,cost,letter);
    temp->next = node[from].List;
    node[from].List = temp;
}

void DArc(int from,int to,int power,int speed,int cost,char letter){
    Arc(from,to,power,speed,cost,letter);
    Arc(to,from,power,speed,cost,letter);
}
queue<int> Q;
char elixirs[100],elin;
int main(){
    freopen("P1009.txt","r",stdin);
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        //read roads
        for(int i=0;i<m;++i){
            int from,to,power,speed,cost;
            char letter;
            scanf("%d%d%d%d%d %c",&from,&to,&power,&speed,&cost,&letter);
            DArc(from,to,power,speed,cost,letter);
        }
        int plovers,slovers;
        scanf("%d%d",&plovers,&slovers);
        //find path from 0 to n-1
        node[0].Dist=0;
        Q.push(0);
        while(!Q.empty()){
            int cnt = Q.front();Q.pop();
            ArcNode *temp = node[cnt].List;
            while(temp){
                if(temp->power < plovers && temp->speed < slovers){
                    if(!~node[temp->to].Dist || node[cnt].Dist + temp->cost < node[temp->to].Dist){
                        node[temp->to].Dist = node[cnt].Dist + temp->cost;
                        node[temp->to].Pre  = cnt;
                        node[temp->to].letter = temp->letter;
                        Q.push(temp->to);
                    }
                }
                temp=temp->next;
            }
        }
        int cur=n-1,pre;
        elin = 0;
        while(-1 != (pre = node[cur].Pre)){
            elixirs[elin++]=node[cur].letter;
            cur = pre;
        }
        for(int i=elin-1;i>=0;--i) printf("%c",elixirs[i]);
        printf("\n");
        
        //clean up node[]
        for(int i=0;i<n;++i){
            ArcNode *temp;
            while(!node[i].List){
                temp = node[i].List;
                node[i].List = node[i].List->next;
                delete temp;
            }
            node[i].Dist=node[i].Pre=-1;
        }
    }
    
    
    return 0;
}


