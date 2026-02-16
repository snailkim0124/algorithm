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
vector<ll> p;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> n;
		if (!n) break;

		p.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}

		ll x, y;
		cin >> x >> y;

		vector<ll> ans;
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		pq.push(1);
		ll prev = -1;

		while (!pq.empty()) {
			auto now = pq.top();
			pq.pop();

			if (now == prev) continue;
			prev = now;

			if (now > y) break;

			if (x <= now && now <= y) {
				ans.push_back(now);
			}

			for (int i = 0; i < n; i++) {
				if (now <= y / p[i]) {
					pq.push(now * p[i]);
				}
				
			}
		}

		if (ans.empty()) {
			cout << "none\n";
		}
		else {
			for (int i = 0; i < ans.size(); i++) {
				if (i == 0) {
					cout << ans[i];
					continue;
				}
				cout << "," << ans[i];

			}
			cout << "\n";
		}
		p.clear();
	}

	return 0;
}