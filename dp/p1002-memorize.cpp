//TODO: REVIEW and optimize
#include <bits/stdc++.h>
using namespace std;
int g[21][21];
long long dp[21][21];
int n, m, mx, my;

int main()
{
	cin >> n >> m >> mx >> my;
	// dp计算
	dp[0][0]=1;
	for (int i = 0; i <=n; i++)
	{
		for (int j = 0; j <=m; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			if (i == mx && j == my)
			{
				continue;
			}

			if ((i == mx + 1 && j == my + 2) || (i == mx + 1 && j == my - 2) || (i == mx - 1 && j == my + 2) || (i == mx - 1 && j == my - 2))
			{
				continue;
			}
			
			if ((i == mx + 2 && j == my + 1) || (i == mx + 2 && j == my - 1) || (i == mx - 2 && j == my - 1) || (i == mx - 2 && j == my + 1))
			{
				continue;
			}
			// x==0 只能从上方来
			if (i == 0)
			{
				dp[i][j] = dp[i][j - 1] ;
				// y==0 只能从右来
			}
			else if (j == 0)
			{
				dp[i][j] = dp[i - 1][j];
			}else{
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
		}
	}
	cout<<dp[n][m];

	return 0;
}