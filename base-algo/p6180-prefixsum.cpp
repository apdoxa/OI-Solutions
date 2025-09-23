#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int a[N], sum1[N], sum2[N], sum3[N];

int main()
{
	sum1[0] = 0;
	sum2[0] = 0;
	sum3[0] = 0;

	int n,q;
	cin >> n>>q;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == 1)
		{
			sum1[i + 1] = sum1[i] + 1;
			sum2[i + 1] = sum2[i];
			sum3[i + 1] = sum3[i];
		}
		else if (a[i] == 2)
		{
			sum1[i + 1] = sum1[i];
			sum2[i + 1] = sum2[i] + 1;
			sum3[i + 1] = sum3[i];
		}
		else
		{
			sum1[i + 1] = sum1[i];
			sum2[i + 1] = sum2[i];
			sum3[i + 1] = sum3[i] + 1;
		}
	}

	while (q--)
	{
		int a, b;
		cin >> a >> b;
		cout << sum1[b] - sum1[a - 1] << ' ' << sum2[b] - sum2[a - 1] << ' ' << sum3[b] - sum3[a - 1] << '\n';
	}

	return 0;
}