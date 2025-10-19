#include <bits/stdc++.h>
#define ll long long
#define ft(i, x) for (int i=1; i <= x; i++)
const int MAXN = 1e5 + 10;
ll arr[MAXN];
ll n, q, mo;

ll dd[MAXN * 4], lazyP[MAXN * 4], lazyMul[MAXN * 4];
void build(ll s, ll t, ll p)
{
	if (s == t)
	{
		dd[p] = arr[s]%mo; // 单一节点
		return;
	}
	lazyP[p]=0;
	lazyMul[p] = 1;
	ll m = s + ((t - s) >> 1);
	build(s, m, p * 2), build(m + 1, t, p * 2 + 1);
	dd[p] = (dd[p * 2] + dd[p * 2 + 1])%mo;
}
void pd(ll s, ll t, ll p)
{
	ll m = s + ((t - s) >> 1);
	// 有子树
	if (s != t)
	{
		if (lazyMul[p] != 1)
		{
			// 有乘法标记，先处理(因为执行乘法操作的时候已经将加法标记放缩了)
			// left
			dd[p * 2] = (dd[p * 2] * lazyMul[p]) % mo;
			lazyMul[p * 2] = (lazyMul[p * 2] * lazyMul[p]) % mo;
			lazyP[p*2]=(lazyP[p*2]*lazyMul[p])%mo;
			// right

			dd[p * 2 + 1] = (dd[p * 2 + 1] * lazyMul[p]) % mo;
			lazyMul[p * 2 + 1] = (lazyMul[p * 2 + 1] * lazyMul[p]) % mo;
			lazyP[p*2+1]=(lazyP[p*2+1]*lazyMul[p])%mo;
			lazyMul[p] = 1;
		}
		if (lazyP[p] != 0 )
		{
			// 有加法标记
			// left
			dd[p * 2] = (dd[p * 2] + lazyP[p] * (m - s + 1)) % mo;
			lazyP[p * 2] =( lazyP[p * 2] + lazyP[p])%mo;

			// right
			dd[p * 2 + 1] = (dd[p * 2 + 1] + lazyP[p] * (t - m)) % mo;
			lazyP[p * 2 + 1] = (lazyP[p * 2 + 1] + lazyP[p]) % mo;

			lazyP[p] = 0;
		}
	}
}
//[l,r]查询区间,[s,t]当前区间 l<=s,t<=r
ll getsum(ll l, ll r, ll s, ll t, ll p)
{
	if (l <= s && t <= r)
	{
		return dd[p];
	}

	ll m = s + ((t - s) >> 1), sum = 0;
	pd(s, t, p);

	if (l <= m)
	{
		sum =( sum+getsum(l, r, s, m, p * 2))%mo;
	}
	if (r > m)
	{
		sum = (sum+ getsum(l, r, m + 1, t, p * 2 + 1))%mo;
	}
	return sum % mo;
}
// l s t r
void upd_plus(ll l, ll r, ll s, ll t, ll p, ll k)
{
	if (l <= s && t <= r)
	{
		// 在区间内
		dd[p] = (dd[p] + k * (t - s + 1)) % mo;
		lazyP[p] = (lazyP[p] + k) % mo;
		return;
	}
	ll m = s + ((t - s) >> 1);
	pd(s, t, p);
	if (l <= m)
	{
		upd_plus(l, r, s, m, p * 2, k);
	}
	if (r > m)
	{
		upd_plus(l, r, m + 1, t, p * 2 + 1, k);
	}
	dd[p] = (dd[p * 2] + dd[p * 2 + 1]) % mo;
}
// l s t r
void upd_mul(ll l, ll r, ll s, ll t, ll p, ll k)
{
	
	if (l <= s && t <= r)
	{
		// 在区间内
		dd[p] = (dd[p] * k) % mo;
		lazyMul[p] = (lazyMul[p] * k) % mo;
				lazyP[p] = (lazyP[p] * k) % mo;
		return;
	}
	pd(s, t, p);
	ll m = s + ((t - s) >> 1);

	if (l <= m)
	{
		upd_mul(l, r, s, m, p * 2, k);
	}
	if (r > m)
	{
		upd_mul(l, r, m + 1, t, p * 2 + 1, k);
	}
	dd[p] = (dd[p * 2] + dd[p * 2 + 1])%mo;
}
using namespace std;
int main()
{

	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> q >> mo;

	ft(i, n)
	{
		cin >> arr[i];
	}
	build(1,n,1);
	ft(op, q)
	{
		int opcode;
		ll x, y;
		cin >> opcode;

		if (opcode == 1)
		{
			ll k;
			cin >> x >> y;
			cin >> k;
			// mul k
			upd_mul(x, y, 1, n, 1, k);
		}
		else if (opcode == 2)
		{
			ll k;
			cin >> x >> y;
			// plus k
			cin >> k;
			upd_plus(x, y, 1, n, 1, k);
		}
		else if (opcode == 3)
		{
			cin >> x >> y;
			// output
			cout << getsum(x, y, 1, n, 1) << '\n';
		}
	}

	return 0;
}