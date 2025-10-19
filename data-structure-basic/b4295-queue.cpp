#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int x, y, k;
	bool mem[202] = {false};
	cin >> x >> y >> k;
	memset(mem, false, sizeof(mem));

	int current = 0, count = 1, total = x + y, remaining = total;
	while (remaining > x)
	{
		if (!mem[current])
		{
			
			if (count == k)
			{
				mem[current] = true;
				remaining--;
				count = 0;
			}
			count++;
		}
		current = (current + 1) % total;
	}
	int cnt=0;
	for (int i = 0; i < (x + y); i++)
	{
		if (!mem[i])
		{
			cnt++;
			printf("%d", i + 1);
			//男生索引可能不为0，导致没有空格输出
			if (cnt<x)
			{
				printf(" ");
			}
		}
	}
}
