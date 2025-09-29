#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const int N=1010;
	int t,m;
	int time[105];
	int value[105];
	int dp[105][N]={0};//x type,y time
	
	cin>>t>>m;
	for (size_t i = 1; i <=m; i++)
	{
		cin>>time[i]>>value[i];
	}

	for (int i = 1; i <=m; i++)//草药
	{
		for (int j = 0; j <=t; j++)//时间	
		{
			dp[i][j]=dp[i-1][j];//继承之前状态

			if (j>=time[i])//剩余时间多
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-time[i]]+value[i]);
			}
			
		}
		
	}
	cout<<dp[m][t]<<'\n';

	return 0;
}