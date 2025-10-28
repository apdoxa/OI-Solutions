#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> trees(n+1);
	int longest=0;
	for (size_t i = 0; i < n; i++)
	{
		cin>>trees[i];
		longest=max(longest,trees[i]);
	}

	int start_heigh=0;
	while (start_heigh<longest)
	{
		int sz=0;
		int mid=start_heigh+((longest-start_heigh)>>1);
		for (size_t i = 0; i < n; i++)
		{
			sz+=trees[i]-mid;
		}
		
		//木头少了
		if (sz<m)
		{
			start_heigh=mid;
		}else if(sz>m){
			longest=mid;
		}
		
	}
	
	cout<<longest<<'\n';
	

	return 0;
}