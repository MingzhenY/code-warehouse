#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int N,k;
char str1[10001],str2[10001];
int Dif[10001];
int main(){
    freopen("P1288.txt","r",stdin);
    scanf("%d",&N);
    while(N--){
        scanf("%s%s%d",str1,str2,&k);
        int len=strlen(str1),ans=0;
        for(int i=0;i<len;++i) ans+=Dif[i]=str1[i]>str2[i]?str1[i]-str2[i]:str2[i]-str1[i];
        sort(Dif,Dif+len);
        for(int i=1;i<=k;++i) ans-=Dif[len-i]-!Dif[len-i];
        printf("%d\n",ans);
    }
    return 0;
}


