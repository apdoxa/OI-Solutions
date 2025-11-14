#include <bits/stdc++.h>
using namespace std;
struct e {
	int u, v, w;
};
int n, m, k;
vector<e> es;
bool cmp(e a, e b) {
	//代价升序
	return a.w < b.w;
}
int pa[1005];
int find(int x){
	return (pa[x]==x)?x:pa[x]=find(pa[x]);
}
void merge(int x,int y){
	int pax=find(x),pay=find(y);
	pa[x]=pay;
}
void kruskal() {
	int tol=0;
	int cost=0;
	for(int i=0;i<m;i++){
		//遍历每条边
		int pax=find(es[i].u),pay=find(es[i].v);
		if(pax!=pay){
			merge(pax,pay);
			tol++;
			cost+=es[i].w;
			if(tol==n-k){
				cout<<cost<<'\n';
				return ;
			}
		}
	}
	cout<<"No Answer\n";
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);

	//n个节点，m条可连边，求生成k个树最小代价

	cin >> n >> m >> k;
	if(n==k){
		cout<<0<<'\n';
		return 0;
	}
	for(int i=0;i<n;i++){
		pa[i]=i;
	}
	es.resize(m);
	for (int i = 0; i < m; i++) {
		int x,y,w;
		cin>>x>>y>>w;
		x--,y--;
		es[i].u=x,es[i].v=y,es[i].w=w;
	}
	sort(es.begin(), es.end(), cmp);
	kruskal();
	return 0;
}
