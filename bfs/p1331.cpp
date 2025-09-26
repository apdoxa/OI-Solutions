//TODO : review
#include <bits/stdc++.h>
using namespace std;
int r, c;
bool g[1005][1005];
bool v[1005][1005];
const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			char s;
			cin >> s;
			if (s == '.')
			{
				g[i][j] = false;
			}
			else if (s == '#')
			{
				g[i][j] = true;
			}
		}
	}

	int ship = 0;
	bool valid = true;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (g[i][j] && !v[i][j])
			{
				// 扫描连通块
				// 初始化矩阵坐标范围
				int mx_x = i, mn_x = i;
				int mx_y = j, mn_y = j;
				queue<pair<int, int>> q;
				q.push({i, j});
				v[i][j] = true;

				while (!q.empty())
				{
					// bfs
					int x = q.front().first;
					int y = q.front().second;

					mx_x = max(x, mx_x);
					mn_x = min(x, mn_x);
					mx_y = max(y, mx_y);
					mn_y = min(y, mn_y);

					q.pop();
					v[x][y] = true;
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dirs[k][0];
						int ny = y + dirs[k][1];
						if(!valid)break;
						// check
						if (nx < 0 || ny < 0 || nx >= r || ny >= c || v[nx][ny]||!g[nx][ny])
						{
							continue;
						}
						else
						{
							v[nx][ny] = true;
							q.push({nx, ny});
						}
					}
				}
				// 扫描矩阵，有水格子即判错
				for (int dx = mn_x; dx <= mx_x; dx++)
				{
					for (int dy = mn_y; dy <= mx_y; dy++)
					{
						if (!g[dx][dy])
						{
							valid = false;
							break;
						}
					}
					if (!valid)
					{
						break;
					}
				}
				if (valid)
				{
					ship++;
				}
			}
		}
	}

	if (valid)
	{
		cout << "There are " << ship << " ships." << endl;
	}
	else
	{
		cout << "Bad placement." << endl;
	}

	return 0;
}