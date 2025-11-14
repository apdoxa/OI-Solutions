//review
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	int n;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		map<int, int> f;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			f[a[i]]++;
		}
		int m = (n - 1) / 2;
		int s = 0;
		for (auto& p : f) {
			s += p.second / 2;
		}
		cout << (s >= m ? "YES" : "NO") << endl;
	}
	return 0;
}

