#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int p;
		cin>>p;

		int cnt=0;
		while(p>2){
			int m1=p/3;
			int m2=m1;
			int m3=p-m1-m2;
			p=m3;
			cnt+=m1;
//			cout<<m1<<' '<<m2<<' '<<m3<<'\n';
		}
		if(p<=2){
			cout<<cnt<<'\n';
			continue;
		}
		
		
	}
	
	return 0;
}
