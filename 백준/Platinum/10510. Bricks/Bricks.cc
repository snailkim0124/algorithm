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
	ll n;
	cin >> n;
	vector<pair<ll, char>> v;
	ll bsum = 0, wsum = 0;

	char prev = '0';
	for (int i = 0; i < n; i++) {
		ll num;
		char c;
		cin >> num >> c;
		if (c == prev) {
			int tmp = v.back().first;
			v.pop_back();
			v.push_back({ num + tmp, c });
		}
		else {
			v.push_back({ num, c });
		}

		prev = c;

		if (c == 'B') {
			bsum += num;
		}
		else if (c == 'W') {
			wsum += num;
		}
	}

	// 한 색깔만 있을 때
	if (v.size() == 1) {
		cout << v[0].first << "\n";
		return;
	}

	// 비 구하기
	ll g = gcd(bsum, wsum);
	bsum /= g;
	wsum /= g;

	ll cnt = 0;
	ll bnow = 0, wnow = 0;
	for (int i = 0; i < v.size(); i++) {
		auto [num, c] = v[i];

		if (c == 'B') {
			if ((wnow * bsum) % wsum == 0) {
				// 구간 안에 있으면 더해가기
				ll tmpb = (wnow * bsum) / wsum;
				if (bnow < tmpb && tmpb <= bnow + num) {
					cnt++;
				}
			}
			bnow += num;
		}
		else if (c == 'W') {
			if ((bnow * wsum) % bsum == 0) {
				ll tmpw = (bnow * wsum) / bsum;
				if (wnow < tmpw && tmpw <= wnow + num) {
					cnt++;
				}
			}
			wnow += num;
		}
	}

	cout << cnt << "\n";
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