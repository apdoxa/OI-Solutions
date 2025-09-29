//TODO: review
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int a[N];
int n;
int dp_solution(){
	cin>>n;

	int x;
	cin>>x;
	int cur_sum=x;//以第一个为初始解
	int max_sum=cur_sum;//储存最大子序列和
	//DP Solution
	for (int i = 1; i < n; i++)
	{
		cin>>x;
		//只有两种前置状态，即单开新段和加入新的子段
		//前者多适用于字段和负数的时候，把x加入为负数的字段反而会拖累x，不如单开
		//极端情况下全负数序列
		cur_sum=max(x,cur_sum+x);
		max_sum=max(cur_sum,max_sum);
	}
	cout<<max_sum<<'\n';

	return 0;
}
int prefix_sum(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	int cur_sum=0;//S[0]=0 S[1]=a[0] ... S[n]=a[0]+..+a[n-1]
	int min_sum=0;//当前字段和=S[i+1]-min_pre 最大=最大-最小前缀
	int max_sum=-2147483647;//动态储存最大字段和

	for (size_t i = 0; i < n; i++)
	{
		int x;
		cin>>x;
		cur_sum+=x;
		
		int cur_child=cur_sum-min_sum;
		if (cur_child>max_sum)
		{
			max_sum=cur_child;
		}

		if(cur_sum<min_sum){
			min_sum=cur_sum;
		}
		
	}
	
	cout<<max_sum;

	return 0;
}
int main(){
	return prefix_sum();
}