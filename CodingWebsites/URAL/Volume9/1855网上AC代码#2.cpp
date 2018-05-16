#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;   
long long s[2000000][3],delt[2000000][3],t[2000000],ans[3];  
int n,m,m1,high;  
char ch[20000];  
void origin()  
{  
    for (m1=1,high=0;m1<=n+2;m1<<=1,high++) ;  
    for (int i=1;i<=n;i++) delt[i+m1][0]=1,delt[i+m1][1]=(i),delt[i+m1][2]=((long long)i)*(i);  
    for (int i=m1-1;i>=1;i--) {  
        int l=i<<1,r=l+1;  
        delt[i][0]=delt[l][0]+delt[r][0];  
        delt[i][1]=delt[l][1]+delt[r][1];  
        delt[i][2]=delt[l][2]+delt[r][2];  
    }  
}  
void change(int x,long long d)  
{  
    t[x]+=d;  
    s[x][0]+=delt[x][0]*d;  
    s[x][1]+=delt[x][1]*d;  
    s[x][2]+=delt[x][2]*d;  
}  
void pushdown(int x)  
{  
    for (int i=high-1;i>=0;i--) {  
        int ne=x>>i;  
        if (t[ne]) {  
            change(ne<<1,t[ne]);  
            change((ne<<1)+1,t[ne]);  
            t[ne]=0;  
        }  
    }  
}  
void updata(int x)  
{  
    for (;x;x>>=1) {  
        s[x][0]=s[x<<1][0]+s[(x<<1)+1][0];  
        s[x][1]=s[x<<1][1]+s[(x<<1)+1][1];  
        s[x][2]=s[x<<1][2]+s[(x<<1)+1][2];  
    }  
}  
void modify(int l,int r,long long d)  
{  
    if (l>r) return ;  
    l+=m1-1,r+=m1+1;  
    int ll=l>>1,rr=r>>1;  
    pushdown(ll),pushdown(rr);  
    for (;!((l^r)==1);l>>=1,r>>=1) {  
        if ((l&1)==0) change(l+1,d);  
        if ((r&1)==1) change(r-1,d);  
    }  
    updata(ll),updata(rr);  
}  
void ask(int l,int r,long long ans[3])  
{  
    ans[0]=ans[1]=ans[2]=0;  
    if (l>r) return ;  
    l+=m1-1,r+=m1+1;  
    int ll=l>>1,rr=r>>1;  
    pushdown(ll),pushdown(rr);  
    for (;!((l^r)==1);l>>=1,r>>=1) {  
        if ((l&1)==0) {  
            ans[0]+=s[l+1][0];  
            ans[1]+=s[l+1][1];  
            ans[2]+=s[l+1][2];  
        }  
        if ((r&1)==1) {  
            ans[0]+=s[r-1][0];  
            ans[1]+=s[r-1][1];  
            ans[2]+=s[r-1][2];  
        }  
    }  
}  
int main()  
{  
    freopen("1855.txt","r",stdin); 
    scanf("%d%d\n",&n,&m);  
    origin();  
    for (int i=1;i<=m;i++) {  
        scanf("%s",ch+1);  
        if ('c'==ch[1]) {  
            int l,r,d;  
            scanf("%d%d%d\n",&l,&r,&d);  
            modify(l+1,r,d);  
            /*printf("%lld\n",(r+l+1)*ans[1]-ans[2]-(l+l*r)*ans[0]); 
            printf("%lld %lld %lld\n\n",ans[0],ans[1],ans[2]);*/  
        }  
        else {  
            int l,r;  
            scanf("%d%d\n",&l,&r);  
            ask(l+1,r,ans);  
            long long sum=((long long)r-l+1)*((long long)r-l)/2;  
//          printf("%lld\n",(r+l+1)*ans[1]-ans[2]-(l+l*r)*ans[0]);   
//          printf("%lld %lld %lld\n",ans[0],ans[1],ans[2]);   
            if (sum) printf("%.10lf\n",((double)((long long)r+l+1)*ans[1]-ans[2]-((long long)l+((long long)l)*r)*ans[0])/sum);  
            else printf("%.10lf\n",0.0);  
        }  
    }  
    /*ask(2,2,ans); 
    printf("%lld %lld %lld\n",ans[0],ans[1],ans[2]);*/  
    return 0;  
}  








