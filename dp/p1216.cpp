#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 1;
int g[MAXN][MAXN];
int f[MAXN][MAXN];

int main()
{
	int n;
	cin >> n;
	for (size_t i = 0; i <n; i++)
	{
		for (size_t j = 0; j <=i; j++)
		{
			cin >> g[i][j];
		}
	}

	f[0][0]=g[0][0];//初始化
	//从第二行开始，计算每一个格子的最大路径和，防止数组越界
	for (size_t i = 1; i <n; i++)
	{
		for (size_t j = 0; j <=i; j++)
		{
			if(j==0){
				//最左侧只能从上到
				f[i][j]=f[i-1][j]+g[i][j];
			}else if(j==i){
				//最右侧只能来自左上
				f[i][j]=f[i-1][j-1]+g[i][j];
			}else{
				//来自左上或者正上
				f[i][j]=max(f[i-1][j-1],f[i-1][j])+g[i][j];
			}
		}
	}
	int ans=0;
	//在最后一行搜寻最大结果
	for(int j=0;j<n;j++){
		ans = max(ans,f[n-1][j]);
	}
	cout<<ans<<'\n';
	return 0;
}