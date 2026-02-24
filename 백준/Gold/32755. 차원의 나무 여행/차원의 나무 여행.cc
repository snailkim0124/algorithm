#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int arr[505][505];
vector<int> adj[505];
int visited[505];
int cnt = 0;

void dfs(int now) {
	visited[now] = 1;
	cnt++;

	for (auto next : adj[now]) {
		if (!visited[next]) {
			dfs(next);
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
		arr[u][v] = 1;
		arr[v][u] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (!arr[i][j] && !arr[j][i]) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		cnt = 0;

		dfs(i);
		mx = max(mx, cnt);
	}

	cout << mx << "\n";
	
	return 0;
}