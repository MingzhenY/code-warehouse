#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int Count[26],Len;
char str[100001];
int main(){
    freopen("P1291.txt","r",stdin);
    while(~scanf("%s",str)&&str[0]!='#'){
        Len = strlen(str);
        for(int i = 0 ; i < Len ; ++i) str[i] -= 'a';
        memset(Count,0,sizeof(Count));
        int ANS_L = 1,ANS_I = 0;
        int L = 0 , R = 0 , Dif = 0;//[L,R)
        while(R < Len){
            if(Dif == R - L){//Record and expand
                if(Dif > ANS_L){
                    ANS_L = Dif;
                    ANS_I = L;
                }
                Dif += !Count[str[R++]]++;
            }
            else{//cut
                Dif -= !--Count[str[L++]];
            }
        }
        for(int i = 0 ; i < Len ; ++i) str[i] += 'a';
        str[ANS_L+ANS_I] = '\0';
        printf("%d %s\n",ANS_L,str+ANS_I);
    }
    return 0;
}


