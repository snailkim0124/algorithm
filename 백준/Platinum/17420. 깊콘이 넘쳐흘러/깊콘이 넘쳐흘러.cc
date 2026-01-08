#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n;
vector<pll> v; // 계획, 남은 기한

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].second;
	}

	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
	}

	sort(all(v));

	//for (auto [a, b] : v) {
	//	cout << a << " : " << b << "\n";
	//}
	
	ll res = 0;
	ll prev = -1; // 이전 최대
	ll mx = -1; // 지금 최대

	for (int i = 0; i < n; i++) {
		if (i > 0 && v[i].first > v[i - 1].first) {
			prev = mx;
		}

		ll tmp = max(v[i].first, prev);

		if (v[i].second < tmp) {
			double diff = tmp - v[i].second;
			ll cnt = ceil(diff / 30.0); // 횟수

			v[i].second += cnt * 30;
			res += cnt;
		}

		mx = max(mx, v[i].second); // 지금 최대 갱신
	}

	cout << res << "\n";
	
	
	return 0;
}