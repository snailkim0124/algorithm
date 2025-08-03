#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
vector<pii> adj[105];
int dist[105][105];
int deg[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, k;
		cin >> x >> y >> k;
		adj[y].push_back({ x, k });
		deg[x]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q.push(i);
			dist[i][i] = 1;
		}
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto next : adj[now]) {
			deg[next.first]--;
			
			for (int i = 1; i <= n; i++) {
				dist[next.first][i] += dist[now][i] * next.second;
			}

			if (deg[next.first] == 0) q.push(next.first);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[n][i] == 0) continue;
		cout << i << " " << dist[n][i] << "\n";
	}

	return 0;
}