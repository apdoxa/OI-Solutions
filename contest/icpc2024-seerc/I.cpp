#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 10;
ll n;

class SGT{
#define TN int now=1,int l=1,int r=n
#define mid (((r-l)>>1)+l)
#define LS now<<1,l,mid
#define RS now<<1|1,mid+1,r
private:
	int no[N<<2],mul[N<<2];
	void apply_mul(int val,TN){
		//乘法操作影响之前的加法操作，故pushdown先下传乘法再加法
		no[now]=no[now]*val;
		mul[now]=mul[now]*val;
	}
	void pushup(int now){
		no[now]=(no[now<<1]+no[now<<1|1]);
	}
	void pushdown(TN){
		if(mul[now]!=1){
			apply_mul(mul[now],LS),apply_mul(mul[now],RS),mul[now]=1;
		}
	}
public:
	void build(TN){
		mul[now]=1;
		if(l==r){
			no[now]=1;//单一数最大值就是自己
			return ;
		}
		build(LS),build(RS),pushup(now);//记得pushup
	}
	void mod_add(int pos,int val,TN){
		//当前节点是需求区间的子集
		if(l==r){
			no[now] += val;
			return;
		}
		pushdown(now,l,r);
		if(pos<=mid)mod_add(pos,val,LS);
		if(pos>mid)mod_add(pos,val,RS);
		pushup(now);
	}
	void mod_mul(int a,int b,TN){
		if(a<=l&&r<=b)return apply_mul(2,now,l,r);
		pushdown(now,l,r);
		if(a<=mid)mod_mul(a,b,LS);
		if(b>mid)mod_mul(a,b,RS);
		pushup(now);
	}
	int query(int pos,TN){
		if(l==r)return no[now];
		int maxn=0;
		pushdown(now,l,r);
		if(pos<=mid)maxn=(maxn+query(pos,LS));
		if(pos>mid)maxn=(maxn+query(pos,RS));
		return maxn;
	}
}sgt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll q;
	cin >> n >> q;
	string s;
	cin >> s;
	sgt.build();
	
	while (q--) {
		int op;
		cin >> op;
		if (op == 2) {
			ll i;
			cin >> i;
			ll idx = sgt.query(i);
			cout << s[idx - 1] << '\n';
		} else {
			ll l, r;
			cin >> l >> r;
			ll pos1 = sgt.query(l);
			ll pos2 = sgt.query(r);
			
			if (pos1 == pos2) {
				sgt.mod_add(pos1, r - l + 1);
				continue;
			}
			
			ll sum_before_pos1 = (pos1 > 1) ? sgt.query(1, pos1 - 1) : 0;
			ll add1 = sum_before_pos1 + sgt.query(pos1, pos1) - l + 1;
			
			ll sum_before_pos2 = sgt.query(1, pos2 - 1);
			ll add2 = r - sum_before_pos2;
			
			sgt.mod_add(pos1, add1);
			sgt.mod_add(pos2, add2);
			
			if (pos1 + 1 <= pos2 - 1) {
				sgt.mod_mul(pos1 + 1, pos2 - 1);
			}
		}
	}
	return 0;
}

