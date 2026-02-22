#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int a, b, c;

void solve() {
	double ans;

	if (a == -1) {
		ans = (c * c - b * b);
		if (ans <= 0) {
			cout << "Impossible.\n";
		}
		else {
			cout << "a = " << sqrt(ans) << "\n";
		}
	}
	else if (b == -1) {
		ans = (c * c - a * a);
		if (ans <= 0) {
			cout << "Impossible.\n";
		}
		else {
			cout << "b = " << sqrt(ans) << "\n";
		}
	}
	else if (c == -1) {
		ans = (a * a + b * b);
		if (ans <= 0) {
			cout << "Impossible.\n";
		}
		else {
			cout << "c = " << sqrt(ans) << "\n";
		}
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cout << fixed;
	cout.precision(3);

	for (int T = 1; ; T++) {
		cin >> a >> b >> c;
		if (!a && !b && !c) break;

		cout << "Triangle #" << T << "\n";
		solve();
	}

	return 0;
}