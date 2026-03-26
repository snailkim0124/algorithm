#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll w, h;
ll n;
vector<pll> v;
vector<ll> x, y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> w >> h;
	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		x.push_back(v[i].first);
		y.push_back(v[i].second);
	}

	sort(all(x));
	sort(all(y));

	ll vx[2] = { x[(x.size() - 1) / 2], x[x.size() / 2]};
	ll vy[2] = { y[(y.size() - 1) / 2], y[y.size() / 2] };


	ll ay = -1, ax = -1;
	ll res = LLONG_MAX;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			ll sum = 0;
			ll mx = -1;
			ll px = vx[i];
			ll py = vy[j];

			for (int k = 0; k < n; k++) {
				mx = max(mx, abs(px - v[k].first) + abs(py - v[k].second));
				sum += 2 * (abs(px - v[k].first) + abs(py - v[k].second));
			}

			sum -= mx;

			if (res > sum) {
				res = sum;
				ay = py;
				ax = px;
			}
			else if (res == sum) {
				if (px < ax) {
					ax = px;
					ay = py;
				}
				else if (px == ax && py < ay) {
					ay = py;
				}
			}
		}
	}


	cout << res << "\n";
	cout << ax << " " << ay << "\n";



	return 0;
}