#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;
int N,M;
int A[301][301];
int D[301][301];
bool Inq[301][301];
struct Node{
    int id,dist;
    Node(int id=0,int dist=0):id(id),dist(dist){}
    bool operator < (const Node B)const{return dist > B.dist;}
};
priority_queue<Node> Q;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int main(){
    freopen("P1089.txt","r",stdin);
    while(~scanf("%d%d",&M,&N)){
        for(int i=1;i<=M;++i){
            for(int j=1;j<=N;++j){
                scanf("%d",&A[i][j]);
            }
        }
        
        memset(Inq,0,sizeof(Inq));
        memset(D,-1,sizeof(D));
        while(!Q.empty()) Q.pop();
        
        D[1][1]=A[1][1];
        Q.push(Node((1<<9)|1,D[1][1]));
        
        while(!Q.empty()){
            Node cnt=Q.top();Q.pop();
            int x=cnt.id>>9,y=cnt.id&511;
            Inq[x][y]=false;
            for(int k=0;k<4;++k){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx>=1&&nx<=M&&ny>=1&&ny<=N){
                    if(!~D[nx][ny] || D[x][y]+A[nx][ny] < D[nx][ny]){
                        if(!Inq[nx][ny]){
                            D[nx][ny]=cnt.dist+A[nx][ny];
                            Q.push(Node((nx<<9)|ny,D[nx][ny]));
                            Inq[nx][ny]=true;
                        }
                    }
                }
            }
        }
        printf("%d\n",D[M][N]);
    }
    return 0;
}


