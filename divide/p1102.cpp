#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	long long n, c;
	cin >> n >> c;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	//a=b+c
	ll cnt = 0;
	sort(arr.begin(), arr.end());
	for(int i=0;i<n;i++){
		ll a=arr[i];
		ll b=a-c;
		//ll l=0,r=n-1;
		//ll first=-1,second=-1;
//		while(l<=r){
//			ll mid=((r-l)>>1)+l;
//			if(arr[mid]>=b){
//				first=mid;
//				r=mid-1;//降序找更小
//			}else{
//				l=mid+1;
//			}
//		}
//		l=0,r=n-1;
//		while(l<=r){
//			ll mid=((r-l)>>1)+l;
//			if(arr[mid]>b){
//				//first=second;
//				second=mid;
//				r=mid-1;//降序找更小
//			}else{
//				l=mid+1;
//			}
//		}
		auto start=lower_bound(arr.begin(),arr.end(),b),end=upper_bound(arr.begin(),arr.end(),b);
		//cout<<first<<" "<<second<<" "<<b<<'\n';
		if(start<end){
			cnt+=end-start;//不包含末尾b<arr[second]
		}
	}
	
	cout << cnt << '\n';
	return 0;
}
