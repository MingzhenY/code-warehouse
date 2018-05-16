#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 100009;

int st[MAXN][20];
int n, t;

map<int, int> pos;
vector<int> f[MAXN];

inline int  gcd (int x, int y) {
    return y == 0 ? x : gcd (y, x % y);
}

inline void ST() {
    for (int i = n - 1; i > 0; --i)
        for (int j = 1; i + (1 << j) <= n; j++)
            st[i][j] = gcd (gcd (st[i][j], st[i][j - 1]), st[i + (1 << j - 1)][j - 1]);
}
inline int getgcd (int l, int r) {
    int tem = st[l][0];
    for (int k = 0; l + (1 << k) <= r; k++)
        tem = gcd (gcd (tem, st[l][k]), st[r - (1 << k) + 1][k]);
    return tem;
}
int main() {
	freopen("474F.txt","r",stdin);
    ios::sync_with_stdio (0);
    cin >> n;
    int tol = 0;
    for (int i = 1; i <= n; i++)  {
        cin >> st[i][0];
        if (pos.find (st[i][0]) == pos.end() ) tol++, pos[st[i][0]] = tol;
        f[pos[st[i][0]]].push_back (i);
    }
    ST();
    cin >> t;
    for (int i = 1, l, r; i <= t; i++) {
        cin >> l >> r;
        int key = getgcd (l, r), k = pos[key];
        int d = upper_bound (f[k].begin(), f[k].end(), r) - lower_bound (f[k].begin(), f[k].end(), l);
        cout << r - l  - d +1<< endl;
    }
}
