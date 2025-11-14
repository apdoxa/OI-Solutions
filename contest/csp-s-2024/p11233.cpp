//TODO: DP and optimize
#include <bits/stdc++.h>
using namespace std;
int main(){
	int T=0;
	cin>>T;
	
	vector<vector<int>> input(T);
	for(int i=0;i<T;i++){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		input.push_back(a);
	}

	ios::sync_with_stdio(false);
	
	return 0;
}