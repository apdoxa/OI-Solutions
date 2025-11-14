#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int mx=0,ans=INT64_MIN;
	for(int i=1;i<=n;i++){
		int now=a[i]+i+mx;
		mx=max(mx,now-i);//维护前缀
		ans=max(ans,now);
	}

	cout << ans << endl;
	return 0;
}

