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
	int n;
	string s;
	cin >> n >> s;

	if (n == 1) {
		cout << 4 << " " << 2 << "\n";
		return;
	}

	ll sum = 0;
	for (auto it : s) {
		sum += it - '0';
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		ll tmp = sum - (s[i] - '0');
		for (int j = (i == 0 ? 1 : 0); j < 10; j++) {
			if ((tmp + j) % 3 == 0) {
				string ans = s;
				ans[i] = (char)(j + '0');
				cout << ans << " " << 3 << "\n";
				cnt++;

				if (cnt == n) return;
			}
		}
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