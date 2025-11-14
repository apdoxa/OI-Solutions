#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<ll> a(n), c(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> c[i];
		}
		vector<ll> dp(n);
		ll tol = 0;
		for (int i = 0; i < n; i++) {
			dp[i] = c[i];
			tol += c[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[j] <= a[i]) {
					if (dp[j] + c[i] > dp[i]) {
						dp[i] = dp[j] + c[i];
					}
				}
			}
		}

		ll maxx = 0;
		for (int i = 0; i < n; i++) {
			maxx = max(dp[i], maxx);
		}
		cout << tol - maxx << endl;
	}
	return 0;
}

