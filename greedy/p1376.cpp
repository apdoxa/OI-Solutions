#include <bits/stdc++.h>
using namespace std;
#define i64 long long
const int N=1e4+1;
i64 min(i64 x,i64 y){
	return x>y?y:x;
}
int main(){
	int n,s;
	int c,y;

	cin>>n>>s;
	cin>>c>>y;
	
	i64 total_cost=0;
	i64 cost=c;
	total_cost+=c*y;//第一周生产y台

	for (int i = 1; i < n; i++)
	{
		cin>>c>>y;
		cost=min(cost+s,c);//上周维护至今或本周生产 取最小值
		total_cost+=y*cost;
	}
	cout<<total_cost;
	
	return 0;
}