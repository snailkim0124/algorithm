#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int k, c, p;

void solve() {
	cin >> k >> c >> p;
	if (k + c + p == 1) {
		cout << "N\n";
		return;
	}

	if (k == c) {
		cout << "Y\n";
		return;
	}
	
	if (c + p < 2) {
		if (k) {
			cout << "N\n";
			return;
		}
	}

	cout << "Y\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	//for (k = 0; k <= 3; k++) {
	//	for (c = 0; c <= 5; c++) {
	//		for (p = 0; p <= 5; p++) {
	//			cout << k << " : " << c << " : " << p << " : ";
	//			solve();
	//		}
	//	}
	//}


	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}

	return 0;
}