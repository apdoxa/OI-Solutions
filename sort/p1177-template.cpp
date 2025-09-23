#include <bits/stdc++.h>
using namespace std;
void selectsort(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int max = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[max] > a[j])
			{
				max = j;
			}
		}
		int t = a[i];
		a[i] = a[max];
		a[max] = t;
	}
}
void bubblesort(int *a,int n){
	for(int i=0;i<n;i++){
		bool swaped=false;
		for (int j = 0; j < n-i-1; j++)
		{
			if(a[j]>a[j+1]){
				int t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
				swaped=true;
			}
		}
		if(!swaped)break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	const int N = 1e5 + 1;
	int a[N];
	vector<int> arr;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		arr.push_back(w);
	}
	sort(arr.begin(),arr.end());

	//bubblesort(a, n);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
		if (i != n-1)
			cout << ' ';
	}
	

	return 0;
}