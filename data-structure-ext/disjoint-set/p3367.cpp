#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
int pa[MAXN];
int find(int x)
{
	if (pa[x]!=x){
		//有父
		pa[x]=find(pa[x]);//找上级并数据压缩
	}
	return pa[x];
}
void unite(int x,int y){
	int rootX=find(x);
	int rootY=find(y);
	if (rootX!=rootY)
	{
		pa[rootX]=rootY;
	}
	
}
int main()
{

	int n, m;
	cin >> n >> m;
	for (size_t i = 1; i <= n; i++)
	{
		pa[i] = i;
	}

	while (m--)
	{
		int z, x, y;
		cin >> z >> x >> y;
		if (z == 1)
		{
			unite(x,y);
			//pa[x] = pa[y];//错误的，这样只是移动树
		}
		else if (z == 2)
		{
			if (find(x) ==find(y))
			{
				cout << 'Y' << '\n';
			}
			else
			{
				cout << 'N' << '\n';
			}
		}
	}

	return 0;
}