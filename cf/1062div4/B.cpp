#include <bits/stdc++.h>
using namespace std;
int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;

		map<char, int> count;
		for (int i = 0; i < t.size(); i++) {
			if (count.count(t[i])) {
				count[t[i]] += 1;
			} else {
				count[t[i]] = 1;
			}
		}
		map<char, int> chek;
		bool vaild = true;
		for (int i = 0; i < s.size(); i++) {
			if (!count.count(s[i])) {

				vaild = false;
				break;
			}
			if (chek.count(s[i])) {
				chek[s[i]] += 1;
			} else {
				chek[s[i]] = 1;
			}
		}
		if (!vaild) {
			cout << "NO" << '\n';
			continue;
		}
		for (int i = 0; i < n; i++) {
			//cout<<chek['a']<<" "<<count['a']<<"www\n";
			if (chek[s[i]] != count[s[i]]) {
				vaild = false;
				break;
			}
		}
		if (!vaild) {
			cout << "NO" << '\n';
			continue;
		}

		cout << "YES" << '\n';
	}
	return 0;
}
