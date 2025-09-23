#include <bits/stdc++.h>
using namespace std;
const int MAXN =1e6;
int n;
struct Act{
	int s;
	int e;
} act[MAXN];
bool cmp(Act a,Act b){
	return a.e<b.e;
}
int sel(){
	sort(act,act+n,cmp);
	int cnt=1;
	int end=act[0].e;
	for(int i=1;i<n;i++){
		if(act[i].s>=end){
			cnt++;
			end = act[i].e;
		}
	}
	return cnt;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>act[i].s>>act[i].e;
	}
	int res=sel();
	cout<<res<<'\n';
	return 0;
}