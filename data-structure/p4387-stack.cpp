#include <bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	stack<int> st;

	cin>>q;
	while (q--)
	{
		int n;
		int a[100001],b[100001];
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}

		int head=0;
		for(int i=0;i<n;i++){
			st.push(a[i]);
			while (st.top()==b[head])
			{
				st.pop();
				head++;
				if(st.empty())break;
			}
		}
		if(st.empty()){
			cout<<"Yes"<<'\n';
		}else{
			cout<<"No"<<'\n';
		}
		while(!st.empty())st.pop();//清空栈
	}
	return 0;
}