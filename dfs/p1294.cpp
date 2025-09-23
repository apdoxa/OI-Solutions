#include <bits/stdc++.h>
using namespace std;
int n,m;
bool visited[21];
int G[21][21];
int dist=0;
void dfs(int i,int a){
	visited[i]=true;
	//搜索某点至任意点的可行路径
	for (int j = 1; j <=n; j++)
	{
		if (G[i][j]&&!visited[j])
		{
			//i->j
			//搜索j点
			dfs(j,a+G[i][j]);
		}
		
	}
	visited[i]=false;
	//取最长路径
	dist=max(dist,a);
}
int main()
{
	cin>>n>>m;

	for (int i = 1; i <=m; i++)
	{
		//input node info
		//1-based index
		int x,y;
		cin>>x>>y;
		//双向图
		cin>>G[x][y];
		G[y][x]=G[x][y];
	}
	
	//从某点开始寻找最长路径
	//1-based index
	for (int i = 1; i <=n; i++)
	{
		dfs(i,0);
	}
	
	cout<<dist<<'\n';
	return 0;
}