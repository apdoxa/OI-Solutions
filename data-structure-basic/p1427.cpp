#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	int a[101];
	ios::sync_with_stdio(false);
	cin.tie(0);

	int p=0;
	while (true)
	{
		int n;
		cin>>n;
		if(n==0)break;
		a[p]=n;
		p++;
	}
	for(int i=p-1;i>=0;i--){
		cout<<a[i]<<" ";
	}
	cout<<'\n';
	
}