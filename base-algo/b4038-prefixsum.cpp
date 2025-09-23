#include <bits/stdc++.h>
using namespace std;

const int N=1e4+1;
int arr[N],sum[N];

inline int pre(int x,int y){
	return sum[y]-sum[x-1];
}
int main(){
	int q;
	sum[0]=0;
	cin>>q;
	while (q--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			sum[i+1]=sum[i]+arr[i];
		}
		if(n==1){
			cout<<"Yes"<<'\n';
			continue;
		}
		bool found=false;

		for(int i=1;i<n;i++){
			if(pre(1,i)==pre(i+1,n)){
				found=true;
				break;
			}
		}

		if(found){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
		
		
	}
	
	return 0;
}