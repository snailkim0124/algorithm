#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
vector<int> adj[100005];
int dp[100005];

void dfs(int now) {
	for (auto next : adj[now]) {
		dp[next] += dp[now];
		dfs(next);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;

		if (i == 1) continue;
		adj[num].push_back(i);
	}

	while (m--) {
		int i, w;
		cin >> i >> w;
		dp[i] += w;
	}

	dfs(1);

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}

	return 0;
}