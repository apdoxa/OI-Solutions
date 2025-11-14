#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> arr(n);
		
		vector<int> eve;
		vector<int> odd;

		
		for(int i=0;i<n;i++){
			cin>>arr[i];
			
			if(arr[i]%2==0){
				eve.push_back(arr[i]);
			}else{
				odd.push_back(arr[i]);
			}
		}
	
		if(!eve.empty()&&!odd.empty()){
			sort(arr.begin(),arr.end());
		}
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<'\n';
	}
	return 0;
}
