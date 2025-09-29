#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;

	cin>>n>>m;
	int dish[105];
	int dp[10005]={0};
	
	dp[0]=1;
	for(int i=0;i<n;i++){
		cin>>dish[i];
	}
	//点菜方法 状态方程:金钱，方法
	for (size_t i = 0; i < n; i++)//n种菜
	{
		// 内层循环从m递减到dish[i]，避免重复选择同一道菜
		//j >=dish[i]确保钱够买，不会触发数组越界
		for (size_t j = m; j >=dish[i]; j--)
		{
			dp[j] +=dp[j-dish[i]];
		}
	}
	cout<<dp[m];

	return 0;
}