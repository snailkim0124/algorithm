#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int dp[10005][2]; // 속하면 1, 아니면 0
int visited[10005];
vector<int> adj[10005];
vector<int> trace;
int mx;

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

void tracing(int now, int prev) {
	if (dp[now][1] > dp[now][0] && !visited[prev]) {
		trace.push_back(now);
		visited[now] = 1;
	}

	for (auto next : adj[now]) {
		if (next != prev) {
			tracing(next, now);
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dp[i][1];
	}

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);
	
	memset(visited, 0, sizeof(visited));
	tracing(1, 0);

	sort(trace.begin(), trace.end());
	cout << max(dp[1][0], dp[1][1]) << "\n";
	for (auto it : trace) {
		cout << it << " ";
	}

	return 0;
}