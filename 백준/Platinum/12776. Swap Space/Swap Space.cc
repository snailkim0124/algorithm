#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n;
vector<pll> v, neg, pos;
ll res;
ll drive;

bool cmpp(pll& x, pll& y) {
	return x.first < y.first;
}

bool cmpn(pll& x, pll& y) {
	return x.second > y.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		if (a < b) pos.push_back({ a, b });
		else neg.push_back({ a, b });
	}

	sort(pos.begin(), pos.end(), cmpp);
	sort(neg.begin(), neg.end(), cmpn);

	for (auto it : pos) v.push_back(it);
	for (auto it : neg) v.push_back(it);

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