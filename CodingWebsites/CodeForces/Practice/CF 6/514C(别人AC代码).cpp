#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <conio.h>

using namespace std;

#pragma comment (linker, "/STACK:64000000")

#define pb push_back
#define pii pair<int, int>
#define pdi pair<double, int>
#define pdii pair<pdi, int>
#define pll pair<ll, ll>
#define pib pair<int, bool>
#define pli pair<ll, int>
#define vi vector<int>
#define inf 2000000000
#define mod2 1000000007
#define mod1 536870911
#define y1 uhgeg
#define eps 1e-9
#define prime 5
#define N 100001
#define y0 tjlhkm

typedef long long ll;
typedef unsigned long long ull;

int n, m, l, j, i, h, k, q1, q2, q, t, v;
char buf[600005];
vector <pii> p;
ll pows1[600005], pows2[600005], hash1[600006], hash2[600005], res1, res2;
pii r;

void calc_hash()
{
	hash1[0] = hash2[0] = buf[0] - 'a' + 1;
	for (i = 1; buf[i]; i++)
	{
		hash1[i] = hash1[i - 1] * prime + (buf[i] - 'a' + 1);
		while (hash1[i] >= mod1)
		{
			hash1[i] -= mod1;
		}
		hash2[i] = hash2[i - 1] * prime + (buf[i] - 'a' + 1);
		while (hash2[i] >= mod2)
		{
			hash2[i] -= mod2;
		}
	}
	l = i;
}

pii get_hash(int pos, char c)
{
	res1 = res2 = 0LL;
	if (pos)
	{
		res1 += (hash1[pos - 1]) * (pows1[l - pos]) % mod1;
		res2 += (hash2[pos - 1]) * (pows2[l - pos]) % mod2;
	}
	res1 += (c - 'a' + 1) * pows1[l - pos - 1];
	res2 += (c - 'a' + 1) * pows2[l - pos - 1];
	res1 += mod1 + (hash1[l - 1]) - ((hash1[pos]) * (pows1[l - pos - 1])) % mod1;
	res2 += mod2 + (hash2[l - 1]) - ((hash2[pos]) * (pows2[l - pos - 1])) % mod2;
	while (res1 >= mod1)
	{
		res1 -= mod1;
	}
	while (res2 >= mod2)
	{
		res2 -= mod2;
	}
	return pii(res1, res2);
}

void solve()
{
	pows1[0] = pows2[0] = 1;
	for (j = 1; j <= 600000; j++)
	{
		pows1[j] = pows1[j - 1] * prime;
		while (pows1[j] >= mod1)
		{
			pows1[j] -= mod1;
		}
		pows2[j] = pows2[j - 1] * prime;
		while (pows2[j] >= mod2)
		{
			pows2[j] -= mod2;
		}
	}
	scanf ("%d%d\n", &n, &m);
	for (j = 1; j <= n; j++)
	{
		scanf ("%s\n", &buf);
		calc_hash();
		p.pb(pii(hash1[l - 1], hash2[l - 1]));
	}
	sort (p.begin(), p.end());
	for (j = 1; j <= m; j++)
	{
		scanf ("%s\n", &buf);
		calc_hash();
		bool yes = 0;
		for (i = 0; buf[i] && !yes; i++)
		{
			for (char c = 'a'; c <= 'c'; c++)
			{
				if (buf[i] == c)
				{
					continue;
				}
				r = get_hash(i, c);
				if (p.back() < r)
				{
					continue;
				}
				q1 = 0;
				q2 = p.size() - 1;
				while (q1 < q2)
				{
					q = (q1 + q2) >> 1;
					if (p[q] >= r)
					{
						q2 = q;
					}
					else
					{
						q1 = q + 1;
					}
				}
				if (p[q1] == r)
				{
					yes = 1;
					break;
				}
			}
		}
		if (yes)
		{
			printf ("YES\n");
		}
		else
		{
			printf ("NO\n");
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("514C.txt", "r", stdin); //freopen("output.txt", "wt", stdout);
	solve();
	return 0;
}
