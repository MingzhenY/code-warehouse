#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define  inf  0x1fffffff
#define out(i) <<#i<<"="<<(i)<<"  "
#define OUT1(a1) cout out(a1) <<endl
#define OUT2(a1,a2) cout out(a1) out(a2) <<endl
#define OUT3(a1,a2,a3) cout out(a1) out(a2) out(a3)<<endl
#define maxn 2000000
using namespace std;
int maxprime[maxn+7];
int f[maxn+7];
void Init(){
    memset(maxprime,-1,sizeof(maxprime));
    maxprime[1]=1;
    for(int i=2;i<=maxn;++i){
        if(~maxprime[i]) continue;
        for(int j=i;j<=maxn;j+=i) maxprime[j]=i;
    }
    f[1]=1;f[2]=2;
    for(int i=3;i<=maxn;++i){
        int X=i;
        int P=maxprime[X],D=1;
        while(X>1&&X%P==0) D++,X/=P;
        f[i]=D*f[X];
    }
}
int A[maxn+7];
int N[100007];
int Pre[maxn+7];
int main()
{
    ios::sync_with_stdio(0);
    Init();
    for(int i=1;i<=maxn;++i) A[i]=1,Pre[i]=-1;
    int MaxN=1,MaxI=1;
    for(int i=3;i<=maxn;++i){
        if(f[i]<=300){
            if(A[i-f[i]]>=A[i]){
                A[i]=A[i-f[i]]+1;
                Pre[i]=i-f[i];
            }
            if(MaxN<100000&&A[i]>MaxN){
                MaxN=A[i];
                MaxI=i;
            }
        }
    }
    int IP=0;
    int X=MaxI;
    while(~Pre[X]){
        N[IP++]=X-Pre[X];
        X=Pre[X];
    }
    N[IP++]=X;
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        if(i^1) cout<<" ";
        cout<<N[100000-i];
    }
    cout<<endl;
    return 0;
}








