/*
 哈希+二分，哈希的空间不够导致大量重复，无法解决问题。
 估计可以用前缀树+最近公共祖先(估计会超内存）
 后来看到可以用后缀数组+线段树（没看懂）
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define LL long long
#define maxn 1000007
using namespace std;
struct Node{
    int List[26];
    Node(){memset(List,0,sizeof(List));}
}node[maxn];
int TP;
void Build(){
    TP = 1;
}
int Add(char *str){
    int Cnt = 1;
    while(*str){
        int t = *str - 'a';
        if(node[Cnt].List[t]) Cnt = node[Cnt].List[t];
        else Cnt = node[Cnt].List[t] = ++TP;
        ++str;
    }
    return Cnt;
}
int ID[6007];
void Show(int id,int k,char ch){
    for(int i = 0 ; i < k ; ++i) printf("  ");
    printf("(%d,%c)\n",id,ch);
    for(int i = 0 ; i < 26 ; ++i){
        if(node[id].List[i]){
            Show(node[id].List[i],k+1,'a'+i);
        }
    }
}
int main(){
    freopen("P1043.txt","r",stdin);
    int n,id;
    char str[1024];
    scanf("%d",&n);
    Build();
    for(int i = 0 ; i < n ; ++i){
        scanf("%d%s\n",&id,str);
        ID[i] = Add(str);
    }
    Show(1,0,'!');
    int m,q,x,y;
    scanf("%d",&m);
    while(m-- >0){
        scanf("%d",&q);
        int ANS = 0;
        while(q-- > 0){
            scanf("%d%d",&x,&y);
            
        }
        printf("%d\n",ANS);
    }
    return 0;
}


