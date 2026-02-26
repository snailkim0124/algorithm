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
vector<pii> adj[500005];
vector<ll> dp;
ll cnt;

void dfs(int now, int prev, int val) {
	dp.push_back(val);
	for (auto [next, w] : adj[now]) {
		if (next != prev) {
			dfs(next, now, val ^ w);
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	dfs(1, 0, 0);
	
	sort(all(dp));
	
	ll tmp = 1;
	for (int i = 1; i < dp.size(); i++) {
		if (dp[i] == dp[i - 1]) tmp++;
		else {
			cnt += tmp * (tmp - 1) / 2;
			tmp = 1;
		}
	}

	cnt += tmp * (tmp - 1) / 2;

	cout << cnt << "\n";
	
	return 0;
}