#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n;
vector<pll> v;
ll res;
ll drive;

bool cmp(pll& x, pll& y) {
	ll dx = x.second - x.first;
	ll dy = y.second - y.first;

	if ((dx >= 0) != (dy >= 0)) return dx >= 0;
	else if (dx >= 0) return x.first < y.first;
	else return x.second > y.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end(), cmp);
	//for (auto it : v) {
	//	cout << it.first << " : " << it.second << "\n";
	//}

	for (int i = 0; i < n; i++) {
		if (v[i].first > drive) {
			res += v[i].first - drive;
			drive = 0;
		}
		else drive -= v[i].first;

		drive += v[i].second;
	}

	cout << res;

	return 0;
}