#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int deg[1005], dp[1005];
vector<int> adj[1005];

void solve() {
	int k, m, p;
	cin >> k >> m >> p;
	for (int i = 0; i < p; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}
	
	queue<int> q;
	for (int i = 1; i <= m; i++) {
		if (deg[i] == 0) {
			q.push(i);
			dp[i] = 1;
		}
	}

	vector<int> order[1005];

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto next : adj[now]) {
			order[next].push_back(dp[now]);

			deg[next]--;
			if (deg[next] == 0) {
				q.push(next);

				int mx = 0;
				int cnt = 0;
				for (auto nr : order[next]) {
					mx = max(mx, nr);
				}
				for (auto nr : order[next]) {
					if (mx == nr) cnt++;
				}

				if (cnt == 1) dp[next] = dp[now];
				else if (cnt >= 2) dp[next] = mx + 1;
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= m; i++) {
		// cout << dp[i] << " ";
		res = max(dp[i], res);
	}
	// cout << "\n";

	cout << k << " " << res << "\n";

	memset(deg, 0, sizeof(deg));
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= m; i++) {
		adj[i].clear();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}


	return 0;
}