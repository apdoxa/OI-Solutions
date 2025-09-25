#include <bits/stdc++.h>
using namespace std;
int n,m;
int g[101][101];
bool v[101][101];
int l[101][101];//记录起点到终点距离
int s_x,s_y,t_x,t_y;
//方向
int d[4][2]={{0,1},{0,-1},{1,0},{-1,0},};
//求最短路径，故采用bfs
int bfs(){
	queue<pair<int,int>> q;
	q.push({s_x,s_y});
	v[s_x][s_y]=true;
	l[s_x][s_y]=0;

	while (!q.empty())
	{
		pair<int,int> h=q.front();
		int x=h.first;
		int y=h.second;
		q.pop();
		if (x==t_x&&y==t_y)
		{
			//到达终点
			return l[x][y];
		}
		for (int k = 0; k < 4; k++)
		{
			int nx=x+d[k][0];
			int ny=y+d[k][1];
			if (nx>=0&&ny>=0&&nx<n&&ny<m&&!v[nx][ny]&&g[nx][ny]==0)
			{
				/* 坐标不越界，坐标未访问，坐标不是1 */
				v[nx][ny]=true;
				l[nx][ny]=l[x][y]+1;
				//先访问再入队
				q.push({nx,ny});
			}
			
		}
		

	}
	return -1;
	

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin>>g[i][j];
		}
	}
	cin>>s_x>>s_y>>t_x>>t_y;

	//0-based index
	s_x--,s_y--,t_x--,t_y--;
	cout<<bfs()<<'\n';

	return 0;
}