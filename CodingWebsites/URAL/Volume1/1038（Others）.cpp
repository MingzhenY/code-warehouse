#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXD 100010
int N, cnt;
char b[MAXD];
char isend(char ch)
{
    return ch == '.' || ch == '?' || ch == '!';
}
void check(char ch, int &pat)
{
    if(pat == 0)
    {
        if(isalpha(ch))
        {
            if(islower(ch))
                ++ cnt;
            pat = 1;    
        }
    }
    else if(pat == 1)
    {
        if(isalpha(ch))
        {
            if(isupper(ch))
                ++ cnt;
        }
        else
        {
            if(isend(ch))
                pat = 0;
            else
                pat = 2;    
        }
    }
    else
    {
        if(isend(ch))
            pat = 0;
        else if(isalpha(ch))
            pat = 1;    
    }
}
void solve()
{
    int i, pat;
    cnt = 0, pat = 0;
    for(i = 0; i < N; i ++)
        check(b[i], pat);    
}
int main()
{freopen("1038.txt","r",stdin); 
    N = 0;
    while(scanf("%c", &b[N]) == 1)
        ++ N;
    solve();
    printf("%d\n", cnt);
    return 0;    
}
