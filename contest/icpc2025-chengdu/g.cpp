//WAWAWA2!!
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
	ll n,k,m;
	cin>>n>>k>>m;
	//所有数和1的gcd均为1
	if(k==1){
		cout<<1+(n-1)/2<<'\n';
	}else{
		if(m==0){
			//cout<<(n-1)/2+1<<'\n';
			cout<<floor(n/2.0)<<'\n';
		}else{
			if(k>=n){
				cout<<min(m,n)<<'\n';
			}else{
				ll nkcnt=0;
				//范围内的k倍数
				for(int i=1;i*k<=n;i++){
					nkcnt++;
				}
				//两两分配一个k的倍数{k,2k}...,向下取整
				ll nkgroup_nums=0;
				if(nkcnt==1){
					nkgroup_nums=1;
				}else{
					nkgroup_nums=(nkcnt-1)/2+1;
				}
				
				ll remain=n-nkcnt;//剩余非k倍数及剩余的k的倍数
				
				cout<<min(remain+nkgroup_nums,nkgroup_nums+m)<<'\n';
			}
		}
	}
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}
