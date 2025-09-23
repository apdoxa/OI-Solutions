#include <bits/stdc++.h>
using namespace std;
const int N=1e3+1;
struct T {
	int time;
	int index;
	int wait;
} t[N];
bool cmp(T a,T b){
	return a.time<b.time;
}
int main(){
	int cur_t=0;


	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		t[i].wait=0;
		t[i].index=i+1; //1-based index
		cin>>t[i].time;
	}
	sort(t,t+n,cmp);
	double total=0;
	for (int i = 0; i < n; i++)
	{
		total +=t[i].time*(n - 1 -i);
		cout<<t[i].index;
		if(i!=n-1){
			cout<<' ';
		}else{
			cout<<'\n';
		}
	}
	cout<<fixed<<setprecision(2)<<total/n<<'\n';
	//第i (0-based)个人的接水时间会被后续n-1-i个人等待
	//a[i]*(n-1-i)

	return 0;
}