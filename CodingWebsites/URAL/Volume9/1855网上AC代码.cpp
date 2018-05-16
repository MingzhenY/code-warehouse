#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;  
  
#define LL(x) (x<<1)  
#define RR(x) (x<<1|1)  
#define MID(a,b) (a+((b-a)>>1))  
  
typedef long long LL;  
const int N=1e5+5;  
  
LL base[N][3];  
struct Segtree  
{  
    LL mult[N*4],sum[N*4],delay[N*4];  
    void fun(int ind,LL valu)  
    {  
        sum[ind]+=valu*mult[ind]; delay[ind]+=valu;  
    }  
    void PushUp(int ind)  
    {  
        sum[ind]=sum[LL(ind)]+sum[RR(ind)];  
    }  
    void PushDown(int ind)  
    {  
        if(delay[ind])  
        {  
            fun(LL(ind),delay[ind]);  
            fun(RR(ind),delay[ind]);  
            delay[ind]=0;  
        }  
    }  
    void build(int lft,int rht,int ind,int type)  
    {  
        mult[ind]=sum[ind]=delay[ind]=0;  
  
        if(lft==rht) mult[ind]=base[lft][type];  
        else  
        {  
            int mid=MID(lft,rht);  
            build(lft,mid,LL(ind),type);  
            build(mid+1,rht,RR(ind),type);  
  
            mult[ind]=mult[LL(ind)]+mult[RR(ind)];  
        }  
    }  
    void updata(int st,int ed,int dx,int lft,int rht,int ind)  
    {  
        if(st<=lft&&rht<=ed)  
        {  
            fun(ind,dx);  
        }  
        else  
        {  
            PushDown(ind);  
            int mid=MID(lft,rht);  
            if(st<=mid) updata(st,ed,dx,lft,mid,LL(ind));  
            if(ed> mid) updata(st,ed,dx,mid+1,rht,RR(ind));  
            PushUp(ind);  
        }  
    }  
    LL query(int st,int ed,int lft,int rht,int ind)  
    {  
        if(st<=lft&&rht<=ed) return sum[ind];  
        else  
        {  
            PushDown(ind);  
            int mid=MID(lft,rht);  
            LL sum1=0,sum2=0;  
            if(st<=mid) sum1=query(st,ed,lft,mid,LL(ind));  
            if(ed> mid) sum2=query(st,ed,mid+1,rht,RR(ind));  
            PushUp(ind);  
            return sum1+sum2;  
        }  
    }  
}seg[3];  
int main()  
{  
    freopen("1855.txt","r",stdin);  
    int n,m;  
    while(scanf("%d%d",&n,&m)!=EOF)  
    {  
        for(int i=1;i<=n;i++)  
        {  
            base[i][0]=1;  
            base[i][1]=(LL)i;  
            base[i][2]=(LL)i*(LL)i;  
        }  
        n--;  
        for(int i=0;i<3;i++) seg[i].build(1,n,1,i);  
  
        char buf[50];  
        int st,ed,valu;  
        while(m--)  
        {  
            scanf("%s",buf);  
            if(buf[0]=='c')  
            {  
                scanf("%d%d%d",&st,&ed,&valu);  
                for(int i=0;i<3;i++) seg[i].updata(st,ed-1,valu,1,n,1);  
            }  
            else  
            {  
                scanf("%d%d",&st,&ed);  
                LL a=-seg[2].query(st,ed-1,1,n,1);  
                LL b=seg[1].query(st,ed-1,1,n,1);  
                LL c=seg[0].query(st,ed-1,1,n,1);  
  
                //cout<<"a="<<a<<" b="<<b<<" c="<<c<<endl;  
  
                LL tmp=ed-st+1;  
                double ans=a+b*(st+ed-1)+c*ed*(1-st);  
                printf("%.15f\t",ans);  
                ans*=2;  
                ans/=(tmp);  
                ans/=(tmp-1);  
                printf("%.15f\n",ans);  
            }  
        }  
    }  
    return 0;  
}  








