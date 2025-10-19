#include <iostream>
#define ii long long
using namespace std;
int main(){
	ii n,m,a;
	cin>>n>>m>>a;

	ii rows=(n+a-1)/a;//向上取整ceil(x)=floor(x+(a-1)/a)
	ii cols=(m+a-1)/a;
	cout<<rows*cols<<'\n';

	return 0;
}