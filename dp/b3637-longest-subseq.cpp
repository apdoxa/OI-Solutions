#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int a[N];
int dp[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	// 初始化极小值
	// memset(dp, 0x80, sizeof(dp));
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int len = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (len == 0 /*放入第一个元素*/ || a[i] > dp[len])
		{
			dp[++len] = a[i]; // 动态扩充长度
		}
		else
		{
			// 小了的话，在现有序列的前面找第一个大于等于的元素替换进去
			*lower_bound(dp, dp + len + 1, a[i]) = a[i];
		}
	}

	cout << len << '\n';

	return 0;
}