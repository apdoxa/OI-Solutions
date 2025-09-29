#include <bits/stdc++.h>
using namespace std;
int dp[1005][35] = {0}; // x->time y->steps
// y%2==0->1 y%2!=0->2
bool tree[1005]; // false->2 true->1
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t, w;
	cin >> t >> w;
	for (size_t i = 1; i <= t; i++)
	{
		int x;
		cin >> x;

		if (x == 1)
		{
			tree[i] = true;
		}
		else if (x == 2)
		{
			tree[i] = false;
		}
	}

	// 初始化 第0分钟未移动
	for (size_t j = 1; j <= w; j++)
	{
		dp[0][j] = INT32_MIN;
	}

	// 时间迭代模拟
	for (size_t i = 1; i <= t; i++)
	{
		for (size_t j = 0; j <= w; j++)
		{
			// 走 or 不走
			// false->1 true->2
			// 接到
			int max_perv = max(dp[i - 1][j], dp[i - 1][j - 1]);
			int add = tree[i] == (j % 2 == 0) ? 1 : 0;
			dp[i][j] = add + max_perv;
		}
	}

	int ans = 0;
	for (int j = 0; j <= w; ++j)
	{
		ans = max(ans, dp[t][j]);
	}
	cout << ans << '\n';

	return 0;
}