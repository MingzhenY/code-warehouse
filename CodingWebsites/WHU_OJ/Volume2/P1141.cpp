#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
bool Vis[26];
char key[128],ch;
int Trans[26],Tn;
int RevT[26];
int main(){
    freopen("P1141.txt","r",stdin);
    scanf("%s",key);
    int Len = strlen(key);
    for(int i = Len - 1 ; i >= 0 ; --i) Vis[key[i]-'A'] = true;
    Tn = 0;
    for(int i = 0 ; i < Len ; ++i)
        Trans[Tn++] = key[i] - 'A';
    for(int i = 25 ; i >= 0 ; --i)
        if(!Vis[i]) Trans[Tn++] = i;
    for(int i = 0 ; i < Tn ; ++i){
        //printf("%c",'A'+Trans[i]);
        RevT[Trans[i]] = i;
    }
    //printf("\n");
    scanf("%*c");
    while(~scanf("%c",&ch)){
        //printf("%c->",ch);
        if(ch >= 'A' && ch <= 'Z'){
            ch = RevT[ch - 'A'] + 'A';
        }
        if(ch >= 'a' && ch <= 'z'){
            ch = RevT[ch - 'a'] + 'a';
        }
        printf("%c",ch);
    }
    if(ch != '\n') printf("\n");
    return 0;
}


