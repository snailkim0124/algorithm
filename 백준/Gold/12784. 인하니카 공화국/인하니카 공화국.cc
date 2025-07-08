#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;
const int INF = 987654321;
vector<pii> adj[1005];
int dp[1005];

void INIT() {
	fill(dp, dp + 1005, INF);
	for (int i = 0; i < 1005; i++) {
		adj[i].clear();
	}
}

int dfs(int now, int prev) {
	if (dp[now] != INF) return dp[now];

	int sum = 0;
	for (auto next : adj[now]) {
		if (next.first != prev) {
			int nextsum = dfs(next.first, now);
			nextsum = min(nextsum, next.second);
			sum += nextsum;
		}
	}

	if (sum != 0) dp[now] = min(dp[now], sum);

	return dp[now];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		INIT();

		int n, m;
		cin >> n >> m;
		while (m--) {
			int u, v, d;
			cin >> u >> v >> d;
			adj[u].push_back({ v, d });
			adj[v].push_back({ u, d });
		}

		if (n == 1) cout << 0 << "\n"; // 1밖에 없는 루트노드
		else cout << dfs(1, 0) << "\n";
	}
	
	return 0;
}