#include <bits/stdc++.h>
using namespace std;
int main() {
	int m, b, s;
	cin >> m >> b >> s;
	double beta = (b  * M_PI)/180.0;
	double st = (s * M_PI)/180.0;
	double alpha = beta - st;
	double g=10.0;

	double f=( g * sin(beta)) / sin(st);
	double fx=f*sin(alpha);
	double fy=f*cos(alpha);

	double y = abs(g-fy);
	double a = sqrt(pow(fx, 2) + pow(y, 2));
	cout <<fixed<<setprecision(6) <<a << '\n';
	return 0;
}
