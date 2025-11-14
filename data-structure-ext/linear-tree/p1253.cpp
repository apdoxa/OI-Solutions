#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pii pair<int,int>
////NOTE!!! INF,-INF记得开够
using namespace std;
const int N=1e6+10;
int n,q;
vector<int> a;
class SGT{
	//线段树维护当前最大值
private:
#define TN int now=1,int l=1,int r=n
#define mid (((r-l)>>1)+l)
#define LS now<<1,l,mid
#define RS now<<1|1,mid+1,r
	int no[N<<2],cge[N<<2],add[N<<2];
	void apply_cge(int mv,TN){
		no[now]=mv;
		add[now]=0;
		cge[now]=mv;
	}
	void apply_add(int mv,TN){
		no[now]+=mv;
		add[now]+=mv;
	}
	void pushup(int now){
		no[now]=max(no[now<<1],no[now<<1|1]);
	}
	void pushdown(TN){
		if(cge[now]!=1e18){
			apply_cge(cge[now],LS),apply_cge(cge[now],RS),cge[now]=1e18;
		}
		if(add[now]!=0){
			apply_add(add[now],LS),apply_add(add[now],RS),add[now]=0;
		}
	}
public:
	void build(TN){
		cge[now]=1e18;
		if(l==r){
			no[now]=a[l];
			return;
		}
		build(LS),build(RS);
		pushup(now);
	}
	void mod_cge(int a,int b,int val,TN){
		if(a<=l&&r<=b){
			apply_cge(val,now,l,r);
			return;
		}
		pushdown(now);
		if(a<=mid)mod_cge(a,b,val,LS);
		if(b>mid)mod_cge(a,b,val,RS);
		pushup(now);
	}
	void mod_add(int a,int b,int val,TN){
		if(a<=l&&r<=b){
			apply_add(val,now,l,r);
			return;
		}
		pushdown(now);
		if(a<=mid)mod_add(a,b,val,LS);
		if(b>mid)mod_add(a,b,val,RS);
		pushup(now);
	}
	int query(int a,int b,TN){
		if(a<=l&&r<=b){
			return no[now];
		}
		pushdown(now);
		int maxn=-1e18;
		if(a<=mid)maxn=max(query(a,b,LS),maxn);
		if(b>mid)maxn=max(query(a,b,RS),maxn);
		return maxn;
	}
	
}sgt;
void solve(){
	cin>>n>>q;
	a.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sgt.build();
	while(q--){
		int op,l,r,x;
		cin>>op>>l>>r;
		if(op==1){
			cin>>x;
			//chang to x
			sgt.mod_cge(l,r,x);
		}else if(op==2){
			cin>>x;
			//add x
			sgt.mod_add(l,r,x);
		}else if(op==3){
			//query
			cout<<sgt.query(l,r)<<'\n';
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
