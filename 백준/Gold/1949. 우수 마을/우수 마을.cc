#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int visited[10005];
int dp[10005][2]; // 선정되면 1, 선정 안되면 0
vector<int> adj[10005];

void dfs(int now) {
	if (visited[now]) return;
	visited[now] = 1;

	for (auto next : adj[now]) {
		if (!visited[next]) {
			dfs(next);
			dp[now][0] += max(dp[next][0], dp[next][1]);
			dp[now][1] += dp[next][0];
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		// 우수 마을 선정한 경우
		cin >> dp[i][1];
	}

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);

	cout << max(dp[1][0], dp[1][1]);

	return 0;
}