//TODO:review
#include <bits/stdc++.h>
using namespace std;
int n;
int max_dist=0;
int g[101][101];
bool v[101][101];
//方向映射
int direction[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
void dfs(int x,int y,int dist){
	if (dist>max_dist)
	{
		max_dist=dist;
	}
	for(int d=0;d<4;d++){
		int dx=direction[d][0];
		int dy=direction[d][1];

		int step=1;
		while (true)
		{
			//拟迭代步数
			int nx=x+dx*(step+1);
			int ny=y+dy*(step+1);

			//检查越界
			if (nx<0 || nx>=n || ny<0 || ny>=n)
			{
				break;
			}

			//检查路径中是否有1
			bool valid = true;
			for (int k = 1; k <= step; k++)
			{
				//检查当前方向迭代的路径上是否有0阻挡路线
				int cx= x+dx*k;
				int cy= y+dy*k;
				if (g[cx][cy]!=1)
				{
					valid=false;
					break;
				}
			}
			
			if (!valid)
			{
				break;//有非1格子，剪枝
			}
			//检查目标格子是否为0且尚未访问
			if (g[nx][ny]==0&& !v[nx][ny])
			{
				v[nx][ny]=true;
				dfs(nx,ny,dist+step+1);
				v[nx][ny]=false;
			}
			//确定步数增加
			step++;
		}
		
	}

}
int main(){
	int x,y;
	cin>>n>>x>>y;
	//0-based
	x--;
	y--;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin>>g[i][j];
		}
	}
	if (g[x][y]!=0)
	{
		cout<<0<<'\n';
		return 0;
	}
	v[x][y]=true;
	dfs(x,y,0);
	
	cout<<max_dist<<'\n';

	return 0;
}