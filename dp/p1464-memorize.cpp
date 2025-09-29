#include <bits/stdc++.h>
using namespace std;
#define i64 long long
bool memok[30][30][30]={false};
i64 mem[30][30][30]={0};
i64 w(i64 a, i64 b, i64 c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
	{
		if (!memok[20][20][20])
		{
			//先计算后标记！！！
			mem[20][20][20] = w(20, 20, 20);
			memok[20][20][20] = true;
		}	
		return mem[20][20][20];
	};
	if (memok[a][b][c])
	{
		return mem[a][b][c];
	}
	
	i64 r;
	if (a < b && b < c)
	{
		r=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	}
	else
	{
		r=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	}
	memok[a][b][c]=true;
	mem[a][b][c]=r;

	return r;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	i64 a,b,c;
	cin >> a >> b >> c;
	//注意while条件
	while (a != -1 || b != -1 || c != -1)
	{
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
		cin >> a >> b >> c;
	}

	return 0;
}