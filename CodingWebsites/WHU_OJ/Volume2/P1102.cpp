#include<cstdio>
#include<iostream>
/*
 改成大数类就可以提交了
 需要乘法，加法，次方，求余
 */
using namespace std;


typedef long long ll;

ll power(ll a,ll b)
{
    ll ans=1ll;
    while(b)
    {
        if(b&1)
            ans=ans*a;
        a=a*a;
        b=b>>1;
    }
    return ans;
}
ll gcd(ll a,ll b)
{
    return b ? gcd(b,a%b)  :  a;
}
int main()
{
    freopen("P1102.txt","r",stdin);
    int c,s;
    ll ans;
    while(~scanf("%d%d",&c,&s) && c && s)
    {
        if(s&1)
            ans=power(c,s/2+1)*s;
        else
            ans=power(c,s/2)*(s/2)+power(c,s/2+1)*(s/2);
        for(int i=1;i<=s;i++)
            ans+=power(c,gcd(s,i));
        printf("%lld\n",(ans/2)/s);
    }
    return 0;
}

