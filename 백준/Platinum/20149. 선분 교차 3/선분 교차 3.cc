#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll ccw(pll p1, pll p2, pll p3) {
	ll s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
	s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

	if (s > 0) return 1;
	else if (s == 0) return 0;
	else return -1;
}

bool iscross(pair<pll, pll> l1, pair<pll, pll> l2) {
	pll p1 = l1.first;
	pll p2 = l1.second;
	pll p3 = l2.first;
	pll p4 = l2.second;

	ll p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	ll p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	if (p1p2 == 0 && p3p4 == 0) {
		if (p1 > p2) swap(p2, p1);
		if (p3 > p4) swap(p3, p4);

		return p3 <= p2 && p1 <= p4;
	}

	return p1p2 <= 0 && p3p4 <= 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	pll p1, p2, p3, p4;
	cin >> p1.first >> p1.second >> p2.first >> p2.second;
	cin >> p3.first >> p3.second >> p4.first >> p4.second;

	cout << fixed;
	cout.precision(9); // 상대오차 10^-9

	if (iscross({ p1,p2 }, { p3,p4 })) {
		cout << 1 << "\n";
		if (p1 > p2) swap(p2, p1);
		if (p3 > p4) swap(p3, p4);
		// 한 점에서 만남
		if (p2 == p3) {
			cout << p2.first << " " << p2.second;
			exit(0);
		}
		else if (p1 == p4) {
			cout << p1.first << " " << p1.second;
			exit(0);
		}

		if (p1.first != p2.first && p3.first != p4.first) {
			double p1p2 = (double)(p1.second - p2.second) / (double)(p1.first - p2.first);
			double p3p4 = (double)(p3.second - p4.second) / (double)(p3.first - p4.first);

			// 직선의 기울기가 동일
			if (p1p2 == p3p4) {
				// 한점에서 교차하지 않는 경우(일치)
				exit(0);
			}

			// y = p1p2 * x + b1
			double b1 = p1.second - p1p2 * p1.first;
			// y = p3p4 * x + b3
			double b3 = p3.second - p3p4 * p3.first;

			double x = (double)(b3 - b1) / (double)(p1p2 - p3p4);
			double y = p1p2 * x + b1;

			cout << x << " " << y;
		}
		else {
			if (p1.first == p2.first && p3.first != p4.first) {
				double p3p4 = (double)(p3.second - p4.second) / (double)(p3.first - p4.first);
				double b3 = p3.second - p3p4 * p3.first;

				// x = p1.first
				double x = p1.first;
				double y = p3p4 * x + b3;
				cout << x << " " << y;
			}
			else if (p1.first != p2.first && p3.first == p4.first) {
				double p1p2 = (double)(p1.second - p2.second) / (double)(p1.first - p2.first);
				double b1 = p1.second - p1p2 * p1.first;

				double x = p3.first;
				double y = p1p2 * x + b1;
				cout << x << " " << y;
			}
		}
	}
	else cout << 0;


	return 0;
}