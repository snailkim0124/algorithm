#include <bits/stdc++.h>
#define PI 3.141592
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n;
vector<pll> v;
ll cnt;

ll dist(pll a, pll b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				ll ij = dist(v[i], v[j]);
				ll jk = dist(v[j], v[k]);
				ll ki = dist(v[k], v[i]);

				ll mx = max(max(ij, jk), ki);
				ll mn = min(min(ij, jk), ki);
				if (mx == mn + (ij + jk + ki) - mn - mx) cnt++;
			}
		}
	}

	cout << cnt;
	
	return 0;
}