#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, g, k;
vector<pll> v, ov; // 중요, 안 중요
ll mxs;
ll ans;

bool check(ll x) {
	ll sum = 0;
	// 중요한거
	for (int i = 0; i < v.size(); i++) {
		sum += v[i].first * max(1LL, x - v[i].second);
	}

	// 빼도 되는 거
	vector<ll> ovv;
	for (int i = 0; i < ov.size(); i++) {
		ovv.push_back(ov[i].first * max(1LL, x - ov[i].second));
	}
	sort(ovv.begin(), ovv.end(), greater<>());

	for (int i = 0; i < min(k, (ll)ovv.size()); i++) {
		sum -= ovv[i];
	}

	return sum <= g;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> g >> k;
	for (int i = 0; i < n; i++) {
		ll s, l, o;
		cin >> s >> l >> o;
		v.push_back({ s, l });
		if (o == 1) ov.push_back({ s, l });
		mxs = max(mxs, s);
	}

	ll left = 0;
	ll right = 2000000001;

	while (left <= right) {
		ll mid = (left + right) / 2;
		if (check(mid)) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << ans;

	return 0;
}