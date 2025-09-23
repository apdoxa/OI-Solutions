#include <bits/stdc++.h>
using namespace std;
void divide(int x)
{
	int cnt = 0;
	for (int i = 31; i >= 0; i--)
	{

		if (x & (1 << i))
		{
			cnt++;
			if (cnt > 1)
				cout << '+';
			if (i == 0)
			{
				cout << "2(0)";
			}
			else if (i == 1)
			{
				cout << "2";
			}
			else
			{
				cout << "2(";
				divide(i);
				cout << ")";
			}
		}
	}

	return;
}
int main()
{
	int x;
	cin >> x;
	divide(x);
	cout << '\n';

	return 0;
}