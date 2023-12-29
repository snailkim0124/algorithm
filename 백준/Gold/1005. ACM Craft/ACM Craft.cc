#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int n, k, w;
int deg[1005];
vector<int> adj[1005];
int building[1005];
int res[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(deg, 0, sizeof(deg));
		memset(building, 0, sizeof(building));
		memset(res, 0, sizeof(res));
		for (int i = 0; i < 1005; i++) {
			adj[i].clear();
		}

		cin >> n >> k;

		for (int i = 1; i <= n; i++) {
			cin >> building[i];
			res[i] += building[i];
		}

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			deg[y]++;
		}

		cin >> w;

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (deg[i] == 0) q.push(i);
		}

		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (auto next : adj[now]) {
				deg[next]--;
				res[next] = max(res[next], res[now] + building[next]); // 더 큰 결과값 갱신
				if (deg[next] == 0) {
					q.push(next);
				}
			}
		}

		cout << res[w] << "\n";
	}
	

	return 0;
}