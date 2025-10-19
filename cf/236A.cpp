#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
int main(){
	set<char> seta;
	char buf[200];

	//odd奇数
	cin>>buf;
	int idx=0;
	while (buf[idx]!='\0')
	{
		seta.emplace(buf[idx]);
		idx++;
	}
	if(seta.size()%2==0){
		cout<<"CHAT WITH HER!"<<'\n';
	}else{
		cout<<"IGNORE HIM!"<<'\n';
	}

	return 0;
}