#include <bits/stdc++.h>
using namespace std;
long long calc(int x){
	int ate=x;
	int sticks=x;

	while (sticks>=3)
	{
		int get=sticks/3;
		//兑换
		ate+=sticks/3;
		sticks =sticks%3+get;
	}
	return ate;
	
}
//二分题解
void binary_search(){
	int n;
	cin>>n;

	//range
	int x=1,y=n;
	int ans=n;
	while (x<=y)
	{
		int mid=(x+y)/2;
		int total=calc(mid);
		if(total>=n){
			//超过，缩小范围
			y=mid-1;
			ans=mid;
		}else{
			//小了，增大范围
			x=mid+1;
		}
	}
	cout<<ans<<'\n';
}
//暴力枚举题解 O(n)
void violence(){
	int n;
	cin>>n;
	
	int stick=0;
	int ice=0;
	int buy=0;
	while (ice<n)
	{
		if(stick==3){
			stick=1;
			ice++;
		}else{
			buy++;
			ice++;
			stick++;
		}
	}
	cout<<buy<<'\n';
}
int main(){
	//violence()	
	binary_search();

	return 0;
}