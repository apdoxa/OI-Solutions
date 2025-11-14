#include <bits/stdc++.h>
using namespace std;
struct Car {
	int x0, v0, a;
};
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m, L, V;
		cin >> n >> m >> L >> V;
		long long V2 = 1LL * V * V;

		vector<Car> cars(n);
		vector<int> sensors(m);
		for (int i = 0; i < n; i++) {
			cin >> cars[i].x0 >> cars[i].v0 >> cars[i].a;
		}
		//传感器已排序
		for (int i = 0; i < m; i++) {
			cin >> sensors[i];
		}
		int ocnt = 0;
		vector<pair<int, int>> rng;
		for(int i = 0; i<n; i++) {
			int x0 = cars[i].x0, v0 = cars[i].v0, a = cars[i].a;
			long long v02 = 1LL * v0*v0;
			int start = x0, end = x0 - 1; //初始无效

			if(a == 0) {
				//匀速且超速
				if (v0 > V) {
					end = L; //随便找一个传感器，最大?
				} 
			} else if(a>0) {
				if (v0 > V) {
					end = L; //随便找一个传感器，最大?
				} else if (v0 < V) {
					int s=floor((V2-v02)/(2.0*a));//加速到v0所需距离
					start=x0+s;//在L内则超速但未判定
					end=L;//[start,L]
				}
				//V0=V速度不变
			} else {
				//a<0
				if(v0>V){
					int s=floor((V2-v02)/(2.0*(a)));
					int stop=ceil(v02/2.0*(-a));
					end=x0+min({s,L-x0,stop});
				}

			}
			if(start<=end){
				auto it=lower_bound(sensors.begin(),sensors.end(),start);
				if(it!=sensors.end()&&*it<=end){
					ocnt++;
					int l=it-sensors.begin();
					//找到最后一个<=end的索引->找大于等于再减1
					auto it_r=upper_bound(sensors.begin(),sensors.end(),end);
					int r=it_r-sensors.begin()-1;
					//超速区间
					rng.emplace_back(l,r);
				}
			}
		}
		sort(rng.begin(),rng.end(),[](pair<int,int>& a,pair<int,int>&b){
			return a.second<b.second;
		});
		int k=0,last=-1;
		for(int i=0;i<(int)rng.size();i++){
			if(last<rng[i].first){
				k++;
				last=rng[i].second; //last->超速区间
			}
		}
		cout<<ocnt<<" "<<m-k<<'\n';
	}
	

	return 0;
}
