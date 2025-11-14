#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 10;
ll n;

class SGT {
private:
	ll node[N << 2], tag[N << 2];
	
	inline void apply(ll now, ll mv) {
		node[now] *= mv;
		tag[now] *= mv;
	}
	
	inline void pushdown(ll now) {
		if (tag[now] != 1) {
			apply(now << 1, tag[now]);
			apply(now << 1 | 1, tag[now]);
			tag[now] = 1;
		}
	}
	
	inline void pushup(ll now) {
		node[now] = node[now << 1] + node[now << 1 | 1];
	}
	
public:
	inline void build(ll now = 1, ll l = 1, ll r = n) {
		tag[now] = 1;
		if (l == r) {
			node[now] = 1;
			return;
		}
		ll mid = ((r - l) >> 1) + l;
		build(now << 1, l, mid);
		build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	
	inline void mod_mul(ll a, ll b, ll now = 1, ll l = 1, ll r = n) {
		if (a <= l && r <= b) {
			apply(now, 2);
			return;
		}
		pushdown(now);
		ll mid = ((r - l) >> 1) + l;
		if (a <= mid) mod_mul(a, b, now << 1, l, mid);
		if (mid < b) mod_mul(a, b, now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	
	inline void mod_add(ll pos, ll val, ll now = 1, ll l = 1, ll r = n) {
		if (l == r) {
			node[now] += val;
			return;
		}
		pushdown(now);
		ll mid = ((r - l) >> 1) + l;
		if (pos <= mid) mod_add(pos, val, now << 1, l, mid);
		else mod_add(pos, val, now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	
	inline ll query(ll val, ll now = 1, ll l = 1, ll r = n) {
		if (l == r) return l;
		pushdown(now);
		ll mid = ((r - l) >> 1) + l;
		if (node[now << 1] >= val) return query(val, now << 1, l, mid);
		else return query(val - node[now << 1], now << 1 | 1, mid + 1, r);
	}
	
	inline ll query_sum(ll a, ll b, ll now = 1, ll l = 1, ll r = n) {
		if (a <= l && r <= b) return node[now];
		pushdown(now);
		ll mid = ((r - l) >> 1) + l;
		ll res = 0;
		if (a <= mid) res += query_sum(a, b, now << 1, l, mid);
		if (mid < b) res += query_sum(a, b, now << 1 | 1, mid + 1, r);
		return res;
	}
} sgtt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll q;
	cin >> n >> q;
	string s;
	cin >> s;
	s = "n" + s;
	
	sgtt.build();
	
	while (q--) {
		int op;
		cin >> op;
		if (op == 2) {
			ll i;
			cin >> i;
			ll idx = sgtt.query(i);
			cout << s[idx] << '\n';  
		} else {
			ll l, r;
			cin >> l >> r;
			ll pos1 = sgtt.query(l);
			ll pos2 = sgtt.query(r);
			
			if (pos1 == pos2) {
				sgtt.mod_add(pos1, r - l + 1);
				continue;
			}
			
			ll sum_before_pos1 = (pos1 > 1) ? sgtt.query_sum(1, pos1 - 1) : 0;
			ll add1 = sum_before_pos1 + sgtt.query_sum(pos1, pos1) - l + 1;
			
			ll sum_before_pos2 = sgtt.query_sum(1, pos2 - 1);
			ll add2 = r - sum_before_pos2;
			
			sgtt.mod_add(pos1, add1);
			sgtt.mod_add(pos2, add2);
			
			if (pos1 + 1 <= pos2 - 1) {
				sgtt.mod_mul(pos1 + 1, pos2 - 1);
			}
		}
	}
	
	return 0;
}

