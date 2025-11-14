#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
int n,m;
vector<int> a,dif;
//线段树维护差分
class SGT{
#define TN int now=1,int l=1,int r=n
#define mid (((r-l)>>1)+l)
#define LS now<<1,l,mid
#define RS now<<1|1,mid+1,r
private:
	int no[N<<2],tag[N<<2];
	void apply(int mv,TN){
		no[now]+=mv*(r-l+1);
		tag[now]+=mv;
	}
	void pushdown(TN){
		if(tag[now]!=0){
			apply(tag[now],LS),apply(tag[now],RS),tag[now]=0;
		}
	}
	void pushup(int now){
		no[now]=no[now<<1]+no[now<<1|1];
	}
public:
	void build(TN){
		if(l==r){
			no[now]=dif[l];//差分
			return;
		}
		build(LS),build(RS);
		pushup(now);
	}
	void add(int a,int b,int val,TN){
		if(a<=l&&r<=b){
			return apply(val,now,l,r);
		}
		pushdown(now,l,r);
		if(a<=mid)add(a,b,val,LS);
		if(b>mid)add(a,b,val,RS);
		pushup(now);
	}
	//差分还原原来数组
	int querysum(int a,int b,TN){
		if(a<=l&&r<=b){
			return no[now];
		}
		pushdown(now,l,r);
		int sum=0;
		if(a<=mid)sum+=querysum(a,b,LS);
		if(b>mid)sum+=querysum(a,b,RS);
		return sum;
	}
}sgt;
void solve(){
	cin>>n>>m;
	a.resize(n+1),dif.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1){
			dif[i]=a[i]-a[i-1];
		}else{
			dif[1]=a[1];
		}
	}
	sgt.build();
	while(m--){
		int op;
		cin>>op;
		
		if(op==1){
			int l,r,k,d;
			cin>>l>>r>>k>>d;
			sgt.add(l,l,k);
			if(l<r){
				sgt.add(l+1,r,d);
			}
			if(r+1<=n){
				sgt.add(r+1,r+1,-(r-l)*d-k);
			}
		}else if(op==2){
			int p;
			cin>>p;
			cout<<sgt.querysum(1,p)<<'\n';
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
