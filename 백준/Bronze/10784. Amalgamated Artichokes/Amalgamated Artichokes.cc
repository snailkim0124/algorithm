#include <bits/stdc++.h>
#include <limits.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

double p, a, b, c, d, n;
double mx = 0, ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cout << fixed;
	cout.precision(6);
	cin >> p >> a >> b >> c >> d >> n;

	for (int k = 1; k <= n; k++) {
		if (k == 1) {
			mx = max(mx, p * (sin(a * k + b) + cos(c * k + d) + 2));
		}
		else {
			ans = max(ans, mx - p * (sin(a * k + b) + cos(c * k + d) + 2));
			mx = max(mx, p * (sin(a * k + b) + cos(c * k + d) + 2));
		}
	}

	cout << ans << "\n";

	return 0;
}