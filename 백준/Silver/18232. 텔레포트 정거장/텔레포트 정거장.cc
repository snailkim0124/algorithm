#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const int INF = 987654321;
int n, m;
int s, e;
vector<int> adj[300005];
int visited[300005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	cin >> s >> e;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	queue<int> q;
	q.push(s);
	visited[s] = 1;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		if (now == e) {
			cout << visited[e] - 1 << "\n";
			break;
		}

		for (auto next : adj[now]) {
			if (!visited[next]) {
				visited[next] = visited[now] + 1;
				q.push(next);
			}
		}

		if (now - 1 >= 1 && !visited[now - 1]) {
			visited[now - 1] = visited[now] + 1;
			q.push(now - 1);
		}

		if (now + 1 <= n && !visited[now + 1]) {
			visited[now + 1] = visited[now] + 1;
			q.push(now + 1);
		}
	}

	return 0;
}