#include <bits/stdc++.h>
using namespace std;
#define u64 unsigned long long
u64 w[64];//提前计算权重
u64 p[21];
int n,k;
u64 maxs=0;
void dfs(int idx,u64 state,u64 score){
	if(idx==n){
		maxs=max(maxs,score);
		return ;
	}

	//不选第i个人
	dfs(idx+1,state,score);

	//选第i个人
	u64 n_state=state ^ p[idx];
	u64 n_s=0;

	//偶数能力抵消，直接不计入就好
	for (int i = 0; i < k; i++)
	{
		if(n_state&(1ULL <<i)){
			n_s+=w[i];
		}
	}

	//搜索新状态
	dfs(idx+1,n_state,n_s);
}
int main(){
	ios::sync_with_stdio(false);

	cin>>n>>k;

	//预先计算权重
	for(int i=0;i<k;i++){
		w[i]=(1ULL<<(k-1-i));//转0-based并计算幂
	}
	for (int i = 0; i < n; i++)
	{
		p[i]=0;
		int c;
		cin>>c;
		for (int j = 0; j < c; j++)
		{
			int abi;
			cin>>abi;
			abi--;//0-based

			p[i] |= (1ULL<<abi);//set ability of bit
		}
		
	}
	dfs(0,0,0);
	cout<<maxs<<'\n';

	return 0;
}