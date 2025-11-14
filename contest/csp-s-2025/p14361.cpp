#include <bits/stdc++.h>
using namespace std;
struct ms
{
	int v[3]; // 三部门满意度
};
void solve()
{
	int n;
	cin >> n;
	vector<ms> arr(n), club[3];
	int sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		int mxidx = 0;
		for (size_t j = 0; j < 3; j++)
		{
			cin >> arr[i].v[j];
			if (arr[i].v[j] > arr[i].v[mxidx])
			{
				mxidx = j;
			}
		}
		sum += arr[i].v[mxidx];
		club[mxidx].push_back(arr[i]);
	}

	int target = -1;
	for (int i = 0; i < 3; i++)
	{
		if (club[i].size() > n / 2)
			target = i; // 找出那一个超过要求的数列
	}
	// 从大到小排序
	// 计算代价
	if (target != -1)
	{
		vector<int> costs(club[target].size());

		//最小更换代价
			vector<int> cost;
			for (int i = 0; i < club[target].size(); i++) {
				ms mmb = club[target][i];
				int mincost = INT32_MAX;
				for (int j = 0; j < 3; j++) {
					if (j == target) {
						continue;
					}
					if (mmb.v[target] - mmb.v[j] < mincost) {
						mincost = mmb.v[target] - mmb.v[j];
					}
				}
				cost.push_back(mincost);
			}
		sort(costs.begin(), costs.end());
		for (size_t i = 0; i < club[target].size() - (n / 2); i++)
		{
			sum -= costs[i];
		}
	}
	cout << sum << '\n';
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}