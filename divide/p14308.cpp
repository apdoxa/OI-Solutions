#include <bits/stdc++.h>
using namespace std;
vector<__int128> arr(5e2, 1);
#define pll pair<__int128, __int128>
vector<pair<pll, pll>> sq; // x0,y0->↙，x1,y1->↗ x=>x0&&y>=y0&&x<=x0&&y<=y0即可
int main()
{
	for (int i = 2; i < 5e2; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		if (arr[i] > (__int128(1) << 64))
		{
			break;
		}
	}
	//左下，右上
	sq.push_back({{-1, 0}, {0, 1}});
	sq.push_back({{-1, -1}, {0, 0}});
	for (int i = 2; i < 92; i++)
	{
		// 1%4==0,1,2,3-> ld,rd,ru,lu
		int re = (i - 2) % 4;
		__int128 lenoffset=arr[i]-arr[i-1];
		pair<pll, pll> a = sq[i - 1];
		// x,y移动值
		__int128 nx = 0;
		__int128 ny = 0;
		if (re == 0)
		{
			// x+
			nx = arr[i -1];
			a.second.first+=lenoffset;
			a.second.second+=lenoffset;
		}
		else if (re == 1)
		{
			// y+
			ny = arr[i-1 ];
			a.first.first-=lenoffset;
			a.second.second+=lenoffset;
		}
		else if (re == 2)
		{
			// x-
			nx = -arr[i-1 ];
			a.first.first-=lenoffset;
			a.first.second-=lenoffset;
		}
		else if (re == 3)
		{
			// y-
			ny = -arr[i-1 ];
			a.first.second-=lenoffset;
			a.second.first+=lenoffset;
		}

		a.first.first += nx;
		a.first.second += ny;
		a.second.first += nx;
		a.second.second += ny;
		sq.push_back(a);
	}
	int t;
	cin >> t;
	while (t--)
	{
		long x, y;
		cin >> x >> y;
		for (int i = 0; i < 92; i++)
		{

			pll left_down = sq[i].first;
			pll right_up = sq[i].second;
			if (x >= left_down.first && y >= left_down.second && x <= right_up.first && y <= right_up.second)
			{
				cout << (long long)arr[i] << endl;
				break;
			}
		}
	}

	return 0;
}
