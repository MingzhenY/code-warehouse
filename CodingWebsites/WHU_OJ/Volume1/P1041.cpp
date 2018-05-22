#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int t,n;
char maze[30][31];
//分层图最短路
int Dist[2][30][30];

int main(){
    freopen("P1041.txt","r",stdin);
    int Sx,Sy,Dx,Dy;
    scanf("%d",&t);
    for(int c=1;c<=t;++c){
        scanf("%d",&n);
        for(int i=0;i<n;++i) scanf("%s",maze[i]);
        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(maze[i][j]=='p') Sx=i,Sy=j,maze[i][j]='r';
                if(maze[i][j]=='a') Dx=i,Dy=j,maze[i][j]='r';
                //r:road  k:wall  d:dogs
            }
        }
        
        memset(Dist,-1,sizeof(Dist));
        Dist[0][Sx][Sy]=0;
        queue<int> Q;
        Q.push((Sx<<5)|Sy);
        while(!Q.empty()){
            int cnt=Q.front();Q.pop();
            int p=cnt>>10,x=(cnt&1023)>>5,y=cnt&31;
            for(int k=0;k<4;++k){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<n&&maze[nx][ny]!='k'){
                    if(maze[nx][ny]=='r'){
                        if(!~Dist[p][nx][ny]){
                            Dist[p][nx][ny]=Dist[p][x][y]+1;
                            Q.push((p<<10)|(nx<<5)|ny);
                        }
                    }
                    else{//dog
                        if(!p && !~Dist[1][nx][ny]){
                            Dist[1][nx][ny]=Dist[1][x][y]+1;
                            Q.push((1<<10)|(nx<<5)|ny);
                        }
                    }
                }
            }
        }
        printf("%s\n",~Dist[0][Dx][Dy] || ~Dist[1][Dx][Dy] ? "Yes" : "No");
    }
    
    
    return 0;
}


