#include <bits/stdc++.h>
#include <limits.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int t;
int n, m;
vector<int> adj[1005];
int visited[1005], matched[1005];

bool dfs(int now) {
	for (auto next : adj[now]) {
		if (visited[next]) continue;
		visited[next] = 1;

		if (matched[next] == -1 || dfs(matched[next])) {
			matched[next] = now;
			return true;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		while (m--) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}

		int cnt = 0;
		memset(matched, -1, sizeof(matched));
		for (int i = 0; i < n; i++) {
			memset(visited, 0, sizeof(visited));
			if (dfs(i)) cnt++;
		}

		cout << cnt << "\n";

		for (int i = 0; i < n; i++) {
			adj[i].clear();
		}
	}
	
	

	return 0;
}