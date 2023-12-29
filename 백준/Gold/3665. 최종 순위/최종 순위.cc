#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int n, m;
int deg[505];
vector<int> adj;
int edges[505][505]; // 간선
vector<int> res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		adj.clear();
		res.clear();
		memset(deg, 0, sizeof(deg));
		memset(edges, 0, sizeof(edges));
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			for (auto b : adj) {
				edges[a][b] = 1;
				deg[b]++;
			}
			adj.push_back(a);
		}
		cin >> m;

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			if (edges[a][b]) {
				edges[a][b] = 0;
				edges[b][a] = 1;
				deg[b]--;
				deg[a]++;
			}
			else if (edges[b][a]) {
				edges[b][a] = 0;
				edges[a][b] = 1;
				deg[a]--;
				deg[b]++;
			}
		}

		bool check = false;
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (deg[i] == 0) q.push(i);
		}

		while (!q.empty()) {
			int now = q.front();
			q.pop();
			res.push_back(now);

			for (int i = 1; i <= n; i++) {
				if (!edges[now][i]) continue;
				deg[i]--;
				if (!deg[i]) {
					q.push(i);
				}
			}
		}

		if (res.size() != n) { // 순위 x
			cout << "IMPOSSIBLE\n";
		}
		else {
			reverse(res.begin(), res.end());

			for (auto it : res) {
				cout << it << " ";
			}
			cout << "\n";
		}

	}

	return 0;
}