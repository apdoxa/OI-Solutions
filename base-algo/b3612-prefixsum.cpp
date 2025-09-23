#include <bits/stdc++.h>
using namespace std;
int main(){
	const int N=1e5+2;
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m,arr[N],sum[N];
	memset(sum,0,sizeof(sum));
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>arr[i];

		//cal prefix sum
		sum[i+1]+=sum[i]+arr[i];
	}
	cin>>m;
	int x,y;
	while(m--){
		cin>>x>>y;
		cout<<(sum[y]-sum[x-1])<<'\n';
	}

}