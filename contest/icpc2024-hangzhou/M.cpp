#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int n;
		long long k;
		cin >> n >> k;
		vector<long long> b(n);
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
		}
		//min_element O(N)
		long long min_b = *min_element(b.begin(), b.end());
		vector<long long> c(n);
		vector<long long> S;
		for (int i = 0; i < n; ++i) {
			c[i] = b[i] - min_b;
			if (c[i] > 0) {
				S.push_back(c[i]);
			}
		}
		if (S.empty()) {
			long long count = k;
			long long sum_x = k * (k + 1) / 2;
			cout << count << " " << sum_x << "\n";
			continue;
		}
		long long G = S[0];
		for (size_t i = 1; i < S.size(); ++i) {
			G = gcd(G, S[i]);
			if (G == 1) break;
		}
		set<long long> divisors;
		for (long long i = 1; i * i <= G; ++i) {
			if (G % i == 0) {
				divisors.insert(i);
				divisors.insert(G / i);
			}
		}
		long long A = min_b + 1;
		long long B = min_b + k;
		vector<long long> valid_x;
		for (long long d : divisors) {
			if (d < A || d > B) {
				continue;
			}
			bool ok = true;
			for (int i = 0; i < n - 1; ++i) {
				long long ci = c[i];
				long long cj = c[i + 1];
				long long mi = (ci / d) + 1;
				long long mj = (cj / d) + 1;
				if (mi == mj) continue;
				if (mi < mj) {
					if (mj % mi != 0) {
						ok = false;
						break;
					}
				} else {
					if (mi % mj != 0) {
						ok = false;
						break;
					}
				}
			}
			if (ok) {
				valid_x.push_back(d - min_b);
			}
		}
		long long count = valid_x.size();
		long long sum_x = 0;
		for (long long x : valid_x) {
			sum_x += x;
		}
		cout << count << " " << sum_x << "\n";
	}
	return 0;
}
