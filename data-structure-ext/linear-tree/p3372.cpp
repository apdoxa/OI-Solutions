#include <bits/stdc++.h>
using namespace std;
#define li long long
#define ft(x) for (int i = 1; i <= x; i++)

const li MAXN = 1e5 + 10;
li n, m;
li nums[MAXN];
li tree[4 * MAXN];
li lazy[4 * MAXN] = {0}; // 懒标记
void build(li s, li t, li p)
{
	if (s == t)
	{
		// 长度1直接赋值
		tree[p] = nums[s];
		return; // 终止递归
	}

	li m = s + ((t - s) >> 1); //!!!移位符号优先级别小于加减法
	build(s, m, p * 2), build(m + 1, t, p * 2 + 1);
	tree[p] = tree[2 * p] + tree[2 * p + 1];
}
void push_down(li s, li t, li p, li m)
{
	if (lazy[p] && s != t)
	{

		// s!=t 代表有子节点，需要往下传
		tree[p * 2] += lazy[p] * (m - s + 1), tree[p * 2 + 1] += lazy[p] * (t - m);
		lazy[p * 2] += lazy[p], lazy[p * 2 + 1] += lazy[p]; // 标记下递
		// 清除标记
		lazy[p] = 0;
	}
}
//[l,r] 查询区间,[s,t]当前区间
li getsum(li l, li r, li s, li t, li p)
{
	// [s,t]在[l,r]区间内
	if (l <= s && t <= r)
	{
		// 是子集，直接返回
		return tree[p];
	}
	li m = s + ((t - s) >> 1), sum = 0;
	// 有标记且有子树，那就往下传
	push_down(s, t, p, m);
	// 检测更新标记
	if (l <= m)
	{
		// 与左子树有交集
		sum += getsum(l, r, s, m, 2 * p);
	}
	// 不能改成if else,因为可能都有交集，如[2,5],左侧[3,4]右侧[5,5]
	if (r > m)
	{
		// 与右子树有交集
		sum += getsum(l, r, m + 1, t, 2 * p + 1);
	}
	return sum;
}

//[l,r]查询区间,[s,t]当前区间
void upd(li l, li r, li s, li t, li k, li p)
{
	// [s,t]在[l,r]区间内，直接修改当前节点的值，然后打标记，结束修改
	if (l <= s && t<= r)
	{
		tree[p] += (t - s + 1) * k, lazy[p] += k; // 区间加上一段，更新节点值，然后直接标记返回
		return;
	}
	li m = s + ((t - s) >> 1);
	// 范围[s,m],[m+1,t]
	push_down(s, t, p, m);
	// 更新子节点
	if (l <= m)
		upd(l, r, s, m, k, p * 2);
	if (r > m)
		upd(l, r, m + 1, t, k, p * 2 + 1);
	tree[p] = tree[p * 2] + tree[p * 2 + 1];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	ft(n)
	{
		cin >> nums[i];
	}
	build(1, n, 1);

	while (m--)
	{
		int opc;
		li x, y;
		cin >> opc;
		cin >> x >> y;
		if (opc == 1)
		{
			li k;
			cin >> k;
			// 加
			upd(x, y, 1, n, k, 1);
		}
		else if (opc == 2)
		{
			// 查
			cout << getsum(x, y, 1, n, 1) << '\n';
		}
	}

	return 0;
}