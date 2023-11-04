#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll cnt;
ll mn = 987654321;
ll sum;

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	return (a.first - a.second) > (b.first - b.second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vector<pair<ll, ll>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), cmp);

	/*for (int i = 0; i < n; i++) {
		cout << v[i].first << " : " << v[i].second << "\n";
	}*/

	ll height = 0;
	for (int i = 0; i < n; i++) {
		mn = min(mn, height);
		height += v[i].first;
		sum += height;
		height -= v[i].second;
		mn = min(mn, height);
	}

	//cout << "sum : " << sum << " : " << "mn : " << mn << "\n";
	cout << sum - mn * n;

	return 0;
}