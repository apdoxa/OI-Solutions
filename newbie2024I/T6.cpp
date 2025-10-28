#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int main(){
	int a[3]={0,0,0};
	int x,y;
	cin>>x>>y;
	a[x-1]++;
	a[y-1]++;
	int index=-1;
	for(int i=0;i<3;i++){
		if(a[i]==2){
			cout<<'0'<<'\n';
			return 0;
		};
		if(a[i]==0)index=i;
	}
	cout<<index+1<<'\n';

	return 0;
}