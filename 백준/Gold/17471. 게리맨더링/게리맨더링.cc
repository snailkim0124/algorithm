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

pii dfs(int now, bool flag) {
	visited[now] = 1;
	pii res = { 1, human[now] }; // 사이즈, 인구 수 총합
	for (int next : adj[now]) {
		if (!visited[next] && cvisited[next] == flag) {
			pii tmp = dfs(next, flag);
			res.first += tmp.first;
			res.second += tmp.second;
		}
	}

	return res;
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

	for (int i = 1; i < (1 << n) - 1; i++) {
		memset(cvisited, 0, sizeof(cvisited));
		memset(visited, 0, sizeof(visited));

		int aidx = -1, bidx = -1;

		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				cvisited[j + 1] = 1;
				aidx = j + 1;
			}
			else bidx = j + 1;
		}

		pii a = dfs(aidx, 1);
		pii b = dfs(bidx, 0);

		if (a.first + b.first == n) mn = min(mn, abs(a.second - b.second));
	}

	if (mn == 987654321) cout << -1;
	else cout << mn;

	return 0;
}