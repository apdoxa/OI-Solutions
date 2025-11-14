#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N = 1e5+10;
int n, m;
vector<int> ar(n + 1);
class SGT {
#define TN int now=1,int l=1,int r=n
#define LS now<<1,l,mid
#define RS now<<1|1,mid+1,r
private:
	int node[N << 2], tag[N << 2];
	void apply(int mv, TN) {
		node[now] += mv * (r - l + 1);
		tag[now] += mv;
	}
	void pushup(int now) {
		node[now] = node[now << 1] + node[now << 1 | 1];
	}
	void pushdown(TN) {
		if (tag[now] == 0) return;  // 无标记则无需下传
		int mid = ((r - l) >> 1) + l;
		// 下传给左孩子
		apply(tag[now], LS);
		// 下传给右孩子
		apply(tag[now], RS);
		// 清空当前节点标记
		tag[now] = 0;
	}

public:

	void build(TN) {
		if (l == r) {
			node[now] = ar[l];
			return ;
		}
		int mid = ((r - l) >> 1) + l;
		build(LS), build(RS);
		pushup(now);
	}
	void mod_mul(int a, int b, int val, TN) {
		if (a <= l && r <= b) return apply(val, now, l, r);
		pushdown(now, l, r);
		int mid = ((r - l) >> 1) + l;
		if (a <= mid)mod_mul(a, b, val, LS);
		if (b > mid)mod_mul(a, b, val, RS);
		pushup(now);
	}
	int querysum(int a, int b, TN) {
		if (a <= l && r <= b) return node[now];
		pushdown(now, l, r);
		int sum = 0, mid = ((r - l) >> 1) + l;
		if (a <= mid) sum += querysum(a, b, LS);
		if (b > mid) sum += querysum(a, b, RS);
		return sum;
	}
} sgt;
void solve() {
	cin >> n >> m;
	ar.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	sgt.build();
	while (m--) {
		int op, x, y, k;
		cin >> op;
		cin >> x >> y;
		if (op == 1) {
			cin >> k;
			sgt.mod_mul(x, y, k);
		} else {
			cout << sgt.querysum(x, y) << '\n';
		}
	}

}
signed main() {
	solve();
	return 0;
}
