#include <bits/stdc++.h>
using namespace std;
int main(){
	double n;
	cin>>n;
	double ans=(1-((((n-1)/n))*(((n-1)/n))*(((n-1)/n))))*n;
	cout<<fixed<<setprecision(6)<<ans<<endl;
	
	return 0;
}
