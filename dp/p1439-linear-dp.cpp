// TODO: review LCS to LIS O(nlogn)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];

//
int lis_solution()
{
	int n;
	int mmap[N];
	int sqe[N];
	int dp[N];
	memset(mmap, 0x80, sizeof(mmap));
	memset(dp, 0x80, sizeof(mmap)); // 初始化
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (size_t i = 0; i < n; i++)
	{
		cin >> b[i];
		mmap[b[i]] = i;
	}
	// 将a数组数值映射到b数组索引
	for (size_t i = 0; i < n; i++)
	{
		a[i] = mmap[a[i]]; 
	}

	// lis 求解
	int len = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i] > dp[len])
		{
			dp[++len] = a[i]; // 位置大了放后面
		}
		else
		{
			// 末尾比a->index(b[i])的位置大，找出第一个大于等于a->index(b[i])的位置，放进去，从而实现往小了优化序列
			*lower_bound(dp, dp + len + 1, a[i]) = a[i];
		}
	}
	cout << len << '\n';

	return 0;
}
// 爆内存解法
int n2_solution()
{
	int f[N][N];
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;

	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (size_t i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	f[0][n] = 0;
	f[n][0] = 0;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (a[i] == b[j])
			{
				f[i][j] = f[i - 1][j - 1] + 1;
			}
			else
			{
				f[i][j] == max(f[i - 1][j], f[i][j - 1]);
			}
		}
	}
	cout << f[n - 1][n - 1] << '\n';

	return 0;
}
int main()
{
	return lis_solution();
}