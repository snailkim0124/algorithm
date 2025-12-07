#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		int g, c, e;
		cin >> g >> c >> e;
		if (e <= c) {
			cout << 0 << "\n";
		}
		else {
			cout << (e - c) * (2 * g - 1) << "\n";
		}
	}

	return 0;
}