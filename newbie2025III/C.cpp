#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int main() {
	const int N = 1e3+10;
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int g[N][N];
	//bfs
	queue<pii> q;
	bool v[N][N] = {0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			if (g[i][j] == 2) {
				v[i][j] = 1;
				q.push({i, j});
			};
		}
	}
	int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int sum = 0;
	while (!q.empty()) {
		pii f = q.front();
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = f.first + dir[d][0], ny = f.second + dir[d][1];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (g[nx][ny] == 0 && !v[nx][ny]) {

				v[nx][ny] = 1;
				sum += 1;
			}
		}
	}
	cout << sum << '\n';


	return 0;
}
