#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k;

    if (n <= 0) {
        k = 24;
    } else if (n == 1) {
        k = 23;
    } else if (n == 2) {
        k = 12;
    } else if (n == 3) {
        k = 1;
    } else {
        k = 0;
    }

    if (k == 0) {
        cout << "0/1" << endl;
        return 0;
    }

    int gcd_val = __gcd(k, 24);/*  */
    int x = k / gcd_val;
    int y = 24 / gcd_val;

    cout << x << "/" << y << endl;

    return 0;
}
