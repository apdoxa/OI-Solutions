#include <bits/stdc++.h>
using namespace std;
int main(){
	const long long p=1e9+7;
	long long op,x,y;
	cin>>op>>x>>y;
	if(op==1){
		cout<<(x+y)%p;
	}else if(op==2){
		long long ans=x-y%p;
		if(ans<0){
			ans+=p;
		}
		cout<<ans<<'\n';
	}else if(op==3){
		cout<<(x*y)%p;
	}
	
	return 0;
}
