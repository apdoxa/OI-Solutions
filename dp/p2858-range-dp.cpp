#include <bits/stdc++.h>
using namespace std;
#define i64 long long
i64 dp[2001][2001]; // dp[i][j]剩余i-j零食时候的最大收益
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; // n max=2000,days max=2000,vmax=2e6,summax=2e6*2e3=4e9>int32
	int initv[2001];

	cin >> n;
	for (size_t i = 1; i <= n; i++)
	{
		cin >> initv[i];
	}
	// 初始化，第i个零食只能第n天卖出
	for (size_t i = 1; i <= n; i++)
	{
		// 枚举剩余一份零食的时候价钱
		// 区间长度1，最小区间无依赖
		dp[i][i] = 1LL * initv[i] * n;
	}

	// 枚举区间长度->枚举区间起点->推导区间终点->计算价格
	for (size_t len = 2; len <= n; len++)
	{ 
		for (size_t i = 1; i <=n-len+1; i++)
		{
			//!!确保j不越界!!! j=i+len-1<=n
			int j = i + len - 1;
			int a = n - len + 1; // 用已经取走的天数求出当前操作天数系数，故需要+1
			// 初始剩余n长,已取4-4=0,下一次取为第1天
			// 故a=第n-1天 -> 第n-2天 -> 第n-3天 -> ... -> 第一天
			// 剩余区间长度 2 -> 3 -> 4 -> ... -> n
			// 从小区间推广到大区间
			dp[i][j] = max(dp[i][j - 1] + a * initv[j], dp[i + 1][j] + a * initv[i]);
		}
	}
	cout<<dp[1][n]<<'\n'; //输出剩余1-n区间可获得最大收入

	return 0;

	// 不采取贪心策略，因为零食顺序可变
	//  int money=0;
	//  int x=1,y=n;
	//  //最多卖n天
	//  for (size_t a = 1; a <=n; a++)
	//  {

	// 	if (initv[x]>initv[y])
	// 	{
	// 		//选择左侧
	// 		money+=initv[x]*a;
	// 		x++;
	// 	}else{
	// 		money+=initv[y]*a;
	// 		y--;
	// 	}
	// }
	// cout<<money<<'\n';

}