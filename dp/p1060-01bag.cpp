#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	int item[30];
	int sale_v[30];
	int dp[30005]={0};

	cin>>n>>m;
	for (size_t i = 0; i < m; i++)
	{
		int v,p;
		cin>>v>>p;
		sale_v[i]=v;
		item[i]=v*p;
	}

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = n; j >=sale_v[i]; j--)
		{
			//dp[i]剩余容量i下所能取得的最大价值
			dp[j]=max(dp[j],dp[j-sale_v[i]]+item[i]);
		}
		
	}
	
	cout<<dp[n]<<'\n';

	return 0;
}