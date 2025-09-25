#include <bits/stdc++.h>
using namespace std;
int n,x,y;
int g[101][101];
bool v[101][101];
int dirs[4][2]={{0,1},{0,-1},{1,0},{-1,0},};
queue<pair<int,int>> q;

void bfs(){
	v[0][0]=true;
	q.push({0,0});
	while (!q.empty())
	{
		pair<int,int> head=q.front();
		q.pop();
		int x=head.first;
		int y=head.second;
		for (int i = 0; i < 4; i++)
		{
			int nx=x+dirs[i][0];
			int ny=y+dirs[i][1];

			//扫一圈外部的0并标记
			if (nx>=0&&nx<=n+1&&ny>=0&&ny<=n+1&&!v[nx][ny]&&g[nx][ny]==0)
			{
				v[nx][ny]=true;
				q.push({nx,ny});
			}
			
		}
		
	}
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	//输入
	cin>>n;
	//[1,n][1,n]为原矩阵范围
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <=n; j++)
		{
			cin>>g[i][j];
			if(g[i][j]==1){
				v[i][j]=true;
			}
		}
		
	}
	bfs();
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <=n; j++)
		{
			if(!v[i][j]&&v[i][j]==0){
				cout<<2;
			}else{
				cout<<g[i][j];
			}
			if(j==n)cout<<'\n';
			else cout<<' ';
		}
		if(i==n)cout<<'\n';
	}

	return 0;
}