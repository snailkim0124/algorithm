#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int n, m;
int deg[505];
vector<int> adj[505];
int building[505];
int res[505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> building[i]; // 건물짓는 시간
		while (1) {
			int tmp;
			cin >> tmp;
			if (tmp == -1) break;
			adj[tmp].push_back(i);
			deg[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto next : adj[now]) {
			deg[next]--;
			res[next] = max(res[next], res[now] + building[now]); // 더 큰 결과값 갱신
			if (deg[next] == 0) {
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << res[i] + building[i] << "\n"; // 완성 시간
	}

	return 0;
}