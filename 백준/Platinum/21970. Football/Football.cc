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
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ll sum = 0;
	ll mx = 0;

	for (int i = 0; i < n; i++) {
		sum += a[i];
		mx = max(mx, a[i]);
	}

	// cout << "sum : " << sum << "\n";
	// 총합이 최대값의 반보다 커야됨?
	if (mx > sum - mx || (sum % 2 == 0)) {
		// cout << "ans : " << 1 << "\n";
		cout << 0;
	}
	else {
		// cout << "ans : " << 0 << "\n";
		cout << 1;
	}
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