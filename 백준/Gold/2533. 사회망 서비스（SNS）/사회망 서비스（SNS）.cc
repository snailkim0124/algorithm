#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, r, q;
vector<int> adj[1000005];
int visited[1000005];
int dp[1000005][2]; // 1이면 얼리

void dfs(int now) {
	visited[now] = 1;
	dp[now][1] = 1;

	for (auto next : adj[now]) {
		if (!visited[next]) {
			dfs(next);
			dp[now][0] += dp[next][1]; // 자식이 얼리
			dp[now][1] += min(dp[next][0], dp[next][1]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);

	cout << min(dp[1][0], dp[1][1]);

	return 0;
}