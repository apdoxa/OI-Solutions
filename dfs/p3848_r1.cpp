//24mins TODO:review
#include <bits/stdc++.h>
#define fz(i,x) for(int i=0;i<x;i++)
using namespace std;
int n, x, y;
vector<vector<int>> g;
vector<vector<int>> v;
long long max_dist;
int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int x,int y,long long dist){
	max_dist=max(max_dist,dist);
	fz(dir,4){
		int step=1;//初始至少2距离，故从step1开始
		//迭代步数
		while(true){
			//模拟下一步
			int nx=x+dirs[dir][0]*(step+1);
			int ny=y+dirs[dir][1]*(step+1);
			
			//越界
			if(nx<0||ny<0||nx>=n||ny>=n){
				break;//当前方向到尽头了
				//!!!这里不能用continue,否则会继续while循环
			}
			bool valid=true;
			//扫描有没有阻挡的 从1-step步数开扫
			for(int k=1;k<=step;k++){
				int cx=x+dirs[dir][0]*k;
				int cy=y+dirs[dir][1]*k;
				if(g[cx][cy]==0){
					valid=false;
					break;
				}
			}
			if(!valid){
				break;
			}
			//判断目标是否为1且尚未访问
			if(v[nx][ny]!=1&&g[nx][ny]==0){
				v[nx][ny]=1;
				//开始搜索当前点
				dfs(nx,ny,dist+step+1);
				//结束搜索当前点
				v[nx][ny]=0;
			}
			step++;//迭代步数，直到尽头
			//不可放在外侧，放在外侧就会正常通行的时候止步不前
		}
		
	}
	
}
int main() {
	//n 1-100
	//1-based index
	cin >> n >> x >> y;
	x--,y--;
	g.resize(n,vector<int>(n));
	v.resize(n,vector<int>(n,0));
	fz(i,n){
		fz(j,n){
			cin>>g[i][j];
		}
	}
	v[x][y]=1;
	dfs(x,y,0);
	cout<<max_dist<<'\n';
	return 0;
}
