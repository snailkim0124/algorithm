#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
vector<int> adj[505];
int visited[505];
int cnt;

void dfs(int v, int depth) {
	visited[v] = 1;

	if (depth == 2) return;

	for (auto nxt : adj[v]) {
		dfs(nxt, depth + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
		adj[a].push_back(b);
	}

	dfs(1, 0);

	for (int i = 2; i <= n; i++) {
		if (visited[i]) cnt++;
	}

	cout << cnt;
	
	return 0;
}