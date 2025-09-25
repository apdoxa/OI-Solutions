#include <bits/stdc++.h>
using namespace std;
struct Node{
	int x,y,step,h;
};
int main()
{
	queue<Node> q;

	int g[9][9]={0};
	int max_hp[9][9];
	memset(max_hp,-1,sizeof(max_hp));


	int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> g[i][j];
			// entry point
			if (g[i][j] == 2)
			{
				q.push((Node){i,j,0,6});
			}
		}
	}
	// BFS
	while (!q.empty())
	{
		Node head = q.front();
		q.pop();
		//check
		if(g[head.x][head.y]==3){
			cout<<head.step;
			return 0;
		}

		
		
		for(int i=0;i<4;i++){
			int dx=head.x+dir[i][0];
			int dy=head.y+dir[i][1];
			int dh=head.h-1;
			if (dx < 0 || dx >= n || dy < 0 || dy >= m || g[dx][dy]==0||dh<=0) continue;

			if(g[dx][dy]==4){
				dh=6;//回血
			}

			//血量大用时更短
			if(dh>max_hp[dx][dy]){
				max_hp[dx][dy]=dh;
				q.push((Node){dx,dy,head.step+1,dh});
			}
		}
	}
	cout<<-1;
	return 0;
}