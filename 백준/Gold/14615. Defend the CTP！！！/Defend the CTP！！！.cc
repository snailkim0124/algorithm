#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, m;
vector<int> adj[100005], rev_adj[100005];
int visited[100005], visited2[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		rev_adj[y].push_back(x);
	}

	queue<int> q;
	q.push(1);
	visited[1] = 1;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		for (auto next : adj[now]) {
			if (!visited[next]) {
				visited[next] = 1;
				q.push(next);
			}
		}
	}

	q = queue<int>();
	q.push(n);
	visited2[n] = 1;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		for (auto next : rev_adj[now]) {
			if (!visited2[next]) {
				visited2[next] = 1;
				q.push(next);
			}
		}
	}


	//for (int i = 1; i <= n; i++) {
	//	cout << i << " : " << visited[i] << "\n";
	//}

	int t;
	cin >> t;
	while (t--) {
		int c;
		cin >> c;
		if (visited[c] && visited2[c]) cout << "Defend the CTP\n";
		else cout << "Destroyed the CTP\n";
	}

	return 0;
}