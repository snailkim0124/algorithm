#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m, v;
vector<int> adj[1005];
int visited[1005];
vector<int> dpath, bpath;

void dfs(int now) {
	visited[now] = 1;
	dpath.push_back(now);

	for (auto next : adj[now]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}

void bfs(int now) {
	queue<int> q;
	visited[now] = 1;
	q.push(now);

	bpath.push_back(now);

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		for (auto next : adj[now]) {
			if (!visited[next]) {
				visited[next] = 1;
				bpath.push_back(next);

				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(all(adj[i]));
	}

	dfs(v);
	
	memset(visited, 0, sizeof(visited));

	bfs(v);

	for (auto it : dpath) {
		cout << it << " ";
	}
	cout << "\n";

	for (auto it : bpath) {
		cout << it << " ";
	}
	cout << "\n";


	return 0;
}