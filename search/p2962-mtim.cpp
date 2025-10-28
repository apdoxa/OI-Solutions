//TODO: review
#include <bits/stdc++.h>
#define ft(i, x) for (int i = 1; i <= x; i++)
#define fz(i, x) for (int i = 0; i < x; i++)
#define ll long long
using namespace std;

ll a[40];		     // 用二进制记录相连灯
map<ll, ll> min_count; // 状态->最小开关灯次数
ll mid;
ll n, m;

void dfs_front(ll light_id, ll status, ll cnt)
{
	if (light_id == mid)
	{
		if (!min_count.count(status))
		{
			min_count[status] = cnt;
		}
		else
		{
			min_count[status] = min(min_count[status], cnt);
		}
		return;
	}
	//[0,mid]
	dfs_front(light_id + 1, status, cnt);
	dfs_front(light_id + 1, status ^ a[light_id], cnt + 1);
}
ll dfs_back(ll light_id, ll status, ll cnt)
{
	if (light_id == n)
	{
		ll target=(1LL<<n)-1;//目标全亮
		ll need=target^status;

		if (min_count.count(need))
		{
			return min_count[need]+cnt;
		}
		else
		{
			return INT64_MIN;
		}
		
	}
	//[0,mid]
    ll res1 = dfs_back(light_id + 1, status, cnt);
    ll res2 = dfs_back(light_id + 1, status ^ a[light_id], cnt + 1);
    
    // 正确处理min操作
    if (res1 == INT64_MIN && res2 == INT64_MIN) return INT64_MIN;
    if (res1 == INT64_MIN) return res2;
    if (res2 == INT64_MIN) return res1;
    return min(res1, res2);
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> n >> m;
	mid = n / 2;
	// 初始化，每盏灯标记自身
	fz(i, n)
	{
		a[i] = 1LL << i ;
	}
	fz(i, m)
	{
		int n1, n2;
		cin >> n1 >> n2;
		n1--, n2--; // 转换为0-based
		a[n1] |= (ll)(1LL << n2), a[n2] |= (ll)(1LL << n1);
	}

	dfs_front(0, 0, 0);  // 1-mid
	ll ans=dfs_back(mid, 0, 0); // mid+1-n

	cout<<ans;
	return 0;
}