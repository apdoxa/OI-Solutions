#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;

		vector<int> qr(q + 10);
		vector<int> m(n + 10);

		vector<int> b_pos;
		for (int i = 0; i < n; i++) {
			char mc;
			cin >> mc;
			if (mc == 'A') {
				m[i] = 0;
			} else if (mc == 'B') {
				m[i] = 1;
				b_pos.push_back(i);
			}

		}
		sort(b_pos.begin(),b_pos.end());
		for (int i = 0; i < q; i++) {
			cin >> qr[i];
		}

		for (int i = 0; i < q; i++) {
			int midx = 0;
			int cnt = 0;
			int cycles = 0;


			while (qr[i]>0) {
				//跳步
				if (b_pos.empty()) {
					cnt += qr[i];
					break;
				}
				//find next b
				int next_b = -1,dist;
				for (int j = 0; j < b_pos.size(); j++) {
					if (midx <= b_pos[j]) {
						next_b = b_pos[j];
						break;
					}
				}//lower_bound优化代码逻辑

				//当前循环没有b机器了
				if (next_b == -1) {
					dist=n-midx;
				} else {
					dist=next_b-midx;
				}
				
				if(qr[i]<=dist){
					cnt+=qr[i];
					break;//走完了
				}
				cnt+=dist;
				qr[i]-=dist;
				
				if(next_b!=-1){
					qr[i]>>=1;
					cnt++;
					midx=(next_b+1)%n;
				}else{
					midx=0;
				}
				if(midx>=n){
					midx=midx-n;
				}
			}
			cout << cnt << '\n';

		}


	}
	return 0;
}

