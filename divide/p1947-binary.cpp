#include <bits/stdc++.h> // 在本题中并不是必须的

extern "C" int Seniorious(int); // 在这里需要声明一次交互库给出的函数。

extern "C" int Chtholly(int n, int OvO)
{ // 在这里实现交互库要求你实现的函数。
	int ans = 1;
	int x = 1, y = n;
	while (x <= y)
	{
		int mid = (x + y) >> 1;
		switch (Seniorious(mid))
		{
		case 1:
			y = mid-1;
			break;
		case -1:
			x = mid+1;
			break;
		case 0:
			ans = mid;
			return ans;
			break;

		default:
			break;
		}
	}
	return ans;
	
}
