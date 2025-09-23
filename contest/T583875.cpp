#include <bits/stdc++.h>
using namespace std;

int main()
{
	const int N = 1e5 + 1;

	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;

	while (q--)
	{
		int n, m;
		cin >> n >> m;
		vector<long long> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		if (n == 0)
		{
			cout << 0 << endl;
			continue;
		}
		vector<long long> b(n);
		b[n - 1] = min((long long)m, arr[n - 1]);

		for (int i = n - 2; i >= 0; i--)
		{
			b[i] = min((long long)m, min(arr[i], b[i + 1]));
		}

		long long total = 0;
		for (int i = 0; i < n; i++)
		{
			total += b[i];
		}
		cout << total << '\n';
	}
}