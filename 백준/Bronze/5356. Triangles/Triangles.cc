#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

void solve() {
	int n; char c;
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << c;
		}
		cout << "\n";

		c = (char)((c - 'A' + 1) % 26 + 'A');
	}

	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	
	return 0;
}