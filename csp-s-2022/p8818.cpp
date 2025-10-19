//TODO:fix 40pts code
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ftx(i, x) for (int i = 1; i <= x; i++)
const int MAXN = 1e5 + 10;
ll LOGN[MAXN + 1];
ll stamax[MAXN][15];
ll stamin[MAXN][15];
ll stbmin[MAXN][15];
ll stbmax[MAXN][15];

void pre()
{
	LOGN[1] = 0;
	LOGN[2] = 1;
	for (size_t i = 3; i <= MAXN; i++)
	{
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
		cin >> stamax[i][0];
		stamin[i][0] = stamax[i][0];
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
			stamax[j][i] = max(stamax[j][i - 1], stamax[j + (1ULL << (i - 1))][i - 1]);
			stamin[j][i] = min(stamin[j][i - 1], stamin[j + (1ULL << (i - 1))][i - 1]);
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
		ll xmx = max(stamax[l1][len1], stamax[r1 - (1ULL << len1) + 1][len1]);
		ll xmi = min(stamin[l1][len1], stamin[r1 - (1ULL << len1) + 1][len1]);
		ll ymx = max(stbmax[l2][len2], stbmax[r2 - (1ULL << len2) + 1][len2]);
		ll ymi = min(stbmin[l2][len2], stbmin[r2 - (1ULL << len2) + 1][len2]);
		
		ll ans=(ll)(INT64_MIN);

		//x最大值为非负数
		if(xmx>=0){
			ll c1=xmx*(xmx>=0?ymi:ymx);
			ans=max(ans,c1);
		}
		//x最小值为负数
		if(xmi<0){
			ll c2=xmi*(xmi>=0?ymi:ymx);
			ans=max(ans,c2);
		}
		if(xmx==0||ymi==0){
			ans=max(ans,0LL);
		}
		cout<<ans<<'\n';
	}

	return 0;
}