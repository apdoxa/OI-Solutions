//TODO:简化
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<int> trees(n+1);
	int maxheight=-1;
	for(int i=1;i<=n;i++){
		cin>>trees[i];
		maxheight=max(maxheight,trees[i]);
	}
	
	int l=0,r=maxheight;
	int res=-1;
	while(l<=r){
		int mid=((r-l)>>1)+l;
		int sum=0;
		
		for(int i=1;i<=n;i++){
			if(trees[i]>=mid){
				sum+=trees[i]-mid;
			}
		}
		if(sum>=m){
			res=mid;
			l=mid+1;//升高砍少点
		}else{
			r=mid-1;
		}
	}
	if(res!=-1){
		cout<<res<<'\n';
	}else{
		cout<<"Nooooo\n";
	}
	return 0;
}
