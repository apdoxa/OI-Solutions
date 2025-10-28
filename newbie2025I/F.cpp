#include <bits/stdc++.h>
using namespace std;

int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	//垂直x轴
	if(x1==x2){
		cout<< 1<<" "<<0<<" "<<-(y1+y2)/2<<'\n';
		return 0;
	}
	//平行x轴
	if(y1==y2){
		cout<< 0<<" "<<1<<" "<<-(x1+x2)/2<<'\n';
		return 0;
	}
	
	int A = x2 - x1;
	int B = y2 - y1;
	int C = -(A/2 * (x1 + x2) + B/2 * (y1 + y2)) / 2;
	
	cout << A << " " << B << " " << C << endl;
	return 0;
}

