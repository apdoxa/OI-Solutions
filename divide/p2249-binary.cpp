#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2;
int a[N];
int n, m;
inline void binary_search(int q)
{
	// 二分查找
	int x = 1, y = n;
	int ans=-1;
	while (x <= y)
	{
		int mid = (x + y) / 2;
		if (a[mid] == q)
		{
			ans=mid;
			y = mid - 1;//查找更小的索引
		}else if (a[mid] > q)
		{
			y = mid - 1;
		}
		else
		{
			x = mid + 1;
		}
	}
	cout << ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	while (m--)
	{
		int q;
		cin>>q;
		binary_search(q);
		if(m!=0)cout<<' ';
	}
	

	return 0;
}