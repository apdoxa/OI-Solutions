#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int p1[5] = {0, 1, 2, 3, 4};
	const pair<int, int> p2[4] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};

	int n;
	cin >> n;
	vector<string> states;
	unordered_map<string, int> mmap;
	for (int i = 0; i < n; i++)
	{
		int idx = 0;
		string cur(5, '0');
		while (idx < 5)
		{
			cin >> cur[idx];
			idx++;
		}
		states.push_back(cur);
	}
	for (const string &str : states)
	{
		set<string> gen;//每轮生成结果，使用set去重

		// 0-9选择一个
		for (size_t num = 1; num <= 9; num++)
		{
			for (size_t bit = 0; bit < 5; bit++)
			{
				string cur = str;
				cur[bit] = '0' + (cur[bit] - '0' + num) % 10;
				gen.insert(cur);

				cur = str;
				cur[bit] = '0' + (cur[bit] - '0' - num + 10) % 10;
				gen.insert(cur);
			}
		}
		// 1,2 2,3 3,4 4,5选择一个
		// 幅度
		for (size_t num = 1; num <= 9; num++)
		{
			for (size_t bit = 0; bit < 4; bit++)
			{
				int x = p2[bit].first;
				int y = p2[bit].second;

				string cur = str;
				cur[x] = '0' + (cur[x] - '0' + num) % 10;
				cur[y] = '0' + (cur[y] - '0' + num) % 10;
				gen.insert(cur);

				cur = str;
				cur[x] = '0' + (str[x] - '0' - num + 10) % 10;
				cur[y] = '0' + (cur[y] - '0' - num + 10) % 10;
				gen.insert(cur);
			}
		}

		for (const string &str : gen)
		{
			mmap[str]++;
		}
	}
	int sum = 0;
	for (pair<string, int> p : mmap)
	{
		if (p.second == n)
			sum++;
	}

	cout << sum << '\n';

	return 0;
}