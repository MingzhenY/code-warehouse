//总排名N或每组n/2
#include<cstdio>
#include <algorithm>
using namespace std;
struct pr
{
    int m,f;//序号，分数
}a[100002],b[100002];

int cmp(pr x,pr y)
{
    return x.f<y.f;//升序
}
int ans1[200001],ans2[200001];
int main()
{
    int n;
    scanf("%d",&n);
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].f,&b[i].f);
        a[i].m=i;b[i].m=i;
        ans1[i]=0;ans2[i]=0;
    }
    sort(a+1,a+n+1,cmp);sort(b+1,b+n+1,cmp);
    for(i=1;i<=n/2;i++)
    {
       ans1[ a[i].m ]=1;ans2[ b[i].m ]=1;
    }
    j=1;k=1;
    for(i=1;i<=n;i++)
    {
        if(a[j].f<b[k].f)
        {
            ans1[a[j].m]=1;j++;
        }
        else
        {
            ans2[b[k].m]=1;k++;
        }
    }
    for(i=1;i<=n;i++)
        if(ans1[i]==1)  printf("1");
        else    printf("0");
    printf("\n");
    for(i=1;i<=n;i++)
        if(ans2[i]==1)  printf("1");
        else    printf("0");
    return 0;
}
