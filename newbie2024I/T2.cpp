#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int sq;
	cin>>sq;
	for(int i=1;i<=10;i++){
		if (pow(i,2)==sq)
		{
			cout<<"Y"<<'\n';
			return 0;
		}
	}
	cout<<"N"<<'\n';
	return 0;
}