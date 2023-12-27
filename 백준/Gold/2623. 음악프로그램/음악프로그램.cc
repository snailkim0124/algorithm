#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int n, m;
int deg[1005];
vector<int> adj[1005];
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		vector<int> v;
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int a;
			cin >> a;
			v.push_back(a);
		}

		for (int j = 0; j < num; j++) {
			for (int k = j + 1; k < num; k++) {
				adj[v[j]].push_back(v[k]);
				deg[v[k]]++;
			}
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		ans.push_back(now);
		for (auto next : adj[now]) {
			deg[next]--;
			if (deg[next] == 0) {
				q.push(next);
			}
		}
	}

	if (ans.size() == n) {
		for (auto it : ans) {
			cout << it << "\n";
		}
	}
	else cout << 0;

	return 0;
}