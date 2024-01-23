#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n;
vector<pll> v;
ll mn = 987654321;
ll idx;

ll dist(pll a, pll b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cout << fixed;
	cout.precision(6); // 10^-6

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 0; i < n; i++) {
		ll mx = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			ll DIST = dist(v[i], v[j]);
			mx = max(mx, DIST);
		}
		// 최대 중 최소
		if (mn > mx) {
			mn = mx;
			idx = i;
		}
	}

	cout << v[idx].first << " " << v[idx].second;

	return 0;
}