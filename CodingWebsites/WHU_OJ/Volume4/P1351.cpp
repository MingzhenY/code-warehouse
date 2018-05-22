#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int M[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
int main(){
    freopen("P1351.txt","r",stdin);
    int T,Month,Day;
    scanf("%d",&T);
    while(T-- > 0){
        scanf("%d%d",&Month,&Day);
        for(int i = 0 ; i <= 500 ; ++i){
            if(Month == 8 && Day == 8){
                printf("%d\n",i);
                break;
            }
            if(++Day > M[Month]){
                if(++Month > 12) Month = 1;
                Day = 1;
            }
        }
    }
    return 0;
}


