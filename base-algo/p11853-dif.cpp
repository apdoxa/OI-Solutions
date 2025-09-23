#include <bits/stdc++.h>
using namespace std;
const int N=1e6+2;
int arr[N]={0};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		arr[x]++;
		arr[y+1]--;
	}
	int max=0;
	for(int i=0;i<=1e6;i++){
		arr[i]+=arr[i-1];
		if(arr[i]>max){
			max=arr[i];
		}
	}
	cout<<max<<'\n';


	return 0;
}
