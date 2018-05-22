/*
 用栈实现的树状DP
 A[Cnt][0]表示当前节点为黑色时，该子树的最小答案，一定有解
 A[Cnt][1]表示当前节点为白色且父节点为黑色时，该子树的最小答案，可能无解，用-1表示
 A[Cnt][2]表示当前节点为白色且父节点为白色时，该子树的最小答案，可能无解，用-1表示
 简单来说就是：
 如果当前为黑色，那么子节点随便，取最小即可
 如果当前为白色且父节点为黑，那么当前节点的子节点必须为白色，且子节点的子节点中有且仅有一个黑色。
 如果当前为白色且父节点为白，那么子节点中有且仅有一个黑色
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
struct ArcNode{
    int to;
    ArcNode *next;
};
ArcNode *List[10007];
void Arc(int from,int to){
    ArcNode *temp = new ArcNode;
    temp->to = to;
    temp->next = List[from];
    List[from] = temp;
}
void DArc(int from,int to){
    Arc(from,to);Arc(to,from);
}
int A[10007][3];//0 for black , 1 for black-white , 2 for white-white
int Stack[10007],Sn;
ArcNode *P[10007];
void Calculate(){
    Stack[Sn = 1] = 1;
    P[1] = List[1];
    while(Sn > 0){
        if(P[Sn]){//Advance
            ArcNode *temp = P[Sn];
            P[Sn] = P[Sn]->next;
            if(temp->to != Stack[Sn - 1]){//Expand
                ++Sn;
                Stack[Sn] = temp->to;
                P[Sn] = List[temp->to];
            }
        }
        else{//Calculate and Reduce
            int Cnt = Stack[Sn] , NumberOf2 = 0 , SumOf2 = 0;
            //A[Cnt][0] and A[Cnt][1]
            A[Cnt][0] = 1 ; A[Cnt][1] = 0;
            for(ArcNode *temp = List[Cnt];temp;temp=temp->next){
                if(temp->to == Stack[Sn - 1]) continue;
                A[Cnt][0] += ~A[temp->to][1] ? min(A[temp->to][0],A[temp->to][1]) : A[temp->to][0] ;
                if(~A[temp->to][2]){
                    A[Cnt][1] += ~A[Cnt][1] ? A[temp->to][2] : 0;
                    SumOf2 += A[temp->to][2];
                }
                else{//-1 == A[temp->to][2]
                    ++NumberOf2;
                    A[Cnt][1] = -1;
                }
            }
            //A[Cnt][2]
            if(NumberOf2 >= 2) A[Cnt][2] = -1;
            else if(NumberOf2 == 1){
                A[Cnt][2] = 0;
                for(ArcNode *temp = List[Cnt];temp;temp=temp->next){
                    if(temp->to == Stack[Sn - 1]) continue;
                    if(!~A[temp->to][2]) A[Cnt][2] += A[temp->to][0] - A[temp->to][2];
                    A[Cnt][2] += A[temp->to][2];
                }
            }
            else{
                A[Cnt][2] = -1;
                for(ArcNode *temp = List[Cnt];temp;temp=temp->next){
                    if(temp->to == Stack[Sn - 1]) continue;
                    int CurA = SumOf2 + A[temp->to][0] - A[temp->to][2];
                    if(!~A[Cnt][2] || CurA < A[Cnt][2]){
                        A[Cnt][2] = CurA;
                    }
                }
            }
            //printf("A[%d]=(%d,%d,%d)\n",Cnt,A[Cnt][0],A[Cnt][1],A[Cnt][2]);
            --Sn;
        }
    }
}
int main(){
    freopen("P1240.txt","r",stdin);
    int N,t,a,b;
    while(1){
        scanf("%d",&N);
        for(int i = 1 ; i < N ; ++i){
            scanf("%d%d",&a,&b);
            DArc(a,b);
        }
        scanf("%d",&t);
        Calculate();
        printf("%d\n",~A[1][2] ? min(A[1][0],A[1][2]) : A[1][0]);
        for(int i = 1 ; i <= N ; ++i){
            ArcNode *temp;
            while(List[i]){
                temp = List[i];
                List[i] = List[i]->next;
                delete temp;
            }
        }
        if(!~t) break;
    }
    return 0;
}


