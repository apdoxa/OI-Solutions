#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 2;
bool light[N];
int n, k;
inline bool chk(int L)
{
	int count = 0;
	int idx = 0;
	while (idx < n)
	{
		// 找到第一个开着的灯，并将后面的i+L-1个灯关闭
		if (light[idx])
		{
			count++;
			idx = idx + L - 1;
		}
		idx++;
	}
	return count <= k;
}
inline void calc()
{
	int min = n;
	int x = 1, y = n;

	int ans = n; // 一次最多关n盏灯
	while (x <= y)
	{
		int mid = (x + y) >> 1; // 移位整除2,优化计算速度
		if (chk(mid))
		{
			ans=mid;
			y = mid - 1;
		}
		else
		{
			x = mid + 1;
		}
	}
	cout << ans << '\n';
}
int main()
{
	int t;
	cin>>t;
	while (t--)
	{

		cin >> n >> k;
		char light_s[N];
		cin>>light_s;
		int idx=0;
		while (light_s[idx]!='\0')
		{
			if(light_s[idx]=='1'){
				light[idx]=true;
			}else{
				light[idx]=false;
			}
			idx++;
		}
		
		calc();
	}

	return 0;
}