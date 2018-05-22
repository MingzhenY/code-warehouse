#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int T,m,n,k;
char grid[50][51];
char str[128];
int len;
int dx[]={-1,-1,-1, 0, 0, 1, 1, 1};
int dy[]={-1, 0, 1, 1,-1,-1, 0, 1};
bool Search(int x,int y,int dir,int pos){
    if(pos==len) return true;
    int nx=x+dx[dir],ny=y+dy[dir];
    if(nx>=0&&nx<m&&ny>=0&&ny<n&&grid[nx][ny]==str[pos]) return Search(nx,ny,dir,pos+1);
    else return false;
}

int main(){
    freopen("P1329.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;++i)
            scanf("%s",grid[i]);
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                grid[i][j]=toupper(grid[i][j]);
        scanf("%d",&k);
        while(k--){
            scanf("%s",str);
            len=strlen(str);
            for(int i=0;i<len;++i)
                str[i]=toupper(str[i]);
            bool Found=false;
            for(int i=0;i<m;++i){
                for(int j=0;j<m;++j){
                    if(grid[i][j]==str[0]){
                        Found=false;
                        for(int k=0;k<8;++k) Found|=Search(i,j,k,1);
                        if(Found) {
                            printf("%d %d\n",i+1,j+1);
                            break;
                        }
                    }
                }
                if(Found) break;
            }
        }
        if(T) printf("\n");
    }
    return 0;
}


