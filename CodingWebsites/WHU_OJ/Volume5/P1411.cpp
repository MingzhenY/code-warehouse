#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char B[15][15];
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,1,-1,-1,0,1};
/*  2   3   7
    1       6
    0   4   5
 */
bool check(int x,int y,char cur){
    if(B[x][y]!='.') return false;
    //Count stones in each direction
    int Count[8];
    for(int i=0;i<8;++i){
        int nx=x+dx[i],ny=y+dy[i];
        Count[i]=0;
        while(nx>=0&&nx<15&&ny>=0&&ny<15&&B[nx][ny]==cur){
            Count[i]++;
            nx+=dx[i];
            ny+=dy[i];
        }
    }
    //test for '-'
    if(Count[1]+Count[6]>=4) return true;
    //test for '|'
    if(Count[3]+Count[4]>=4) return true;
    //test for '/'
    if(Count[0]+Count[7]>=4) return true;
    //test for '\'
    if(Count[2]+Count[5]>=4) return true;
    return false;
}
int main(){
    freopen("P1411.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T-->0){
        for(int i=0;i<15;++i) scanf("%s",B[i]);
        int Black=0,White=0;
        for(int i=0;i<15;++i){
            for(int j=0;j<15;++j){
                Black+=B[i][j]=='B';
                White+=B[i][j]=='W';
            }
        }
        char cur = Black == White ? 'B' : 'W';
        bool WIN = false;
        for(int i=0;i<15;++i){
            for(int j=0;j<15;++j){
                WIN|=check(i,j,cur);
            }
        }
        printf("%s\n",WIN?"YES":"NO");
    }
    return 0;
}


