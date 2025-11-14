#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(m, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[j][i];
			}
		}

		for (int i = 0; i < m; i++) {
			sort(a[i].begin(), a[i].end(),greater<int>());
		}
		bool va = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m ; j++) {
//				if (a[j][i] < a[j+1][i]) {
//					va = false;
//					break;
//				};
				cout<<a[j][i]<<' ';
			}
			cout<<'\n';
		}
		if (va) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}

	}

	return 0;
}
