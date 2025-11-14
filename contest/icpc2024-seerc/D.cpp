	#include <bits/stdc++.h>
	#define ll long long
	using namespace std;
	int main() {
		int n;
		cin >> n;
		priority_queue<ll> q;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			q.push(x);
			sum += x;
		}
		//D first turn%2==1 ->D turn%2==0 P
		ll turn = 1;
		if(q.top()==0){
			cout<<"Puss in Boots\n";
		}else{
			sum-=q.top();
			if(sum>=n){
				cout<<"Puss in Boots\n";
			}else{
				cout << "Donkey\n";
			}
		}
		return 0;
	//	while (true) {
	//		if (turn % 2 == 1) {
	//			//D
	//			if (q.empty()) {
	//				cout << "Puss in Boots\n";
	//				return 0;
	//			} else {
	//				sum -= q.top();
	//				q.pop();
	//				turn++;
	//			}
	//		} else {
	//			//P
	//			if (!q.empty() && sum >= n) {
	//				ll todocnt = n;
	//				ll topn=q.top();
	//				while(todocnt>0){
	//					
	//				}
	//				
	//				turn++;
	//			} else {
	//				cout << "Donkey\n";
	//				return 0;
	//			}
	//		}
	//	}
	}
