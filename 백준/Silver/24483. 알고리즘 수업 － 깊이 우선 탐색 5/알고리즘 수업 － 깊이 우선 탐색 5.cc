#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, m, r;
vector<ll> adj[100005];
ll visited[100005];
ll sum = 0;
ll cnt = 1;

void dfs(int now, int depth) {
	visited[now] = 1;
	sum += depth * cnt++;

	for (auto next : adj[now]) {
		if (!visited[next]) {
			dfs(next, depth + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> r;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(all(adj[i]));
	}
	
	dfs(r, 0);

	cout << sum << "\n";
	
	return 0;
}