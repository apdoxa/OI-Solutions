#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e4;
struct Itm{
	int w;
	int v;
} itm[MAXN];
int n,cap;
bool cmp(Itm a,Itm b){
	//float cmp!!!
	return (double)a.v/a.w>(double)b.v/b.w;
}
double solve(){
	sort(itm,itm+n,cmp);
	double val=0;
	for (int i = 0; i < n; i++)
	{
		if(cap==0)break;

		if(itm[i].w<=cap){
			val += itm[i].v;
			cap -= itm[i].w;
		}else{
			//放入部分
			val += (double) cap*((double)itm[i].v/(double)itm[i].w);
			cap=0;
		}
	}
	return val;
	
}
int main(){
	cin>>n>>cap;
	for(int i=0;i<n;i++){
		cin>>itm[i].w>>itm[i].v;
	}
	double res=solve();
	printf("%.2f\n",res);
	return 0;
}