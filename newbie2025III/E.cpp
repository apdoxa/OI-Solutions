#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	int sum=0;
	bool ng=false;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum+=a[i];
		if(a[i]<0)ng=true;
	}
	sum+=n;
	//非负重计算
	if(ng){
		int mx=INT64_MIN;
		for(int i=1;i<=n;i++){
			mx=max(a[i]+i,mx);
		}
		sum=mx;
	}
	cout << sum << '\n';

	return 0;
}
