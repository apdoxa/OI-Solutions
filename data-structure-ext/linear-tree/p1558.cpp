#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pii pair<int,int>
using namespace std;
const int N = 1e5+10;
int L, T, O;
vector<int> board;
class SGT {
#define TN int now=1,int l=1,int r=L
#define mid (((r-l)>>1)+l)
#define LS now<<1,l,mid
#define RS now<<1|1,mid+1,r
private:
	int no[N << 2], tag[N << 2];
	void apply(int mv, TN) {
		no[now] = (1 << mv);
		tag[now] = mv;
	}
	void pushup(int now) {
		no[now] = no[now << 1] | no[now << 1 | 1];
	}
	void pushdown(TN) {
		if (tag[now] != 0) {
			apply(tag[now], LS), apply(tag[now], RS), tag[now] = 0;
		}
	}
public:
	void build(TN) {
		tag[now] = 0;
		if (l == r) {
			no[now] = (1 << 1);
			return;
		}
		build(LS), build(RS);
		pushup(now);
	}
	void color(int a, int b, int c, TN) {
		if (a <= l && r <= b) {
			apply(c, now, l, r);
			return ;
		}
		pushdown(now, l, r);
		if (a <= mid)color(a, b, c, LS);
		if (b > mid)color(a, b, c, RS);
		pushup(now);
	}
	int query(int a, int b, TN) {
		if (a <= l && r <= b) {
			return no[now];
		}
		pushdown(now, l, r);
		int bo = 0;
		if (a <= mid)bo |= query(a, b, LS);
		if (b > mid)bo |= query(a, b, RS);
		return bo;
	}
} sgt;
void solve() {
	cin >> L >> T >> O;
	board.resize(L + 1);
	sgt.build();
	while (O--) {
		char op;
		int x, y, c;
		cin >> op >> x >> y;
		if (op == 'C') {
			cin >> c;
			if (x > y)swap(x, y);
			sgt.color(x, y, c);
		} else {
			if (x > y)swap(x, y);
			int mask = sgt.query(x, y);
			int ans = 0;
			for (int i = 1; i <= T; i++) {
				if (mask & (1 << i))ans++;
			}
			cout << ans << '\n';
		}
	}
}
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
