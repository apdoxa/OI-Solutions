// BFS（或DFS）+ 连通块标记 + 记忆化
#include <bits/stdc++.h>
using namespace std;
int n, m;
int g[1001][1001];
int compent[1001][1001];
int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int compent_idx = 0;
unordered_map<int, int> com_size;
void bfs(int x, int y, int com_idx)
{
	queue<pair<int, int>> q;
	int cnt = 0;
	q.push({x, y});
	compent[x][y] = com_idx;
	cnt++; // 计入首块

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dirs[i][0];
			int ny = y + dirs[i][1];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
			{
				continue;
			}

			// 标号环节
			if (compent[nx][ny] != -1)
			{
				continue;
			}

			// 相邻数字不相同，则移动并标号
			if (g[x][y] != g[nx][ny])
			{
				compent[nx][ny] = com_idx;
				q.push({nx, ny});
				cnt++;
			}
		}
	}
	com_size[com_idx] = cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	memset(compent, -1, sizeof(compent));
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			g[i][j]=c-'0';

		}
	}
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			// 未标号格子
			if (compent[i][j] == -1)
			{
				compent_idx++;
				bfs(i, j, compent_idx);
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		//0-based
		cout << com_size[compent[x-1][y-1]]<<'\n';
	}

	queue<pair<int, int>> q;
	q.push({0, 0});

	return 0;
}