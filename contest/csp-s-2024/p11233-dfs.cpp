#include <bits/stdc++.h>
using namespace std;
long long max_score = 0;
int n;
vector<int> a;
void dfs(int pos, int lastr, int lastb, long long cur_score) {
	if (pos == n) {
		max_score = max(cur_score, max_score);
		return;
	}
	//红

	if (lastr != -1 && a[lastr] == a[pos]) {
		dfs(pos + 1, pos, lastb, cur_score + a[lastr]);
	} else {
		dfs(pos + 1, pos, lastb, cur_score);
	}


	if (lastb != -1 && a[lastb] == a[pos]) {
		dfs(pos + 1, lastr, pos, cur_score + a[lastb]);
	} else {
		dfs(pos + 1, lastr, pos, cur_score );
	}

	//蓝
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		a=vector<int>(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		dfs(0, -1, -1, 0);
		cout << max_score << '\n';
		max_score = 0;
	}
	return 0;
}
