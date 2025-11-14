#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n, m, k, b;
	cin >> n >> m >> k >> b;

	int accnt = 0;
	int recnt = 0;
	vector<int> tobered;

	for (size_t i = 0; i < n; i++)
	{
		int sum = 0;
		int rescore = 0;
		for (size_t j = 0; j < m; j++)
		{
			int sc;
			cin >> sc;
			sum += sc;
			if (sc >= 1)
			{
				sc--;
			}
			else
			{
				sc++;
			}
			rescore += sc;
		}

		if (sum >= k)
		{
			accnt++;
		}
		else
		{
			//cout << "wwww" << i << '\n';
			tobered.push_back(rescore);
		}
	}
	sort(tobered.begin(), tobered.end(), greater<int>());
	for (size_t i = 0; i < tobered.size(); i++)
	{
		if (tobered[i] >= k && recnt < b)
		{
			accnt++;
			recnt++;
		}
		else
		{
			break;
		}
	}
	cout << accnt << '\n';
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}