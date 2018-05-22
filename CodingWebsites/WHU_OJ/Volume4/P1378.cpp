#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n,m,a,b;
vector<int> List[101];
int Dist[101],In[101],Depth[101];
void Init(){
    memset(Dist,-1,sizeof(Dist));
    memset(In,0,sizeof(In));
    memset(Depth,0,sizeof(Depth));
    for(int i = 0 ; i <= 100 ; ++i) List[i].clear();
}
int main(){
    freopen("P1378.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)&&n){
        Init();
        bool Valid = true;
        for(int i = 0 ; i < m ; ++i){
            scanf("%d%d",&a,&b);
            List[a].push_back(b);
            ++In[b];
            if(a == b) Valid = false;
        }
        for(int i = 1 ; i <= n ; ++i){
            if(In[i] >= 2) Valid = false;
            if(!In[i]) Dist[i] = 0;
        }
        if(Valid){
            queue<int> Q;
            for(int i = 1 ; i <= n ; ++i){
                if(!Dist[i]) Q.push(i);
            }
            if(Q.empty()) Valid = false;
            while(!Q.empty() && Valid){
                int cnt = Q.front();Q.pop();
                for(int i = 0 ; i < List[cnt].size() ; ++i){
                    int to = List[cnt][i];
                    if(~Dist[to]){
                        Valid = false;
                    }
                    else{
                        Dist[to] = Dist[cnt] + 1;
                        Q.push(to);
                    }
                }
            }
        }
        if(Valid){
            for(int i = 1 ; i <= n ; ++i){
                ++Depth[Dist[i]];
            }
            int Width = 0 , Deep = 0 ;
            for(int i = 0 ; i <= n ; ++i){
                if(Depth[i]) Deep = i;
                if(Depth[i] > Width){
                    Width = Depth[i];
                }
            }
            printf("%d %d\n",Deep,Width);
        }
        else printf("INVALID\n");
    }
    return 0;
}


