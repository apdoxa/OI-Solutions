#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0;
	vector<int> val;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int input;
		scanf("%d", &input);

		val.push_back(input);
	}
	sort(val.begin(), val.end());

	int minMos=0;
	int existence = n;
	for (int attackMos = 0; attackMos < n; attackMos++)
	{
		if (val[attackMos]>val[minMos])
		{
			existence--;
			minMos++;
		}
		
	}

	printf("%d\n", existence);

	return 0;
}