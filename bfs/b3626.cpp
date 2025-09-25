#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 2;
int min_steps[N];
int dirs[4] = {-1, 1, 2};
int main()
{
	int n;
	cin >> n;
	n -= 1; // 0-based index
	fill(min_steps, min_steps + N, 2147483647); //memset 适用于每个字节,fill适用于每个元素
	queue<pair<int, int>> q; // idx,steps
	min_steps[0] = 0;
	q.push({0, 0});

	while (!q.empty())
	{
		pair<int, int> head = q.front();
		q.pop();

		for (int i = 0; i < 3; i++)
		{
			int dx;
			// calc x
			if (dirs[i] == 2)
			{
				//1-based计算再转换回去
				dx = (head.first+1)* 2-1;
			}
			else
			{
				dx = head.first + dirs[i];
			}
			// 越界检查
			if (dx < 0 || dx > n)
			{
				continue;
			}

			if (head.second + 1 < min_steps[dx])
			{
				min_steps[dx] = head.second + 1;
				q.push({dx, head.second + 1});
				if (dx == n)
				{
					cout << min_steps[dx];
					return 0;
				}
			}
		}
	}

	return 0;
}