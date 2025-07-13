#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


ll l, w, h;
ll n;
vector<pll> v;
ll res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> l >> w >> h;

	cin >> n;
	while (n--) {
		ll a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	//for (auto it : v) {
	//	cout << "it : " << it.first << " " << it.second << "\n";
	//}

	ll tmp = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		ll tmpL = pow(2, v[i].first);
		ll cnt = (l / tmpL) * (w / tmpL) * (h / tmpL);

		if (i != v.size() - 1) {
			ll k = pow(2, v[i + 1].first - v[i].first);
			tmp *= pow(k, 3);
		}
		cnt -= tmp;

		tmp += min(cnt, v[i].second);
		res += min(cnt, v[i].second);

		// cout << "tmp : " << tmp << "\n";
	}


	if(tmp == l * w * h) cout << res;
	else cout << -1;

	return 0;
}