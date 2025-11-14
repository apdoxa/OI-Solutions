#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int x,y,q;
	cin>>x>>y>>q;
	if(x>=y){
		cout<<0<<'\n';
	}else{
		cout<<(y-x)/q+1<<'\n';
	}
	return 0;
}
