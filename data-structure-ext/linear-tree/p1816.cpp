#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=1e5+10;
int m,n;
vector<int> a;
class SGT {
#define TN int now=1,int l=1,int r=m
#define mid (((r-l)>>1)+l)
#define LS now<<1,l,mid
#define RS now<<1|1,mid+1,r
private:
	int no[N<<2];
	void pushup(int now){
		no[now]=min(no[now<<1],no[now<<1|1]);
	}
public:
	void build(TN){
		if(l==r){
			no[now]=a[l];
			return;
		}
		build(LS),build(RS);
		pushup(now);
	}
	int query(int a,int b,TN){
		if(a<=l&&r<=b){
			return no[now];
		}
		int ans=INT64_MAX;
		if(a<=mid)ans=min(query(a,b,LS),ans);
		if(b>mid)ans=min(ans,query(a,b,RS));
		
		return ans;
	}
}sgt;
void solve(){
	cin>>m>>n;
	a.resize(m+1);
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	sgt.build();
	while(n--){
		int x,y;
		cin>>x>>y;
		cout<<sgt.query(x,y)<<' ';
	}
}
signed main(){
	cin.tie(0),cout.tie(0)->sync_with_stdio(0);
	solve();
	return 0;
}
