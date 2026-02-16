#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
vector<pll> v;

ll dist(ll mid) {
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += abs(v[i].first - mid) * v[i].second;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	v.resize(n);
	ll mn = INT_MAX;
	ll mx = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		mx = max(mx, v[i].first);
		mn = min(mn, v[i].first);
	}

	ll left = mn;
	ll right = mx;
	ll tmp_mn = INT_MAX;
	ll res = INT_MAX;

	while (left <= right) {
		ll mid = (left + right) / 2;
		if (dist(mid) > dist(mid + 1)) {
			left = mid + 1;
		}
		else {
			res = mid;
			right = mid - 1;
		}
	}

	cout << res << "\n";

	
	
	return 0;
}