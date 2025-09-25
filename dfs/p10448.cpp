#include <bits/stdc++.h>
using namespace std;
int path[26];
int n, m;
void dfs(int start, int depth)
{
	if (depth == m)
	{
		// 选择m个后输出
		for (int i = 0; i < m; i++)
		{
			cout << path[i];
			if (i < m - 1)
				cout << ' ';
		}
		cout << '\n';
		return;
	}

	// start
	for (int i = start; i <= n; i++)
	{
		path[depth] = i;
		dfs(i + 1, depth + 1);
	}
}
int main()
{
	cin >> n >> m; // 1-n 1-based

	// 处理m=0的特殊情况
	if (m == 0)
	{
		cout << endl;
		return 0;
	}

	dfs(1, 0);

	return 0;
}