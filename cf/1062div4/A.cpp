#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a==b&b==c&&c==d){
			cout<<"YES"<<'\n';
		}else{
			cout<<"NO"<<'\n';
		}
	}
	return 0;
}
