#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, l, s, e;
vector<int> adj[200005];
int visited[200005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l;
	for (int i = 1; i <= l; i++) {
		while (1) {
			int num;
			cin >> num;
			if (num == -1) break;
			adj[num].push_back(n + i);
			adj[n + i].push_back(num);
		}
	}
	cin >> s >> e;

	//for (int i = 1; i <= n + l; i++) {
	//	cout << i << " : ";
	//	for (auto it : adj[i]) {
	//		cout << it << " ";
	//	}
	//	cout << "\n";
	//}

	memset(visited, -1, sizeof(visited));

	queue<int> q;
	q.push(s);
	visited[s] = 0;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		if (now == e) {
			if (visited[now] - 1 <= 0) cout << 0 << "\n";
			else cout << visited[now] - 1 << "\n";
			exit(0);
		}

		for (auto next : adj[now]) {
			if (visited[next] != -1) continue;
			// 역 -> 노선
			if (now <= n && next > n) {
				visited[next] = visited[now] + 1;
				q.push(next);
			}
			// 노선 -> 역 (환승)
			else if (now > n && next <= n) {
				visited[next] = visited[now];
				q.push(next);
			}
		}
	}

	cout << -1 << "\n";


	return 0;
}