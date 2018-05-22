#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int F[10000],O[10000],r,c;
int Find(int x){return x==F[x]?x:F[x]=Find(F[x]);}
void Union(int x,int y){F[Find(x)]=Find(y);}

char maze[101][102];
int dx[]={0,1,1,1};
int dy[]={1,1,0,-1};
int main(){
    freopen("P1167.txt","r",stdin);
    while(~scanf("%d%d",&r,&c)&&r&&c){
        for(int i=0;i<r;++i) scanf("%s",maze[i]);
        for(int i=0;i<r*c;++i) F[i]=i;
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                O[i*c+j]=maze[i][j]=='O';
            }
        }
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                for(int k=0;k<4;++k){
                    int nx=i+dx[k],ny=j+dy[k];
                    if(nx>=0&&nx<r&&ny>=0&&ny<c){
                        if(maze[nx][ny]==maze[i][j]){
                            Union(i*c+j,nx*c+ny);
                        }
                    }
                }
            }
        }
        int ANS=0;
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                ANS+=(F[i*c+j]==i*c+j) && O[i*c+j];
            }
        }
        printf("%d\n",ANS);
    }
    
    
    return 0;
}


