#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	int ans = 0;
	int psum = 0, nsum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			psum = psum + m,nsum = nsum + m;
		} else {
			nsum -= a[i];
			psum += a[i];
		}
		ans = max({ans, psum, nsum});
		//过程中最大
	}

	cout << ans << '\n';
	return 0;
}
