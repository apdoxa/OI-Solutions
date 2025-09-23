#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e6+1;
struct F {
	int v;
	int cap;//capacity per day
} f[MAXN];
bool cmp(F a,F b){
	return a.v < b.v;
}
int solve(int n,int m){

	int val=0;
	sort(f,f+m,cmp);

	for (int i = 0; i < m; i++)
	{
		if(n==0)break;

		if (f[i].cap<=n)
		{
			n-=f[i].cap;
			val+=f[i].v*f[i].cap;
		}
		else
		{
			val+=n*f[i].v;
			n=0;//fulled
		}
		
	}
	


	return val;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin>>n>>m;
	for (int i = 0; i < m; i++)
	{
		cin>>f[i].v>>f[i].cap;
	}
	int res=solve(n,m);
	cout<<res<<'\n';
	
	return 0;
}