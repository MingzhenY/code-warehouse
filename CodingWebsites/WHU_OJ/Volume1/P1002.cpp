#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool IsHead(char *p,int len){
    if(len<3||len>4) return 0;
    return isdigit(p[0])&&(p[1]==':')&&isdigit(p[2])&&(len==3 || isdigit(p[3]));
}
void PrintWord(char *p,int len){
    for(int i=0;i<len;++i) cout<<p[i];
    cout<<" ";
}

int main(){
    char ch;
    char Word[128];
    int Length=0,Count = 0,First=1;
    freopen("P1002.txt","r",stdin);
    while(~(ch=getchar())){
        if(Length){//if in a word
            if(ch!=' ' && ch!='\n') Word[Length++]=ch;
            else{
                //Word[0~Length] is a word
                if(IsHead(Word,Length)){
                    if(First) First = 0;
                    else{
                        cout<<Count<<endl;
                        Count=0;
                    }
                    PrintWord(Word,Length);
                }
                else Count++;
                Length = 0;
            }
        }
        else{//if not in a word
            if(!isalnum(ch)) continue;
            Word[Length++]=ch;
        }
    }
    if(Count) {
                    cout<<Count<<endl;
                    Count=0;
                }
    
    return 0;
}


