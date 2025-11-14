#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	vector<ll> pns;
	for(int i=2;i<=500;i++){
		bool va=true;
		for(int j=2;j<=500;j++){
			if(gcd(i,j)!=1&&gcd(i,j)!=i){
				va=false;
			}
		}
		if(va){
			pns.emplace_back(i);
		}
	}
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<ll> arr(n);
		bool chk1odd=false;
		ll mid=INT64_MAX;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			mid=min(mid,arr[i]);
			if(arr[i]%2==1){
				chk1odd=true;
			}
		}
		if(chk1odd){
			cout<<2<<'\n';
			continue;
		}
		
		ll curgcd=arr[0];
		for(int i=1;i<n;i++){
			curgcd=gcd(curgcd,arr[i]);
		}
		for(int i=0;i<pns.size();i++){
			if(gcd(curgcd,pns[i])==1){
				cout<<pns[i]<<'\n';
				break;
			}
		}
		
	}
	return 0;
}
