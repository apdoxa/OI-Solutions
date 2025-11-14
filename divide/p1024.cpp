//review:精度问题
#include <bits/stdc++.h>
using namespace std;
double a, b, c, d;
double f(double x) {
	return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}
stack<double> roots;
int main() {
	cin >> a >> b >> c >> d;

	for (int i = -100; i < 100; i += 1) {
		double l = i, r = i + 1, fx1 = f(l), fx2 = f(r), ans;
		if (fx1 == 0) {
			if (!roots.empty() && !roots.top() - fx1 < 1.0) {
				cout << fixed << setprecision(2) << l << ' ';
				roots.push(l);
				if (roots.size() >= 3) {
					return 0;
				}
			} else {
				cout << fixed << setprecision(2) << l << ' ';
				roots.push(l);
			}
			continue;
		}
		if (fx2 == 0) {
			continue;
		}

		if (fx1 * fx2 <= 0.0) {
			while (r - l >= 1e-8) {
				double mid = (r + l) / 2.0;
				if (fx1 * f(mid) <= 0.0) {
					ans = mid;
					r = mid - 1e-5;
				} else {
					l = mid + 1e-5;
				}
			}

			if (!roots.empty() && !roots.top() - ans < 1.0) {
				cout << fixed << setprecision(2) << ans << ' ';
				roots.push(ans);
				if (roots.size() >= 3) {
					return 0;
				}
			} else {

				cout << fixed << setprecision(2) << l << ' ';
				roots.push(l);

				continue;
			}
		}
	}

	return 0;
}
/*
//LLM AC ans:
#include <bits/stdc++.h>
using namespace std;
double a, b, c, d;
double roots[3];  // 存储已输出的根（去重）
int cnt = 0;

// 用乘法代替pow(x,3)，精度更高
double f(double x) {
	return a*x*x*x + b*x*x + c*x + d;  // 避免pow的精度误差
}

// 检查是否重复根（差的绝对值小于1e-4视为同一根）
bool is_duplicate(double x) {
	for (int i = 0; i < cnt; i++) {
		if (fabs(x - roots[i]) < 1e-4) return true;
	}
	return false;
}

int main() {
	cin >> a >> b >> c >> d;
	
	for (int i = -100; i < 100; i++) {  // 遍历每个小区间[i, i+1]
		double l = i, r = i + 1;
		double fx1 = f(l), fx2 = f(r);
		
		// 1. 检查左端点是否为根
		if (fabs(fx1) < 1e-8) {  // 允许微小误差
			if (!is_duplicate(l)) {  // 不重复才输出
				roots[cnt++] = l;
				cout << fixed << setprecision(2) << l << ' ';
				if (cnt >= 3) return 0;
			}
			l += 1e-8;  // 移动左端点，避免重复判断
			fx1 = f(l);  // 更新函数值
		}
		
		// 2. 检查右端点是否为根
		if (fabs(fx2) < 1e-8) {
			if (!is_duplicate(r)) {
				roots[cnt++] = r;
				cout << fixed << setprecision(2) << r << ' ';
				if (cnt >= 3) return 0;
			}
			r -= 1e-8;  // 移动右端点，避免重复判断
			fx2 = f(r);
		}
		
		// 3. 检查区间内是否有根（排除端点后）
		if (fx1 * fx2 <= 0) {  // 区间内存在根
			// 二分查找根（标准实数二分）
			while (r - l > 1e-8) {
				double mid = (l + r) / 2;
				double fmid = f(mid);
				if (fx1 * fmid <= 0) {
					r = mid;
				} else {
					l = mid;
				}
			}
			double candidate = (l + r) / 2;  // 根的近似值
			if (!is_duplicate(candidate)) {  // 去重后输出
				roots[cnt++] = candidate;
				cout << fixed << setprecision(2) << candidate << ' ';
				if (cnt >= 3) return 0;
			}
		}
	}
	return 0;
}*/

