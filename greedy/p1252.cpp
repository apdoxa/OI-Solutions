#include <bits/stdc++.h>
using namespace std;
int info[5][10];
int km[5] = {1, 1, 1, 1, 1};

int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> info[i][j];
		}
	}

	int total_km = 5;
	// 初始
	int time = 0;
	for (int i = 0; i < 5; ++i)
	{
		time += info[i][0]; // info[i][0]是跑1公里的总时间
	}
	while (total_km < 25)
	{
		int min_time = INT32_MAX;
		int selected = -1;

		for (int i = 0; i < 5; i++)
		{
			if (km[i] >= 10)
			{
				continue; // arrived at limitiation
			}
			// calc next km time
			int ntime = info[i][km[i]] - info[i][km[i] - 1];

			if (ntime < min_time)
			{
				min_time = ntime;
				selected = i;
			}
		}
		time += min_time;
		km[selected]++;
		total_km++;
	}
	cout << time << '\n';
	for (int i = 0; i < 5; i++)
	{
		cout << km[i] << ' ';
	}

	return 0;
}