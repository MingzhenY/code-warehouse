#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char str1[2014],str2[1024];
int S1[26],S2[26];
int main(){
    freopen("P1330.txt","r",stdin);
    while(~scanf("%s%s",str1,str2)){
        memset(S1,0,sizeof(S1));
        memset(S2,0,sizeof(S2));
        int L1 = strlen(str1) , L2 = strlen(str2);
        for(int i = 0 ; i < L1 ; ++i){
            ++S1[str1[i] - 'a'];
        }
        for(int i = 0 ; i < L2 ; ++i){
            ++S2[str2[i] - 'a'];
        }
        for(int i = 0 ; i < 26 ; ++i){
            int L = min(S1[i],S2[i]);
            for(int j = 0 ; j < L ; ++j) printf("%c",char('a'+i));
        }
        printf("\n");
    }
    return 0;
}


