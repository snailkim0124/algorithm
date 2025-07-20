#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int human[15];
vector<int> adj[15];
int visited[15], cvisited[15];
int mn = 987654321;

bool connected(vector<int> &v, bool flag) {
	int cnt = 1;
	memset(cvisited, 0, sizeof(cvisited));
	queue<int> q;
	cvisited[v[0]] = 1;
	q.push(v[0]);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto next : adj[now]) {
			if (!cvisited[next] && visited[next] == flag) {
				cnt++;
				cvisited[next] = 1;
				q.push(next);
			}
		}
	}

	return v.size() == cnt;
}

bool check() {
	vector<int> a, b;

	for (int i = 1; i <= n; i++) {
		if (visited[i]) a.push_back(i);
		else b.push_back(i);
	}

	if (a.empty() || b.empty()) return false;
	if (!connected(a, true)) return false;
	if (!connected(b, false)) return false;

	return true;

}

void dfs(int now, int cnt) {
	if (cnt >= 1) {
		if (check()) {
			int asum = 0;
			int bsum = 0;

			for (int i = 1; i <= n; i++) {
				if (visited[i]) asum += human[i];
				else bsum += human[i];
			}

			mn = min(mn, abs(asum - bsum));
		}
	}

	for (int i = now; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			dfs(i + 1, cnt + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> human[i];
	}

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		while (num--) {
			int k;
			cin >> k;
			adj[i].push_back(k);
		}
	}

	dfs(1, 0);

	if (mn == 987654321) cout << -1;
	else cout << mn;

	return 0;
}