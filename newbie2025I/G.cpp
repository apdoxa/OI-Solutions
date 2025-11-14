#include <bits/stdc++.h>
using namespace std;

int main() {
	double x1, y1, x2, y2;
	cin >> x1 >> y1;
	cin >> x2 >> y2;

	int A = 2 * (x2 - x1);
	int B = 2 * (y2 - y1);
	int C = (x1 * x1 + y1 * y1) - (x2 * x2 + y2 * y2);

	cout << A << " " << B << " " << C << '\n';
	return 0;
}

