//TODO: review
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int v, n;

	cin >> v >> n;
	int item[35];
	
	int dp[20001]={0};//容量为i的箱子能装的最大物品体积
	for (int i = 0; i < n; i++)
	{
		cin >> item[i];
	}
	dp[0]=0;
	//每个物品扫一遍能不能放
	for (size_t i = 0; i < n; i++)
	{
		//放的下的箱子都扫一边
		//从大扫下去
		for (size_t j = v; j >= item[i]; j--)
		{
			//倒序遍历容量，确保每个物品只用一次，在每个容量位置选择最优的装填方案
			//这样从最大容量到物品容量部分，都加上了物品i,如果放不下那么就不加
			//dp[j]这表示容量j的背包n能装的最大价值
			//dp[j-item[i]]这是腾出物品i容量的背包之前能装的最大价值
			if(dp[j-item[i]]+item[i]>dp[j]){
				dp[j]=dp[j-item[i]]+item[i];
			}
		}
	}
	cout<<v-dp[v]<<'\n';//剩余容量

	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 0; j <= v; j++)
	// 	{
	// 		dp[i][j] = dp[i - 1][j];
	// 		if (itemv[i] <= v)
	// 		{
	// 			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - itemv[i]]);
	// 		}
	// 	}
	// }

	return 0;
}