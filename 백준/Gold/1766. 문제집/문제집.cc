#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int n, m;
int deg[32005];
vector<int> adj[32005];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}

	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int now = q.top();
		q.pop();
		cout << now << " ";
		for (auto next : adj[now]) {
			deg[next]--;
			if (deg[next] == 0) {
				q.push(next);
			}
		}
	}

	return 0;
}