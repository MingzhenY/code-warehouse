#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
struct Node{
    char ch;
    int child[26];
    Node(char ch=0):ch(ch){memset(child,0,sizeof(child));}
}node[10001];
int NP,Root;
char str[201];

void AddAlpha(int &rt,char ch){
    if(!node[rt].child[ch]){
        node[++NP]=Node(ch);
        rt=node[rt].child[ch]=NP;
    }
    else rt=node[rt].child[ch];
}


int main(){
    freopen("P1013.txt","r",stdin);
    while(~scanf("%s",str)){
        int len=strlen(str);
        for(int i=0;i<len;++i) str[i]-='a';
        for(int i=(len<<1);i>=len;--i) str[i]=str[i-len];
        
        NP=0;
        node[0]=Node();
        
        for(int i=0;i<len;++i){
            Root = 0;
            for(int j=0;j<len;++j){
                AddAlpha(Root,str[i+j]);
            }
        }
        
        Root=0;
        for(int i=0;i<len;++i){
            for(int j=0;j<26;++j){
                if(node[Root].child[j]){
                    Root=node[Root].child[j];
                    printf("%c",node[Root].ch+'a');
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}


