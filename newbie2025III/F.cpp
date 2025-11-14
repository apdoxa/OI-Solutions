#include <bits/stdc++.h>
using namespace std;
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	bool fd = false;
	int target;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == k) {
			fd = true;
			break;
		} else if ((a[i] &k) == k) {
			q.push(a[i]);
			target=a[i];
		}
	}
	if (fd) {
		cout << "YES\n";
		return 0;
	}
	while (!q.empty()) {
		target &= q.front();
		q.pop();
		if (target == k) {
			break;
		}
	}
	if (target == k) {
		cout << "YES\n";
		return 0;
	} else {
		cout << "NO\n";
		return 0;
	}

	
}
