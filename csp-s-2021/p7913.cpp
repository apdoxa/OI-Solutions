#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> in;
priority_queue<int, vector<int>, greater<int>> out;
#define ll long long
#define ft(i, x) for (int i = 1; i <= x; i++)
#define fz(i, x) for (int i = 0; i < x; i++)
//问的累计停靠廊桥的航班数，而不是最大并发数

// n -> 有n个廊桥数时候最大航班数，使用前缀和优化查询速度
vector<int> calc(vector<pii> &fls, int n)
{
	// 从小到大排序,stl pair默认先比较first,相同再比较second,但是本题指明不存在同时降落的航班
	sort(fls.begin(), fls.end());
	//idle使用优先队列
	//1.保证先到先得，小编号先被使用
	//2.便于前缀和计算

	//priority_queue<int>这是大堆根

	//小根堆
	//利用优先队列，将离开时间最早的航班放在前
	priority_queue<pii,vector<pii>,greater<pii>> busy;
	//先到先得，故优先小航班
	priority_queue<int,vector<int>,greater<int>> idle;

	//初始化，所有廊桥均空闲
	//分配n个可用廊桥
	vector<int> res(n+1,0);
	ft(i,n){
		idle.push(i);
	}
	//按时间顺序（已排序）遍历每架飞机，计算最大廊桥占用
	for(auto&fl:fls){
		//有可走的飞机就走,first记录离开时间
		while (!busy.empty()&&busy.top().first<=fl.first)
		{
			idle.push(busy.top().second);
			busy.pop();
		}
		//有空位就分配廊桥
		if (!idle.empty())
		{
			//分配一个廊桥
			int bridge=idle.top();
			idle.pop();
			busy.push({fl.second,bridge});
			res[bridge]++;
		}
		//没有就直接分配远机位，不参与后续廊桥的分配
	}
	ft(i,n){
		res[i]+=res[i-1];//前缀和
	}
	return res;
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	vector<pii> domest(m1), inter(m2);
	fz(i, m1)
	{
		cin >> domest[i].first >> domest[i].second;
	}
	fz(i, m2)
	{
		pair<int, int> p;
		cin >> inter[i].first >> inter[i].second;
	}
	vector<int> dom_res=calc(domest,n);
	vector<int> int_res=calc(inter,n);

	int ans=0;
	for(int i=0;i<=n;i++){

		ans=max(ans,dom_res[i]+int_res[n-i]);
	}

	cout<<ans<<'\n';

	return 0;
}