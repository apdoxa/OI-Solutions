#include <iostream>
#include <cstdio>
#include <vector>
#define fz(i, x) for (int i = 0; i < x; i++)
using namespace std;
int a[3][4];
vector<int> mul(vector<int> x, vector<int> y)
{
	vector<int> res(4);
	res[0] = x[0] * y[0] - x[1] * y[1] - x[2] * y[2] - x[3] * y[3];

	res[1] = x[0] * y[1] + x[1] * y[0] + x[2] * y[3] - x[3] * y[2];

	res[2] = x[0] * y[2] - x[1] * y[3] + x[2] * y[0] + x[3] * y[1];

	res[3] = x[0] * y[3] + x[1] * y[2] - x[2] * y[1] + x[3] * y[0];

	return res;
}
int main()
{
	vector<vector<int>> a;
	fz(i, 3)
	{
		vector<int> w(4);
		fz(j, 4)
		{
			cin >> w[j];
		}
		a.push_back(w);
	}

	vector<int> res1 = mul(mul(a[0], a[1]), a[2]);
	vector<int> res2 = mul( a[0],mul(a[1], a[2]));

	fz(j, 4)
	{
		cout<<res1[j]<<' ';
	}
	cout<<'\n';
	fz(j, 4)
	{
		cout<<res2[j]<<' ';
	}

	return 0;
}