// TODO:fix 40pts code
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ftx(i, x) for (int i = 1; i <= x; i++)
const int MAXN = 1e5 + 10;
ll LOGN[MAXN + 1];
// a正数最值st
ll sta_pomax[MAXN][15];
ll sta_pomin[MAXN][15];
// a负数最值st
ll sta_ngmax[MAXN][15];
ll sta_ngmin[MAXN][15];
// b最值st
ll stbmin[MAXN][15];
ll stbmax[MAXN][15];

vector<int> zero_A;
void pre()
{
	LOGN[1] = 0;
	sta_ngmax[1][0] = INT64_MIN;
	sta_ngmin[1][0] = INT64_MIN;
	sta_pomax[1][0] = INT64_MAX;
	sta_pomin[1][0] = INT64_MAX;
	LOGN[2] = 1;
	sta_ngmax[2][0] = INT64_MIN;
	sta_ngmin[2][0] = INT64_MIN;
	sta_pomax[2][0] = INT64_MAX;
	sta_pomin[2][0] = INT64_MAX;
	for (size_t i = 3; i <= MAXN; i++)
	{
		sta_ngmax[i][0] = INT64_MIN;
		sta_ngmin[i][0] = INT64_MIN;
		sta_pomax[i][0] = INT64_MAX;
		sta_pomin[i][0] = INT64_MAX;
		LOGN[i] = LOGN[i / 2] + 1;
	}
}

// greedy,linear-tree st
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	ll n, m, q;

	// pre calc logn
	pre();
	cin >> n >> m >> q;
	ftx(i, n)
	{
		ll x;
		cin >> x;
		if (x < 0)
		{
			sta_ngmax[i][0] = x;
			sta_ngmin[i][0] = x;
		}
		else if (x > 0)
		{
			sta_pomax[i][0] = x;
			sta_pomin[i][0] = x;
		}
		else
		{
			 zero_A.push_back(i);

			// 均记为无效值
			sta_pomax[i][0] = INT64_MIN;
			sta_pomin[i][0] = INT64_MAX;

			sta_ngmax[i][0] = INT64_MIN;
			sta_ngmin[i][0] = INT64_MAX;
		}
	}
	ftx(i, m)
	{
		cin >> stbmin[i][0];
		stbmax[i][0] = stbmin[i][0];
	}
	// sta->x max
	ftx(i, LOGN[n] + 1)
	{
		for (int j = 1; j + (1ULL << i) - 1 <= n; j++)
		{
			sta_pomax[j][i] = max(sta_pomax[j][i - 1], sta_pomax[j + (1ULL << (i - 1))][i - 1]);
			sta_pomin[j][i] = min(sta_pomin[j][i - 1], sta_pomin[j + (1ULL << (i - 1))][i - 1]);

			sta_ngmax[j][i] = max(sta_ngmax[j][i - 1], sta_ngmax[j + (1ULL << (i - 1))][i - 1]);
			sta_ngmin[j][i] = min(sta_ngmin[j][i - 1], sta_ngmin[j + (1ULL << (i - 1))][i - 1]);
		}
	}
	// stb->y min
	ftx(i, LOGN[m] + 1)
	{
		for (int j = 1; j + (1ULL << i) - 1 <= m; j++)
		{
			stbmax[j][i] = max(stbmax[j][i - 1], stbmax[j + (1ULL << (i - 1))][i - 1]);
			stbmin[j][i] = min(stbmin[j][i - 1], stbmin[j + (1ULL << (i - 1))][i - 1]);
		}
	}
	ftx(op, q)
	{
		ll l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		int soc[4] = {0};
		int len1 = LOGN[r1 - l1 + 1];
		int len2 = LOGN[r2 - l2 + 1];

		ll xpo_mx = max(sta_pomax[l1][len1], sta_pomax[r1 - (1ULL << len1) + 1][len1]);
		ll xpo_mi = min(sta_pomin[l1][len1], sta_pomin[r1 - (1ULL << len1) + 1][len1]);

		ll xng_mx = max(sta_ngmax[l1][len1], sta_ngmax[r1 - (1ULL << len1) + 1][len1]);
		ll xng_mi = min(sta_ngmin[l1][len1], sta_ngmin[r1 - (1ULL << len1) + 1][len1]);

		ll ymx = max(stbmax[l2][len2], stbmax[r2 - (1ULL << len2) + 1][len2]);
		ll ymi = min(stbmin[l2][len2], stbmin[r2 - (1ULL << len2) + 1][len2]);

		bool has_zero = false;
		if (!zero_A.empty())
		{
			auto it = lower_bound(zero_A.begin(), zero_A.end(), l1);
			if (it != zero_A.end() && *it <= r1)
				has_zero = true;
		}

		ll ans = INT64_MIN;

		// x最大值为非负数，且存在
		// x>0 x*ymi->xpo_mx,xpo_mi
		if (xpo_mx != INT64_MAX)
		{
			if (ymi > 0)
			{
				ll c1 = xpo_mx * ymi;
				ans = max(ans, c1);
			}
			else if (ymi < 0)
			{
				ll c2 = xpo_mi * ymi;
				ans = max(ans, c2);
			}
			else
			{
				// ymi==0
				ans = max(ans, 0LL);
			}
		}

		if (xng_mx != INT64_MIN)
		{
			// x<0 x*ymx->xng_max,xng_min
			if (ymx > 0)
			{
				ll c3 = xng_mx * ymx;
				ans = max(ans, c3);
			}
			else if (ymx < 0)
			{
				ll c4 = xng_mi * ymx;
				ans = max(ans, c4);
			}
			else
			{
				ans = max(ans, 0LL);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}