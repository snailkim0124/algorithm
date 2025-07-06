#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, r, q;
vector<int> adj[100005];
int visited[100005];
int dp[100005];

int dfs(int now) {
	if (visited[now]) return dp[now];
	visited[now] = 1;

	for (auto next : adj[now]) {
		if (!visited[next]) {
			dp[now] += dfs(next);
		}
	}
	return dp[now];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> r >> q;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
	}

	dfs(r);

	while (q--) {
		int u;
		cin >> u;
		cout << dp[u] << "\n";
	}

	return 0;
}