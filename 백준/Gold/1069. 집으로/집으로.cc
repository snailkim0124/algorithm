#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

double x, y, d, t;
double res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cout << fixed;
	cout.precision(9);

	cin >> x >> y >> d >> t;
	double mndist = sqrt(x * x + y * y);

	if (d < t) {
		// 1. 걷는 게 빠를 때
		cout << mndist << "\n";
	}
	else {
		// 2. 점프
		res = mndist;

		int tmp = mndist / d;
		mndist -= tmp * d;

		if (tmp == 0) res = min(res, min(t + d - mndist, 2 * t));
		else res = min(res, min(tmp * t + mndist, (tmp + 1) * t));

		cout << res << "\n";
	}

	return 0;
}