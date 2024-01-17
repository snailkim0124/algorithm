#include <bits/stdc++.h>
#define y1 aaa
#define PI 3.14159265358979323846
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

double x1, y1, r1, x2, y2, r2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	cout << fixed;
	cout.precision(3);

	// 만나지 않는 경우
	if (pow(x2 - x1, 2) + pow(y2 - y1, 2) > pow(r1 + r2, 2)) {
		cout << 0.000;
	}
	// 포함된 경우
	else if (pow(x2 - x1, 2) + pow(y2 - y1, 2) <= pow(r1 - r2, 2)) {
		cout << PI * pow(min(r1, r2), 2);
	}
	// 겹쳐있는 경우
	else {
		double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		double t1 = 2 * acos((d * d + r1 * r1 - r2 * r2) / (2 * r1 * d));
		double t2 = 2 * acos((d * d + r2 * r2 - r1 * r1) / (2 * r2 * d));

		cout << 0.5 * r1 * r1 * (t1 - sin(t1)) + 0.5 * r2 * r2 * (t2 - sin(t2));
	}

	return 0;
}