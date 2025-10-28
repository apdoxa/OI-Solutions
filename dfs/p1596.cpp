#include <bits/stdc++.h>
using namespace std;
int n, m;
int cnt = 0;
bool g[101][101];
int vist[101][101];
void dfs(int x, int y)
{

	// 注意边界，0-based index
	if (x < 0 || y < 0 || x >= n || y >= m)
		return ; // 不存在的点
	//不是水或已访问
	if (!g[x][y] || vist[x][y])
		return;
	vist[x][y] = true;

	//连通的水塘都会被标记
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
	dfs(x + 1, y + 1);
	dfs(x + 1, y - 1);
	dfs(x - 1, y + 1);
	dfs(x - 1, y - 1);
		
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == '.')
				g[i][j] = false;
			else if (c == 'W')
				g[i][j] = true;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (g[i][j]&&!vist[i][j])
				cnt++;
				dfs(i, j);
		}
	}

	cout << cnt << '\n';

	return 0;
}