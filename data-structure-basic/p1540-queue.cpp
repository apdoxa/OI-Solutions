#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	queue<int> cached;
	bool mmap[10000]={false};
	int mem_size,length,count=0;
	cin>>mem_size>>length;
	for(int i=0;i<length;i++){
		int a;
		cin>>a;
		if(mmap[a])continue;
		if(mem_size<=cached.size()){
			int old=cached.front();
			cached.pop();
			mmap[old]=false;
		}
		count++;
		cached.push(a);
		mmap[a]=true;
	}
	cout<<count;

	return 0;
}