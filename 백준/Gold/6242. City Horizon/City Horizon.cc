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
vector<tll> v;
vector<ll> x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		ll a, b, h;
		cin >> a >> b >> h;
		v.push_back({ a, b, h });
		x.push_back(a);
		x.push_back(b);
	}

	sort(all(x));
	x.erase(unique(all(x)), x.end());
	sort(all(v));

	ll ans = 0;
	ll idx = 0;
	priority_queue<pll> pq;

	for (int i = 0; i < x.size() - 1; i++) {
		ll dx = x[i + 1] - x[i];
		if (dx == 0) continue;

		while (idx < n && get<0>(v[idx]) == x[i]) {
			pq.push({ get<2>(v[idx]), get<1>(v[idx]) });
			idx++;
		}

		while (!pq.empty() && pq.top().second <= x[i]) {
			pq.pop();
		}

		ll mx = 0;
		if (!pq.empty()) mx = pq.top().first;

		ans += dx * mx;
	}

	cout << ans << "\n";

	


	return 0;
}