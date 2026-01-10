#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, k, m;
vector<int> adj[200005];
int visited[200005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k >> m;
	for (int i = 1; i <= m; i++) {
		int u = n + i;
		for (int j = 0; j < k; j++) {
			int v;
			cin >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	queue<int> q;
	visited[1] = 1;
	q.push(1);

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		if (now == n) {
			cout << visited[now] << "\n";
			exit(0);
		}

		for (auto next : adj[now]) {
			if (!visited[next]) {
				if (next <= n) {
					visited[next] = visited[now] + 1;
				}
				else if (next > n) {
					// 하이퍼튜브
					visited[next] = visited[now];
				}

				q.push(next);
			}
		}

	}

	cout << -1 << "\n";

	
	return 0;
}