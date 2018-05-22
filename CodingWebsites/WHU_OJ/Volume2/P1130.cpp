#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int maxprime[20831534];
int prime[1319947],pn;
int Dif[1319947];
bool FirstWin[1319947];
void Init(){
    memset(maxprime,-1,sizeof(maxprime));
    pn = 0;
    for(int i = 2 ; i <= 20831533 ; ++i){
        if(~maxprime[i]) continue;
        prime[++pn] = i;
        Dif[pn] = prime[pn] - prime[pn - 1];
        for(int j = i ; j <= 20831533 ; j += i) maxprime[j] = i;
    }
}

int main(){
    freopen("P1130.txt","r",stdin);
    Init();
    int G,n;
    scanf("%d",&G);
    for(int Case = 1 ; Case <= G ; ++Case){
        scanf("%d",&n);
        int MAXI = 1;
        while(Dif[MAXI] <= n) ++MAXI;
        FirstWin[MAXI - 1] = 0;
        for(int i = MAXI - 2; i >= 0 ; --i){
            bool Win = false;
            for(int j = i + 1 ; j <= pn ; ++j){
                if(prime[j] - prime[i] <= n){
                    if(!FirstWin[j]) {
                        Win = true;
                        break;
                    }
                }
                else break;
            }
            FirstWin[i] = Win;
            //printf("FirstWin[%d]=%d\n",prime[i],FirstWin[i]);
        }
        if(FirstWin[0]){
            for(int i = 1 ; i <= pn ; ++i){
                if(!FirstWin[i]) {
                    printf("A %d\n",prime[i]);
                    break;
                }
            }
        }
        else printf("B\n");
    }
    return 0;
}


