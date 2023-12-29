#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int deg[10005];
vector<pair<int,int>> adj[10005], r_adj[10005]; // 역방향
int res[10005];
int cnt;
int visited[10005];
int s, e;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		r_adj[b].push_back({ a, c });
		deg[b]++;
	}
	cin >> s >> e;

	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto next : adj[now]) {
			deg[next.first]--;
			res[next.first] = max(res[next.first], res[now] + next.second);
			if (deg[next.first] == 0) {
				q.push(next.first);
			}
		}
	}

	queue<int> rq; // 역방향으로
	rq.push(e);
	while (!rq.empty()) {
		int now = rq.front();
		rq.pop();
		for (auto next : r_adj[now]) {
			if (res[next.first] + next.second == res[now]) {
				cnt++;
				if (!visited[next.first]) { // 재방문 방지
					visited[next.first] = 1;
					rq.push(next.first);
				}
			}
		}
	}

	cout << res[e] << "\n" << cnt;
	return 0;
}