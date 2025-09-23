#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 1;
int arr[N], dif[N];
inline void upd(int *dif, int x, int y, int num)
{
	dif[x] += num;
	if (y + 1 < N)
	{
		dif[y + 1] -= num;
	}
}
int main()
{

	int n, p;
	cin >> n >> p;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (i > 0)
		{
			dif[i] = arr[i] - arr[i - 1];
		}
		else
		{
			dif[0] = arr[0];
		}
	}
	while (p--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		upd(dif,x-1,y-1,z);//0-base index
	}
	int min=N;
	for(int i=0;i<n;i++){
		if(i>0){
			arr[i]=arr[i-1]+dif[i];
		}else{
			arr[i]=dif[0];
		}
		if(min>arr[i]){
			min=arr[i];
		}
	}
	cout<<min<<'\n';

	return 0;
}