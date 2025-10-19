#include <bits/stdc++.h>
using namespace std;
#define li long long
#define ft(x) for (int i = 1; i <= x; i++)
li n, q, m;
const li MAXN = 1e5 + 10;
li arr[MAXN];

li d[MAXN * 4], lazyP[MAXN * 4], lazyMulti[MAXN * 4];

void pd(li s, li t, li p)
{
	li m = s + ((t - s) >> 1);
	if (lazyMulti[p]!=1 && s != t)
	{
		d[p * 2] =(d[p * 2] *lazyMulti[p])%m;
		d[p * 2 + 1] =(d[p * 2] * lazyMulti[p])%m;

		//乘法标记会影响加法标记
		lazyMulti[p * 2] = lazyMulti[p];
		lazyMulti[p * 2 + 1] = lazyMulti[p];
		lazyMulti[p] = 1;


	}
	if(lazyP[p]&&s!=t){
		//先乘法后加法以实现a*m+k。一个节点对应一个原数值的偏移和放缩，如果先加法则会改变乘法效果
		d[p * 2] = (d[p * 2] +lazyP[p] * (m - s + 1))%m;
		d[p * 2 + 1] = (d[p * 2+1] +lazyP[p] * (t - m))%m;

		lazyP[p * 2] = (lazyP[p * 2]+lazyP[p])%m;
		lazyP[p * 2 + 1] =(lazyP[p * 2+1]+ lazyP[p])%m;
		lazyP[p] = 0;
	}
}

void build(li s, li t, li p)
{
	if (s == t)
	{
		d[p] = arr[s];
		return;
	}
	lazyMulti[p]=1;
	li m = s + ((t - s) >> 1);
	build(s, m, p * 2), build(m + 1, t, p * 2 + 1);
	d[p] = d[p * 2] + d[p * 2 + 1];
}
li getSum(li l, li r, li s, li t, li p)
{
	if (l <= s && t <= r)
	{
		return d[p];
	}
	li m = s + ((t - s) >> 1), sum = 0;
	pd(s, t, p);

	if (l <= m)
	{
		sum += getSum(l,r,s,m,p*2);
	}
	if (r > m)
	{
		sum += getSum(l,r,m+1,t,p*2+1);
	}

	return sum;
}
void upd_plus(li l, li r, li s, li t, li p, li num)
{
	if (l <= s && t <= r)
	{
		// 在区间内，直接修改
		d[p] = (d[p]+num * (t - s + 1))%m;
		lazyP[p] =  (lazyP[p]+num)%m;
		return;
	}
	li m = s + ((t - s) >> 1);
	pd(s, t, p);
	if (l <= m)
	{
		upd_plus(l, r, s, m, p * 2, num);
	}
	if (r > m)
	{
		upd_plus(l, r, m+1, t, p * 2 + 1, num);
	}
	d[p] = d[p * 2] + d[p * 2 + 1];
}
void upd_Multi(li l, li r, li s, li t, li p, li num)
{
	if (l <= s && t <= r)
	{ // 注意是s,t是l,r的子集，即l<=s,t<=r
		// 在区间内，直接修改
		d[p] = (d[p]*num)%m;
		lazyMulti[p] =( lazyMulti[p] *num)%m;
		return;
	}
	li m = s + ((t - s) >> 1);
	pd(s, t, p);
	if (l <= m)
	{
		upd_Multi(l, r, s, m, p * 2, num);
	}
	if (r > m)
	{
		upd_Multi(l, r, m+1, t, p * 2 + 1, num);
	}
	d[p] = (d[p * 2] + d[p * 2 + 1])%m;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q >> m;
	ft(n)
	{
		cin >> arr[i];
	}
	while (q--)
	{
		li x, y, opcode;
		cin >> opcode >> x >> y;
		if (opcode == 1)
		{
			li k;
			cin >> k;
			upd_Multi(x,y,1,n,1,k);
		}
		else if (opcode == 2)
		{
			li k;
			cin >> k;
			upd_plus(x,y,1,n,1,k);
		}
		else if (opcode == 3)
		{
			cout << getSum(x, y, 1, n, 1) % m<<'\n';
		}
	}

	return 0;
}