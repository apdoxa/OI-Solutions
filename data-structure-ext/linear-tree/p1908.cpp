#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pii pair<int,int>
using namespace std;
const int N = 5e5+10;
int n;
vector<int> a, b;
//线段树记录前方数值比a[i]大的个数
class SGT {
#define TN int now=1,int l=1,int r=n
#define mid (((r-l)>>1)+l)
#define LS now<<1,l,mid
#define RS now<<1|1,mid+1,r
private:
	int no[N << 2];

	inline void pushup(int now) {
		no[now] = no[now << 1] + no[now << 1 | 1];
	}
public:
	inline void update(int pos, TN) {
		if (l == r) {
			no[now] += 1;
			return ;
		}
		if (pos <= mid)update(pos, LS);
		if (pos > mid)update(pos, RS);
		pushup(now);
	}
	inline int query(int pos, TN) {
		if (r <= pos) {
			return no[now];
		}
		int res = query(pos, LS);//前方的，故必含有左子树
		if (mid < pos) {//如果范围包括右子树，则返回右子树
			res += query(pos, RS);
		}
		return res;
	}
} sgt;
void solve() {
	cin >> n;
	a.resize(n + 1), b.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	//先排序，这样去重后也是有序化的
	sort(b.begin() + 1, b.end());
	//unique将不重复的元素放在前方故unique位置-(b.begin()+1)即位前方不重复元素的长度
	int size = unique(b.begin() + 1, b.end()) - (b.begin() + 1);
	map<int, int> mmap;
	for (int i = 1; i <= size; i++) {
		//将数值从小到大映射到位置，从而实现数据离散化
		mmap[b[i]] = i;
	}
	int ans = 0;
	for (int i = n; i >= 1; i--) {
		int val = mmap[a[i]];//将数值映射到对应位置
		//第一个元素不存在逆序对(按照从后往前找)
		if (val > 1) {
			ans += sgt.query(val - 1);//查询当前位置之前的数值出现次数和
		}
		//a[i]元素个数加一，从而避免重复元素只计算一次
		sgt.update(val);
	}
	cout << ans << '\n';
}
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	//cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}
