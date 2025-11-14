#include <bits/stdc++.h>
#define ll long long
const int N = 1e6+10;
ll a[N], fl[N], fr[N];
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	fl[0] = a[0];
	for (int i = 1; i < n; i++) {
		fl[i] = max(fl[i - 1] + a[i], a[i]);
	}
	for (int i = 1; i < n; i++) {
		fl[i] = max(fl[i - 1], fl[i]);
	}

	fr[n - 1] = a[n - 1];
	for (int i = n - 2; i > 0; i--) {
		fr[i] = max(fr[i + 1] + a[i], a[i]);
	}
	for (int i = n - 2; i > 0; i--) {
		fr[i] = max(fr[i + 1], fr[i]);
	}
	ll ans = fl[0] + fr[2];
	for (int i = 1; i < n - 1; i++) {
		ans = max(ans, fr[i + 1] + fl[i - 1]);
	}
	cout << ans << '\n';

	return 0;
}
