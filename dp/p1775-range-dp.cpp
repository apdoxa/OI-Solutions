#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int rocks[305];
	int sum[305]={0};
	int dp[305][305];//dp[i][j]表示i到j堆的最小a代价

	cin>>n;
	for (size_t i = 1; i <= n; i++)
	{
		cin>>rocks[i];
		sum[i]=sum[i-1]+rocks[i];//前缀和，尽量使用1-index
	}
	
	//[i,i]无需合并，代价0
	for (size_t i = 1; i <=n; i++)
	{
		dp[i][i]=0;
	}
	//dp[i,j]合并代价
	//dp[i][j] min(dp[i,k]+dp[k+1,j])+sum(i,j)之前的合并代价
	
	//枚举区间长度，时间复杂度O(n^3)
	for (size_t len = 2; len <=n; len++)
	{
		//枚举起点,在[i,i+len-1]范围内
		for (size_t i = 1; i+len-1 <=n; i++)
		{
			//用长度推导出区间终点j
			int j=i+len-1;//-1是去掉起点重叠
			dp[i][j]=INT32_MAX;
			//分为两堆[i,k],[k+1,j]
			//枚举分割点k k的范围为i-j-1,因为k+1可以取到j
			for (size_t k = i; k < j; k++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
			}
			
		}
		
	}

	cout<<dp[1][n]<<'\n';

	return 0;
}