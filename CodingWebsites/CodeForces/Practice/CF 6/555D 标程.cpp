#include <bits/stdc++.h>
#define sc second
#define fs first

using namespace std;

const int MAXN = 200500;

int main()
{freopen("555D.txt","r",stdin); 
    int n, m;
    scanf("%d%d", &n, &m);
    pair<int, int> b[MAXN];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i].fs);
        b[i].sc = i;
    }
    sort(b, b + n);
    int u[MAXN];
    for (int i = 0; i < n; i++)
        u[b[i].sc] = i;
    int x[MAXN];
    for (int i = 0; i < n; i++)
        x[i] = b[i].fs;
    int k, k1, dis, d, p, l, dir;
    for (int j = 0; j < m; j++)
    {
        scanf("%d%d", &p, &d);
        k = u[p - 1];
        dir = 1;
        dis = x[k] + d * dir;
        k1 = upper_bound(x, x + n, dis) - x - 1;
        d -= abs(x[k] - x[k1]);
        k = k1;
        dir *= -1;
        for ( ; ; )
        {
            dis = x[k] + d * dir;
            if (dir == 1)
                k1 = upper_bound(x, x + n, dis) - x - 1;
            else
                k1 = lower_bound(x, x + n, dis) - x;
            if (k == k1)
                break;
            l = abs(x[k] - x[k1]);
            if ((d / l) % 2 == 1)
            {
                dir *= -1;
                k = k1;
            }
            d = d % l;
        }
        printf("%d\n", b[k].sc + 1);
    }
    return 0;
}
