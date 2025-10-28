#include <bits/stdc++.h>
using namespace std;
signed main() {
	vector<int> purenum = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	unordered_map<int, bool> pns;
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < (long long)purenum.size(); i++) {
		pns[purenum[i]] = true;
	}
	int len = 0;
	bool lastispure;
	int maxlen=0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) {
			len = 0;
			lastispure = false;
			continue;
		}

		bool isPure = pns.count(arr[i]);
		if (len == 0) {
			len = 1;
			lastispure = isPure;
		} else if (lastispure == isPure) {
			len++;
		} else {
			maxlen=max(maxlen,len);
			len = 1;
			lastispure = isPure;
		};
		maxlen=max(maxlen,len);
	}

	cout << maxlen << '\n';
	return 0;
}
